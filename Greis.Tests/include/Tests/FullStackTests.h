#pragma once

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Utils/BaseTest.h"
#include "Utils/Helpers.h"
#include "Common/SmartPtr.h"
#include "Greis/GreisMessageStream.h"
#include "Greis/FileBinaryStream.h"
#include "Greis/DataChunk.h"
#include "Greis/MySqlSink.h"
#include "Greis/MySqlSource.h"

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class FullStackTests : public BaseTest
        {
        };

        TEST_F(FullStackTests, ShouldSaveToDatabaseAndBinarizeTheSame)
        {
            // Arrange
            QString fileName = this->ResolvePath("ifz-data-0.jps");
            QByteArray expected = this->ReadJpsBinary(fileName);
            auto dataChunk = DataChunk::FromFile(fileName);

            // Act
            QByteArray actual;
            {
                // Saving to the database
                auto sink = make_unique<MySqlSink>(this->Connection().get(), 1000);
                sink->AddJpsFile(dataChunk.get());
                sink->Flush();
            }
            {
                // Reading from the database
                auto source = make_unique<MySqlSource>(this->Connection().get());
                auto loadedFile = source->ReadAll();
                actual = loadedFile->ToByteArray();
            }

            // Assert
            sHelpers.assertBinaryArray(expected, actual);
        }

        TEST_F(FullStackTests, ShouldSaveToDatabaseOneEpoch)
        {
            // Arrange
            QString fileName = this->ResolvePath("ifz-data-epoch.jps");
            auto expectedChunk = DataChunk::FromFile(fileName);
            auto expected = expectedChunk->ToByteArray();

            // Act
            QByteArray actual;
            {
                // Saving to the database
                auto sink = make_unique<MySqlSink>(this->Connection().get(), 1000);
                sink->AddJpsFile(expectedChunk.get());
                sink->Flush();
            }
            DataChunk::UniquePtr_t actualChunk;
            {
                // Reading from the database
                auto source = make_unique<MySqlSource>(this->Connection().get());
                actualChunk = source->ReadAll();
                actual = actualChunk->ToByteArray();
            }

            // Assert
            ASSERT_EQ(actualChunk->Body().size(), expectedChunk->Body().size());
            auto& actualEpoch = actualChunk->Body()[0];
            auto& expectedEpoch = expectedChunk->Body()[0];
            ASSERT_EQ(actualEpoch->DateTime, expectedEpoch->DateTime);
            ASSERT_EQ(actualEpoch->Messages.size(), expectedEpoch->Messages.size());
            auto& actualMessages = actualEpoch->Messages;
            auto& expectedMessages = expectedEpoch->Messages;
            int actualIndex = 0;
            int expectedIndex = 0;
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
                auto actualBinary = actualMsg->ToByteArray();
                auto expectedBinary = expectedMsg->ToByteArray();
                sHelpers.assertBinaryArray(actualBinary, expectedBinary);
            }

            sHelpers.assertBinaryArray(expected, actual);
        }
    }
}
