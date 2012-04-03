#ifndef MySqlSource_h__
#define MySqlSource_h__

#include <boost/noncopyable.hpp>
#include <QtCore/QMap>
#include <QtCore/QDateTime>
#include "ProjectBase/Connection.h"
#include "ProjectBase/SmartPtr.h"
#include "ProjectBase/NotSupportedException.h"
#include "ProjectBase/NotImplementedException.h"
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

        // Extract custom type from buffer
        CustomType::UniquePtr_t extractCustomType(ECustomTypeId::Type ctId, int dbId);
    private:
        Connection* _connection;
        DatabaseHelper* _dbHelper;

        QDateTime _from;
        QDateTime _to;

        QMap<ECustomTypeId::Type, QMap<int, CustomType::SharedPtr_t>> _ctBuffer;

        GreisMysqlSerializer _serializer;

        QMap<int, std::string> _codes;
    };

    template<typename Func>
    void MySqlSource::handleMessage( QString queryStr, Func handleMessageFields, 
        QMap<qulonglong, Epoch*>& epochsByDateTime )
    {
        QSqlQuery query = _dbHelper->ExecuteQuery(queryStr);
        while (query.next())
        {
            int id = query.value(0).toInt();
            int idEpoch = query.value(1).toInt();
            qulonglong unixTime = query.value(2).toULongLong();
            int messageCodeId = query.value(3).toInt();
            std::string messageCode = _codes[messageCodeId];
            int bodySize = query.value(4).toInt();

            auto msg = make_unique<CNRStdMessage>(messageCode, bodySize);

            // message-specific fields handling
            handleMessageFields(query, msg.get());

            auto epoch = epochsByDateTime.value(unixTime, nullptr);
            if (epoch == nullptr)
            {
                epoch = new Epoch();
                epoch->DateTime = QDateTime::fromMSecsSinceEpoch(unixTime);
                epochsByDateTime[unixTime] = epoch;
            }
            epoch->Messages.push_back(std::move(msg));
        }
    }
}

#endif // MySqlSource_h__
