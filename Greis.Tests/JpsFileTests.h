#ifndef JpsFileTests_h__
#define JpsFileTests_h__

#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <boost/thread.hpp>
#include "ProjectBase/SmartPtr.h"
#include "JpsFile.h"

using namespace Greis;
using namespace ProjectBase;

namespace
{
    class JpsFileTests : public ::testing::Test
    {
    protected:
        JpsFileTests()
        {
        }

        virtual ~JpsFileTests()
        {
        }

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }
    };

    TEST_F(JpsFileTests, TestData_ipg_2011_03_28_cropped_jps_DeserializationTest)
    {
        QString filename("TestData/ipg_2011_03_28_00.00.00_cropped.jps");

        auto file = JpsFile::FromFile(filename);

        auto ba = file->ToByteArray();
        auto outFile = File::CreateBinary("generatedJpsFile.jps");
        outFile->write(ba);
        outFile->close();
    }
}

#endif // JpsFileTests_h__
