#ifndef MySqlSource_h__
#define MySqlSource_h__

#include <functional>
#include <boost/noncopyable.hpp>
#include <QtCore/QMap>
#include <QtCore/QDateTime>
#include "ProjectBase/Connection.h"
#include "ProjectBase/SmartPtr.h"
#include "ProjectBase/NotSupportedException.h"
#include "ProjectBase/NotImplementedException.h"
#include "ProjectBase/DataConsistencyException.h"
#include "EMessageId.h"
#include "ECustomTypeId.h"
#include "JpsFile.h"
#include "GreisMysqlSerializer.h"
#include "CustomType.h"

using namespace ProjectBase;

namespace Greis
{
    class MySqlSource : private boost::noncopyable
    {
    public:
        SMART_PTR_T(MySqlSource);

        MySqlSource(Connection* connection);
        ~MySqlSource();

        JpsFile::UniquePtr_t ReadRange(const QDateTime& from, const QDateTime& to);
    private:
        template<typename Func>
        void handleMessage(QString queryStr, Func handleMessageFields, QMap<qulonglong, Epoch*>& epochsByDateTime);

        // Extract a custom type from the buffer
        template<typename T>
        typename T::UniquePtr_t extractCustomType(ECustomTypeId::Type ctId, int dbId);

        void constructCtQueriesAndHandlers();

        template<typename T>
        std::vector<typename T::UniquePtr_t> deserializeAndGetCustomTypes(ECustomTypeId::Type ctId, const QVariant& encodedIds);

        void fillStandardJpsHeader(JpsFile* jpsFile);
    private:
        Connection* _connection;
        DatabaseHelper* _dbHelper;

        QDateTime _from;
        QDateTime _to;

        GreisMysqlSerializer _serializer;

        QMap<ECustomTypeId::Type, QMap<int, CustomType*>> _ctBuffer;
        QMap<ECustomTypeId::Type, QString> _ctQueries;
        QMap<ECustomTypeId::Type, std::function<void (int,const QSqlQuery&,CustomType*&)>> _ctHandlers;

        QMap<int, std::string> _codes;
    };

    template<typename Func>
    void MySqlSource::handleMessage( QString queryStr, Func handleMessageFields, 
        QMap<qulonglong, Epoch*>& epochsByDateTime )
    {
        int msgCount = 0;
        QSqlQuery query = _dbHelper->ExecuteQuery(queryStr);
        while (query.next())
        {
            int id = query.value(0).toInt();
            //int idEpoch = query.value(1).toInt();
            qulonglong unixTime = query.value(2).toULongLong();
            int messageCodeId = query.value(3).toInt();
            std::string messageCode = _codes[messageCodeId];
            int bodySize = query.value(4).toInt();

            Message::UniquePtr_t msg;

            // message-specific fields handling
            handleMessageFields(messageCode, bodySize, query, msg);

            if (!msg->Validate())
            {
                throw DataConsistencyException(QString("Invalid message `%1` with Id `%2`.").
                    arg(QString::fromAscii(messageCode.c_str(), 2)).arg(id));
            }
            assert(msg->Size() == bodySize + StdMessage::HeadSize());

            auto epoch = epochsByDateTime.value(unixTime, nullptr);
            if (epoch == nullptr)
            {
                epoch = new Epoch();
                epoch->DateTime = QDateTime::fromMSecsSinceEpoch(unixTime);
                epochsByDateTime[unixTime] = epoch;
            }
            epoch->Messages.push_back(std::move(msg));
            epoch->Messages.push_back(NonStdTextMessage::CreateCarriageReturnMessage());
            epoch->Messages.push_back(NonStdTextMessage::CreateNewLineMessage());
            ++msgCount;
        }
        sLogger.Info(QString("%1 messages readed into memory...").arg(msgCount));
    }

    template<typename T>
    typename T::UniquePtr_t MySqlSource::extractCustomType( ECustomTypeId::Type ctId, int dbId )
    {
        static_assert(std::is_base_of<CustomType, T>::value, "T must be a CustomType descendant.");

        auto& buffer = _ctBuffer[ctId];
        auto val = buffer.take(dbId);
        if (val != nullptr)
        {
            return T::UniquePtr_t(dynamic_cast<T*>(val));
        }

        QString queryStr = _ctQueries.value(ctId);

        assert (queryStr != QString());

        queryStr = queryStr.arg(_from.toMSecsSinceEpoch()).arg(_to.toMSecsSinceEpoch());

        int ctCount = 0;
        T::UniquePtr_t retVal;
        QSqlQuery query = _dbHelper->ExecuteQuery(queryStr);
        while (query.next())
        {
            int id = query.value(0).toInt();
            //int idEpoch = query.value(1).toInt();
            //qulonglong unixTime = query.value(2).toULongLong();
            int size = query.value(3).toInt();

            CustomType* ct;
            auto handler = _ctHandlers.value(ctId);

            handler(size, query, ct);

            assert(ct->Size() == size);

            if (id == dbId)
            {
                retVal = T::UniquePtr_t(dynamic_cast<T*>(ct));
            }
            buffer[id] = ct;
            ++ctCount;
        }
        sLogger.Info(QString("%1 custom types readed into memory...").arg(ctCount));

        if (!retVal.get())
        {
            throw DatabaseException(QString("Custom type with id `%1` has not been found in the database.").
                arg(dbId));
        }
        return retVal;
    }

    template<typename T>
    std::vector<typename T::UniquePtr_t> MySqlSource::deserializeAndGetCustomTypes
        ( ECustomTypeId::Type ctId, const QVariant& encodedIds )
    {
        std::vector<int> ids;
        _serializer.DeserializeIds(encodedIds, ids);

        std::vector<typename T::UniquePtr_t> out;
        for (auto it = ids.cbegin(); it != ids.cend(); ++it)
        {
            out.push_back(extractCustomType<T>(ctId, *it));
        }
        return out;
    }
}

#endif // MySqlSource_h__
