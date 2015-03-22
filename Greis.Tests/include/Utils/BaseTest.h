#pragma once

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Common/SmartPtr.h"
#include "Common/Exception.h"
#include "Common/Connection.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class BaseTest : public ::testing::Test
        {
        private:
            std::shared_ptr<Connection> _connection;
        protected:
            BaseTest()
            {
            }

            virtual ~BaseTest()
            {
            }

            virtual void SetUp()
            {
                sLogger.Info("Connecting to the test database...");
                this->_connection = Connection::FromSettings("Db");
                this->_connection->Connect();

                this->_connection->DbHelper()->ExecuteQuery("SET autocommit=0;");

                sLogger.Info("Starting a new transaction...");
                bool z = this->_connection->Database().driver()->hasFeature(QSqlDriver::Transactions);
                bool transactionStarted = this->_connection->Database().transaction();
                if (!transactionStarted)
                {
                    auto errText = this->_connection->Database().lastError().text();
                    throw Exception("Failed to start a database transaction.");
                }
                sLogger.Info("SetUp Succeeded...");
            }

            virtual void TearDown()
            {
                this->_connection->Database().rollback();
                sLogger.Info("Transaction has been reverted.");
            }

            const std::shared_ptr<Connection>& Connection() const
            {
                return this->_connection;
            }
        };
    }
}
