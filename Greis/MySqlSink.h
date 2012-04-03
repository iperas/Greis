#ifndef MySqlSink_h__
#define MySqlSink_h__

#include <boost/noncopyable.hpp>
#include <QtCore/QList>
#include <QtCore/QMap>
#include "ProjectBase/Connection.h"
#include "ProjectBase/SmartPtr.h"
#include "ProjectBase/NotSupportedException.h"
#include "ProjectBase/NotImplementedException.h"
#include "ProjectBase/DataInserter.h"
#include "ProjectBase/DataBatchInserter.h"
#include "EMessageId.h"
#include "ECustomTypeId.h"
#include "JpsFile.h"
#include "GreisMysqlSerializer.h"
#include "CustomType.h"

using namespace ProjectBase;

namespace Greis
{
    class MySqlSink : private boost::noncopyable
    {
    public:
        SMART_PTR_T(MySqlSink);

        MySqlSink(Connection* connection, int inserterBatchSize = 10000);
        ~MySqlSink();

        void AddJpsFile(JpsFile* file);

        void AddEpoch(QDateTime dateTime);
        void AddMessage(Message* msg);

        void Flush();
    private:
        void construct();

        int addCustomType(CustomType* ct);

        // Serialize objects fields into QVariantList with calling addCustomType if needed.
        void serializeMessage(StdMessage* msg, QVariantList& out);
        void serializeCustomType(CustomType* ct, QVariantList& out);

        // Add vector of custom types and serialize it for standard message table field.
        template<typename T>
        inline QVariant addCustomTypesAndSerialize(const std::vector<T>& field)
        {
            std::vector<int> ids;
            for (auto it = field.cbegin(); it != field.cend(); ++it)
            {
                int idVal = addCustomType(it->get());
                ids.push_back(idVal);
            }
            return _serializer.SerializeIds(ids);
        }
    private:
        Connection* _connection;
        DatabaseHelper* _dbHelper;
        int _inserterBatchSize;

        QMap<EMessageId::Type, DataBatchInserter::SharedPtr_t> _msgInserters;
        QMap<ECustomTypeId::Type, DataBatchInserter::SharedPtr_t> _ctInserters;

        GreisMysqlSerializer _serializer;

        DataBatchInserter::SharedPtr_t _epochInserter;
        DataBatchInserter::SharedPtr_t _rawMessageInserter;
        int _lastEpochId;
        QDateTime _lastEpochDateTime;

        QMap<ECustomTypeId::Type, int> _ctCurrentMaxId;
        QMap<std::string, int> _codeIds;
    };
}

#endif // MySqlSink_h__