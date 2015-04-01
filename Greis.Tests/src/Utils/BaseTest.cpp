#include "Utils/BaseTest.h"
#include <gtest/gtest.h>
#include "Common/File.h"

namespace Greis
{
    namespace Tests
    {
        BaseTest::BaseTest()
        {

        }

        BaseTest::~BaseTest()
        {

        }

        void BaseTest::SetUp()
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

        void BaseTest::TearDown()
        {
            this->_connection->Database().rollback();
            sLogger.Info("Transaction has been reverted.");
        }

        const std::shared_ptr<Connection>& BaseTest::Connection() const
        {
            return this->_connection;
        }

        QString BaseTest::ResolvePath(const QString& fileName) const
        {
            QString fullPath("../../../TestData/" + fileName);
            if (!QFile::exists(fullPath))
            {
                throw Exception(QString("File %1 does not exist").arg(fullPath));
            }
            return fullPath;
        }

        QByteArray BaseTest::ReadJpsBinary(const QString& fileName) const
        {
            QByteArray binaryData;
            auto file = File::OpenReadBinary(fileName);
            binaryData = file->readAll();
            int i;
            for (i = 0; i < binaryData.size(); i++)
            {
                if (binaryData.at(i) != '\0')
                {
                    break;
                }
            }
            binaryData.remove(0, i);
            return binaryData;
        }

    }
}
