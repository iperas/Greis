#ifndef MySqlSinkTests_h__
#define MySqlSinkTests_h__

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Utils/BaseTest.h"
#include "Common/SmartPtr.h"
#include "Common/Path.h"
#include "Common/IniSettings.h"
#include "Common/Connection.h"
#include "Greis/DataChunk.h"
#include "Greis/MySqlSink.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class MySqlSinkTests : public BaseTest
        {
        };

        TEST_F(MySqlSinkTests, ShouldSerializeIntoDatabase)
        {
            QString filename("../../../TestData/ifz-data-0.jps");
            auto file = DataChunk::FromFile(filename);

            bool wrapIntoTransaction = sIniSettings.value("WrapIntoTransaction", false).toBool();
            int inserterBatchSize = sIniSettings.value("inserterBatchSize", 10000).toInt();
            auto connection = Connection::FromSettings("Db");
            connection->Connect();

            bool transactionStarted;
            if (wrapIntoTransaction)
            {
                sLogger.Info("Starting a new transaction...");
                transactionStarted = connection->Database().transaction();
            }
            {
                auto sink = make_unique<MySqlSink>(connection.get(), inserterBatchSize);
                sink->AddJpsFile(file.get());
                sink->Flush();
            }
            if (wrapIntoTransaction && transactionStarted)
            {
                connection->Database().commit();
                sLogger.Info("Transaction has been committed.");
            }
            sLogger.Info(QString("Insertion completed."));
        }
    }
}

#endif // MySqlSinkTests_h__
