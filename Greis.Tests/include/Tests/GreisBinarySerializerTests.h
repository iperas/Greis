#pragma once

#include "gtest/gtest.h"
#include "Common/BitConverter.h"
#include "Common/SmartPtr.h"
#include "Utils/BaseTest.h"
#include "Greis/GreisBinarySerializer.h"
#include "Greis/GreisTypes.h"
#include "Greis/RawCustomType.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class GreisBinarySerializerTests : public BaseTest
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

        TEST_F(GreisBinarySerializerTests, LeastSignificantByteMode_DeserializeMethods)
        {
            // unsigned
            {
                Types::u1 expected = 234;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            {
                Types::u2 expected = 12345;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            {
                Types::u4 expected = 1234567891;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            // signed
            {
                Types::i1 expected = -112;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            {
                Types::i2 expected = -12345;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            {
                Types::i4 expected = -1234567891;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            // floating point
            {
                Types::f4 expected = 12345.67891f;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            {
                Types::f8 expected = 1234512345.67891234;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            // a1
            {
                Types::a1 expected = 112;
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), actual);
                EXPECT_EQ(expected, actual);
            }
            // string
            {
                std::string expected = "test1ôûâ";
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), buffer.size(), actual);
                EXPECT_EQ(expected, actual);
            }
            // Deserialize(vector<int>) == Deserialize(int) || Deserialize(int) || ... || Deserialize(int)
            {
                std::vector<Types::i4> expected;
                expected.push_back(-1234567891);
                expected.push_back(-1234567892);
                expected.push_back(-1234567893);
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);

                std::vector<Types::i4> actual;
                _serializer.Deserialize(buffer, buffer.size(), actual);

                ASSERT_EQ(expected.size(), actual.size());
                for (int i = 0; i < (int)expected.size(); ++i)
                {
                    EXPECT_EQ(expected[i], actual[i]);
                }
            }
            // CustomType::UniquePtr_t
            {
                auto expected = make_unique<RawCustomType>("test2aaaz", 9);
                decltype(expected) actual;
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);
                _serializer.Deserialize(buffer.data(), buffer.size(), actual);
                EXPECT_EQ(expected->ToByteArray(), actual->ToByteArray());
            }
            // vector<CustomType::UniquePtr_t>
            {
                std::vector<RawCustomType::UniquePtr_t> expected;
                expected.push_back(make_unique<RawCustomType>("test1", 5));
                expected.push_back(make_unique<RawCustomType>("test2", 5));
                expected.push_back(make_unique<RawCustomType>("test3", 5));
                QByteArray buffer;
                _serializer.Serialize(expected, buffer);

                std::vector<RawCustomType::UniquePtr_t> actual;
                _serializer.Deserialize(buffer, buffer.size(), 5, actual);

                ASSERT_EQ(expected.size(), actual.size());
                for (int i = 0; i < (int)expected.size(); ++i)
                {
                    EXPECT_EQ(expected[i]->ToByteArray(), actual[i]->ToByteArray());
                }
            }
        }
    }
}
