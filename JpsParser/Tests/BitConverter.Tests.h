#ifndef BitConverter_Tests_h__
#define BitConverter_Tests_h__

#include <cassert>
#include "ProjectBase/BitConverter.h"

namespace Tests
{
    class BitConverterTests
    {
    public:
        void TestLittleEndian()
        {
            BitConverter bc(BitConverter::LeastSignificantByte);

            unsigned short a = 12345;
            unsigned int b = 1234567891;
            short c = -12345;
            int d = -321123321;
            float e = 12345.67891f;
            double f = 1234512345.67891234;

            auto resa = bc.GetUShort((const char*) &a);
            auto resb = bc.GetUInt((const char*) &b);
            auto resc = bc.GetShort((const char*) &c);
            auto resd = bc.GetInt((const char*) &d);
            auto rese = bc.GetFloat((const char*) &e);
            auto resf = bc.GetDouble((const char*) &f);

            assert(resa == a);
            assert(resb == b);
            assert(resc == c);
            assert(resd == d);
            assert(rese == e);
            assert(resf == f);

            char buffer[4];
            bc.ToByteArray(b, buffer);
            assert(*((unsigned int*)buffer) == b);
        }
    };
}

#endif // BitConverter_Tests_h__