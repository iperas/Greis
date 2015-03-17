#ifndef MySqlSourceTests_h__
#define MySqlSourceTests_h__

#include <vector>
#include <cmath>
#include <boost/thread.hpp>
#include <gtest/gtest.h>
#include <QtCore/QtCore>
#include "Common/SmartPtr.h"
#include "Common/Path.h"
#include "Common/IniSettings.h"
#include "Common/Connection.h"
#include "Greis/DataChunk.h"
#include "Greis/MySqlSink.h"
#include "Greis/MySqlSource.h"

using namespace Greis;
using namespace Common;

namespace
{
    class MySqlSourceTests : public ::testing::Test
    {
    protected:
        MySqlSourceTests()
        {
        }

        virtual ~MySqlSourceTests()
        {
        }

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }
    };

    TEST_F(MySqlSourceTests, ShouldDeserializeFromDatabase)
    {
        try
        {
            sIniSettings.Initialize(Path::Combine(Path::ApplicationDirPath(), "config.ini"));
    
            auto connection = Connection::FromSettings("Db");
            connection->Connect();

            auto source = make_unique<MySqlSource>(connection.get());

            auto jpsFile = source->ReadRange(QDateTime(QDate(2000, 03, 22), QTime(0, 0, 0), Qt::LocalTime), 
                QDateTime(QDate(2013, 03, 22), QTime(5, 0, 1), Qt::LocalTime));

            auto ba = jpsFile->ToByteArray();
            auto out = File::CreateBinary("from_database.jps");
            out->write(ba);
            out->close();
        }
        catch (Exception& ex)
        {
            sLogger.Error(ex.what());
            ASSERT_TRUE(false);
        }
    }
}

#endif // MySqlSourceTests_h__
