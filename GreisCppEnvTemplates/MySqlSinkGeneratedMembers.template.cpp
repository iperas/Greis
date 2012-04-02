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
    
    void MySqlSink::AddMessage( Message* msg )
    {
        if (msg->Kind() != EMessageKind::StdMessage)
        {
            return;
        }

        auto stdMsg = dynamic_cast<StdMessage*>(msg);

        QVariantList fields;
        switch (stdMsg->IdNumber())
        {
        // ${SerializationCodeStub}
        default:
            throw InvalidOperationException();
        }
    }
}
