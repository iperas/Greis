#ifndef MySqlSourceTests_h__
#define MySqlSourceTests_h__

#include <vector>
#include <cmath>
#include <boost/thread.hpp>
#include <gtest/gtest.h>
#include <QtCore/QtCore>
#include "Utils/BaseTest.h"
#include "Common/SmartPtr.h"
#include "Common/Path.h"
#include "Common/IniSettings.h"
#include "Common/Connection.h"
#include "Greis/DataChunk.h"
#include "Greis/MySqlSink.h"
#include "Greis/MySqlSource.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class MySqlSourceTests : public BaseTest
        {
        };

        TEST_F(MySqlSourceTests, ShouldDeserializeFromDatabase)
        {
            // Arrange
            QString filename = this->ResolvePath("ifz-data-0.jps");
            auto file = DataChunk::FromFile(filename);

            {
                int inserterBatchSize = 10000;
                auto sink = make_unique<MySqlSink>(this->Connection().get(), inserterBatchSize);
                sink->AddJpsFile(file.get());
                sink->Flush();
            }

            // Act
            try
            {
                auto source = make_unique<MySqlSource>(this->Connection().get());
                
                auto jpsFile = source->ReadAll();

                auto ba = jpsFile->ToByteArray();
                auto out = File::CreateBinary("from_database.jps");
                out->write(ba);
                out->close();
            }
            catch (Exception& ex)
            {
                // Assert
                sLogger.Error(ex.what());
                ASSERT_TRUE(false);
            }
        }
    }
}

#endif // MySqlSourceTests_h__
