#ifndef MySqlSinkTests_h__
#define MySqlSinkTests_h__

#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <boost/thread.hpp>
#include "ProjectBase/SmartPtr.h"
#include "JpsFile.h"
#include "ProjectBase/Path.h"
#include "ProjectBase/IniSettings.h"
#include "ProjectBase/Connection.h"
#include "MySqlSink.h"

using namespace Greis;
using namespace ProjectBase;

namespace
{
    class MySqlSinkTests : public ::testing::Test
    {
    protected:
        MySqlSinkTests()
        {
        }

        virtual ~MySqlSinkTests()
        {
        }

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }
    };

    TEST_F(MySqlSinkTests, mainTest)
    {
        QString filename("TestData/ipg_2011_03_28_00.00.00_cropped.jps");
        auto file = JpsFile::FromFile(filename);

        sIniSettings.Initialize(Path::Combine(Path::ApplicationDirPath(), "config.ini"));

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

#endif // MySqlSinkTests_h__
