#include "Common/Connection.h"
#include "Common/Logger.h"
#include "Greis/AllStdMessages.h"
#include "Greis/MySqlSink.h"

using namespace Common;

namespace Greis
{
    MySqlSink::MySqlSink(Connection* connection, int inserterBatchSize)
    {
        _connection = connection;
        _dbHelper = _connection->DbHelper();
        _inserterBatchSize = inserterBatchSize;
        
        construct();

        // ${InsertersCreationCode}
    }

    void MySqlSink::serializeMessage( StdMessage* msg, QVariantList& out )
    {
        if (!msg->IsCorrect())
        {
            return;
        }

        switch (msg->IdNumber())
        {
        // ${MsgSerializationCodeStub}
        default:
            sLogger.Debug(QString("Skipping serialization for the %1 message.").arg(QString::fromStdString(msg->ToString())));
            break;
            //throw InvalidOperationException();
        }
    }

    void MySqlSink::serializeCustomType( CustomType* ct, QVariantList& out )
    {
        if (!ct->IsCorrect())
        {
            return;
        }

        switch (ct->IdNumber())
        {
        // ${CtSerializationCodeStub}
        default:
            sLogger.Debug(QString("Skipping serialization for the %1 custom type.").arg(ct->IdNumber()));
            break;
            //throw InvalidOperationException();
        }
    }
}
