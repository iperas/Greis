#ifndef BitConverter_Tests_h__
#define BitConverter_Tests_h__

#include "gtest/gtest.h"
#include "ProjectBase/BitConverter.h"

using namespace ProjectBase;

namespace
{
    class BitConverterTest : public ::testing::Test
    {
    protected:
        BitConverterTest() : _lsbBc(BitConverter::LeastSignificantByte)
        {
        }

        virtual ~BitConverterTest()
        {
        }

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }

        BitConverter _lsbBc;
    };

    TEST_F(BitConverterTest, LeastSignificantByteModeWorks)
    {
        unsigned short a = 12345;
        unsigned int b = 1234567891;
        short c = -12345;
        int d = -321123321;
        float e = 12345.67891f;
        double f = 1234512345.67891234;

        auto resa = _lsbBc.GetUShort((const char*) &a);
        auto resb = _lsbBc.GetUInt((const char*) &b);
        auto resc = _lsbBc.GetShort((const char*) &c);
        auto resd = _lsbBc.GetInt((const char*) &d);
        auto rese = _lsbBc.GetFloat((const char*) &e);
        auto resf = _lsbBc.GetDouble((const char*) &f);

        EXPECT_EQ(a, resa);
        EXPECT_EQ(b, resb);
        EXPECT_EQ(c, resc);
        EXPECT_EQ(d, resd);
        EXPECT_EQ(e, rese);
        EXPECT_EQ(f, resf);

        char buffer[4];
        _lsbBc.ToByteArray(b, buffer);
        EXPECT_EQ(b, *((unsigned int*)buffer));
    }
}

#endif // BitConverter_Tests_h__