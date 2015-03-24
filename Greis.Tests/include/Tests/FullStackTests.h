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

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class FullStackTests : public BaseTest
        {
        };

        TEST_F(FullStackTests, ShouldSaveToTheDatabaseAndBinarizeTheSame)
        {
            // Arrange
            QString filename("../../../TestData/ifz-data-0.jps");
            QByteArray expected;
            {
                auto file = File::OpenReadBinary(filename);
                expected = file->readAll();

                int i;
                for (i = 0; i < expected.size(); i++)
                {
                    if (expected.at(i) != '\0')
                    {
                        break;
                    }
                }
                expected.remove(0, i);
            }
            auto dataChunk = DataChunk::FromFile(filename);

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
                auto loadedFile = source->ReadRange(nullptr, nullptr);
                actual = loadedFile->ToByteArray();
            }

            // Assert
            sHelpers.assertBinaryArray(expected, actual);
        }
    }
}
