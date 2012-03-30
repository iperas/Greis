#ifndef GreisBinarySerializerTests_h__
#define GreisBinarySerializerTests_h__

#include "gtest/gtest.h"
#include "GreisBinarySerializer.h"
#include "GreisTypes.h"
#include "RawCustomType.h"
#include "ProjectBase/BitConverter.h"
#include "ProjectBase/SmartPtr.h"

using namespace Greis;
using namespace ProjectBase;

namespace
{
    class GreisBinarySerializerTests : public ::testing::Test
    {
    protected:
        GreisBinarySerializerTests() : _serializer(BitConverter::LeastSignificantByte)
        {
        }

        virtual ~GreisBinarySerializerTests()
        {
        }

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }

        GreisBinarySerializer _serializer;
    };

    TEST_F(GreisBinarySerializerTests, LeastSignificantByteMode_SerializeMethods)
    {
        // unsigned
        {
            Types::u1 expected = 234;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        {
            Types::u2 expected = 12345;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        {
            Types::u4 expected = 1234567891;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        // signed
        {
            Types::i1 expected = -112;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        {
            Types::i2 expected = -12345;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        {
            Types::i4 expected = -1234567891;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        // floating point
        {
            Types::f4 expected = 12345.67891f;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        {
            Types::f8 expected = 1234512345.67891234;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        // a1
        {
            Types::a1 expected = 112;
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, *((decltype(expected)*)buffer.data()));
        }
        // string
        {
            std::string expected = "test1ôûâ";
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected, std::string(buffer.data(), buffer.size()));
        }
        // Serialize(vector<int>) == Serialize(int) || Serialize(int) || ... || Serialize(int)
        {
            std::vector<Types::i4> source;
            source.push_back(-1234567891);
            source.push_back(-1234567892);
            source.push_back(-1234567893);
            QByteArray buffer;
            _serializer.Serialize(source, buffer);

            QByteArray expected;
            int val = -1234567891;
            _serializer.Serialize(val, expected);
            val = -1234567892;
            _serializer.Serialize(val, expected);
            val = -1234567893;
            _serializer.Serialize(val, expected);

            EXPECT_EQ(expected, buffer);
        }
        // CustomType::UniquePtr_t
        {
            auto expected = make_unique<RawCustomType>("test2aaaz", 9);
            QByteArray buffer;
            _serializer.Serialize(expected, buffer);
            EXPECT_EQ(expected->ToByteArray(), 
                make_unique<RawCustomType>(buffer.data(), buffer.size())->ToByteArray());
        }
        // vector<CustomType::UniquePtr_t>
        {
            std::vector<RawCustomType::UniquePtr_t> source;
            source.push_back(make_unique<RawCustomType>("test1", 5));
            source.push_back(make_unique<RawCustomType>("test2", 5));
            source.push_back(make_unique<RawCustomType>("test3", 5));
            QByteArray buffer;
            _serializer.Serialize(source, buffer);

            QByteArray expected;
            RawCustomType::UniquePtr_t val = make_unique<RawCustomType>("test1", 5);
            _serializer.Serialize(val, expected);
            val = make_unique<RawCustomType>("test2", 5);
            _serializer.Serialize(val, expected);
            val = make_unique<RawCustomType>("test3", 5);
            _serializer.Serialize(val, expected);

            EXPECT_EQ(expected, buffer);
        }
    }
}

#endif // GreisBinarySerializerTests_h__
