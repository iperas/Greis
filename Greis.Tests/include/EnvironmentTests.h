#pragma once

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Common/SmartPtr.h"
#include "Common/Connection.h"

using namespace Common;

namespace
{
    class EnvironmentTests : public ::testing::Test
    {
    protected:
        EnvironmentTests()
        {
        }

        virtual ~EnvironmentTests()
        {
        }

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }
    };

    TEST_F(EnvironmentTests, ShouldConnect)
    {
        auto connection = Connection::FromSettings("Db");
        connection->Connect();
        sLogger.Info("Starting a new transaction...");
        connection->Database().transaction();
        connection->DbHelper()->ExecuteQuery("SHOW TABLES;");
        connection->Database().commit();
        sLogger.Info("Connection succeeded.");
    }
}
