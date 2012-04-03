#ifndef MySqlSourceTests_h__
#define MySqlSourceTests_h__

#include <gtest/gtest.h>
#include <QtCore/QtCore>
#include <vector>
#include <cmath>
#include <boost/thread.hpp>
#include "ProjectBase/SmartPtr.h"
#include "JpsFile.h"
#include "ProjectBase/Path.h"
#include "ProjectBase/IniSettings.h"
#include "ProjectBase/Connection.h"
#include "MySqlSink.h"
#include "MySqlSource.h"

using namespace Greis;
using namespace ProjectBase;

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

    TEST_F(MySqlSourceTests, mainTest)
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
}

#endif // MySqlSourceTests_h__
