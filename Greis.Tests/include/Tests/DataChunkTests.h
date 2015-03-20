#pragma once

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Utils/BaseTest.h"
#include "Common/SmartPtr.h"
#include "Greis/DataChunk.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class DataChunkTests : public BaseTest
        {
        };

        TEST_F(DataChunkTests, TestData_ipg_2011_03_28_cropped_jps_DeserializationTest)
        {
            QString filename("TestData/ipg_2011_03_28_00.00.00_cropped.jps");

            auto file = DataChunk::FromFile(filename);

            for (auto e = file->Body().begin(); e != file->Body().end(); ++e)
            {
                for (auto it = (*e)->Messages.begin(); it != (*e)->Messages.end(); ++it)
                {
                    bool res = (*it)->Validate();
                    EXPECT_TRUE(res);
                }
            }

            auto ba = file->ToByteArray();
            auto outFile = File::CreateBinary("generatedJpsFile.jps");
            outFile->write(ba);
            outFile->close();
        }
    }
}
