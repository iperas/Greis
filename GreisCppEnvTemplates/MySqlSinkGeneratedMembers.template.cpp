#include "MySqlSink.h"
#include "ProjectBase\Connection.h"
#include "AllStdMessages.h"

using namespace ProjectBase;

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
        switch (msg->IdNumber())
        {
        // ${MsgSerializationCodeStub}
        default:
            throw InvalidOperationException();
        }
    }

    void MySqlSink::serializeCustomType( CustomType* ct, QVariantList& out )
    {
        switch (ct->IdNumber())
        {
        // ${CtSerializationCodeStub}
        default:
            throw InvalidOperationException();
        }
    }
}
