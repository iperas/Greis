#ifndef MySqlSink_h__
#define MySqlSink_h__

#include <QList>
#include "Database/Connection.h"
#include "Util/SharedPtr.h"
#include "MetaInfo.h"
#include "GreisMessage.h"

using namespace Database;
using namespace Greis;

namespace Domain
{
    class MySqlSink
    {
    private:
        MetaInfo::Pointer_t _metaInfo;
        Connection* _connection;
        DatabaseHelper* _dbHelper;

        QMap<QString, MessageMeta::Pointer_t> _codeToMsgMap;
    public:
        SHARED_PTR_T(MySqlSink);

        MySqlSink(MetaInfo::Pointer_t metaInfo, Connection* connection)
        {
            _metaInfo = metaInfo;
            _connection = connection;
            _dbHelper = _connection->DbHelper();

            foreach (MessageMeta::Pointer_t msg, _metaInfo->MessagesMeta)
            {
                foreach (MessageCode::Pointer_t code, msg->Codes)
                {
                    _codeToMsgMap[code->Code] = msg;
                }
            }
        }

        void AddMessage(StdMessage_t::Pointer_t msg)
        {
            auto msgCode = QString::fromAscii(msg->id().c_str(), 2);
            auto messageMeta = _codeToMsgMap.value(msgCode, MessageMeta::Pointer_t());

            if (!messageMeta.get())
            {
                // Unknown message
                return;
            }
        }
    };
}

#endif // MySqlSink_h__