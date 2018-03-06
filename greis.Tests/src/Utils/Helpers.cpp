#include "Utils/Helpers.h"
#include <algorithm>
#include <gtest/gtest.h>
#include "common/File.h"

namespace Greis
{
    namespace Tests
    {
        Helpers::Helpers()
        {
        }

        Helpers::~Helpers()
        {
        }

        void Helpers::assertBinaryArray(const QByteArray& expected, const QByteArray& actual)
        {
            int size = std::min(expected.size(), actual.size());
            bool bad = false;
            int badIndex = -1;
            for (int i = 0; i < size; ++i)
            {
                if (expected[i] != actual[i])
                {
                    sLogger.Info(QString("Bytes mismatch at %1.").arg(i));
                    bad = true;
                    badIndex = i;
                    break;
                }
            }
            if (bad)
            {
                auto expectedFile = File::CreateBinary("testData.expected.jps");
                expectedFile->write(expected);
                auto actualFile = File::CreateBinary("testData.actual.jps");
                actualFile->write(actual);
                ASSERT_EQ(expected[badIndex], actual[badIndex]);
            }
            ASSERT_EQ(expected.size(), actual.size());
        }

        void Helpers::assertMessages(const std::vector<Message::UniquePtr_t>& expectedMessages, const std::vector<Message::UniquePtr_t>& actualMessages)
        {
            int actualIndex = 0;
            int expectedIndex = 0;
            int actualCount = 0;
            int expectedCount = 0;
            while (actualIndex < actualMessages.size() && expectedIndex < expectedMessages.size())
            {
                auto& actualMsg = actualMessages[actualIndex];
                auto& expectedMsg = expectedMessages[expectedIndex];
                if (actualMsg->Kind() != EMessageKind::StdMessage)
                {
                    actualIndex++;
                    continue;
                }
                if (expectedMsg->Kind() != EMessageKind::StdMessage)
                {
                    expectedIndex++;
                    continue;
                }
                if (actualMsg->Size() != expectedMsg->Size())
                {
                    int stub = 1;
                }
                ASSERT_EQ(actualMsg->Kind(), expectedMsg->Kind());
                ASSERT_EQ(actualMsg->Size(), expectedMsg->Size());
                actualIndex++;
                expectedIndex++;
                actualCount++;
                expectedCount++;
            }
            ASSERT_EQ(actualCount, expectedCount);
        }

        void Helpers::assertEpoch(Epoch* expected, Epoch* actual)
        {
            ASSERT_EQ(actual->DateTime, expected->DateTime);
            std::vector<Message::UniquePtr_t>& actualMessages = actual->Messages;
            auto& expectedMessages = expected->Messages;
            this->assertMessages(expectedMessages, actualMessages);
        }

        void Helpers::assertDataChunk(DataChunk* expected, DataChunk* actual, bool checkHead)
        {
            if (checkHead)
            {
                this->assertMessages(expected->Head(), actual->Head());
            }
            ASSERT_EQ(expected->Body().size(), actual->Body().size());
            for (size_t i = 0; i < expected->Body().size(); i++)
            {
                this->assertEpoch(expected->Body()[i].get(), actual->Body()[i].get());
            }
        }

        void Helpers::saveToFile(const QString& fileName, DataChunk* data)
        {
            auto file = File::CreateBinary(fileName);
            file->write(data->ToByteArray());
        }
    }
}
