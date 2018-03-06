#ifndef MySqlSinkTests_h__
#define MySqlSinkTests_h__

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Utils/BaseTest.h"
#include "common/SmartPtr.h"
#include "common/Path.h"
#include "common/IniSettings.h"
#include "common/Connection.h"
#include "greis/DataChunk.h"
#include "greis/MySqlSink.h"

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
            QString filename = this->ResolvePath("ifz-data-0.jps");
            auto file = DataChunk::FromFile(filename);

            int inserterBatchSize = 10000;

            {
                auto sink = make_unique<MySqlSink>(this->Connection(), inserterBatchSize);
                sink->AddJpsFile(file.get());
                sink->Flush();
            }
            sLogger.Info(QString("Insertion completed."));
        }
    }
}

#endif // MySqlSinkTests_h__
