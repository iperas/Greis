#pragma once

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Utils/BaseTest.h"
#include "Common/SmartPtr.h"
#include "Common/Connection.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class EnvironmentTests : public BaseTest
        {
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
}
