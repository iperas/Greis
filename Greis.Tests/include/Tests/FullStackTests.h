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
            auto dataChunk = DataChunk::FromFile(fileName);
            auto expected = dataChunk->ToByteArray();

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
    }
}
