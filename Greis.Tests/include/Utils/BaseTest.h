#pragma once

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Common/SmartPtr.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class BaseTest : public ::testing::Test
        {
        protected:
            BaseTest()
            {
            }

            virtual ~BaseTest()
            {
            }

            virtual void SetUp()
            {
            }

            virtual void TearDown()
            {
            }
        };
    }
}
