#ifndef GreisMessageStreamTests_h__
#define GreisMessageStreamTests_h__

#include "GreisMessageStream.h"
#include <gtest/gtest.h>
#include "ProjectBase/SmartPtr.h"

using namespace Greis;
using namespace ProjectBase;

namespace
{
    class GreisMessageStreamTests : public ::testing::Test
    {
    protected:
        GreisMessageStreamTests()
        {
        }

        virtual ~GreisMessageStreamTests()
        {
        }

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }
    };

    TEST_F(GreisMessageStreamTests, TestData_ipg_2011_03_28_cropped_jps)
    {
        GreisMessageStream stream("TestData/ipg_2011_03_28_00.00.00_cropped.jps");

        Message::UniquePtr_t msg;
        while((msg = stream.Next()).get())
        {
            
        }
    }
}

#endif // GreisMessageStreamTests_h__
