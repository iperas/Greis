#pragma once

#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include "Utils/BaseTest.h"
#include "common/SmartPtr.h"
#include "greis/DataChunk.h"
#include <greis/FileBinaryStream.h>
#include <Utils/Helpers.h>

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class DataChunkTests : public BaseTest
        {
        };

        TEST_F(DataChunkTests, ShouldDeserializeIntoObjectModel)
        {
            // Arrange, Act
            QString filename = this->ResolvePath("ifz-data-0.jps");
            auto file = DataChunk::FromFile(filename);

            // Assert
            for (auto e = file->Body().begin(); e != file->Body().end(); ++e)
            {
                for (auto it = (*e)->Messages.begin(); it != (*e)->Messages.end(); ++it)
                {
                    bool res = (*it)->Validate();
                    EXPECT_TRUE(res);
                }
            }

            EXPECT_EQ(file->Body().size(), 90);
            auto ba = file->ToByteArray();
            auto outFile = File::CreateBinary("generatedJpsFile.jps");
            outFile->write(ba);
            outFile->close();
        }

        TEST_F(DataChunkTests, ShouldDeserializeIntoObjectModelByParts)
        {
            // Arrange
            QString filename = this->ResolvePath("ifz-data-0.jps");
            auto exceptedFile = DataChunk::FromFile(filename);

            // Act
            auto file = make_unique<DataChunk>();
            GreisMessageStream stream(std::make_shared<FileBinaryStream>(filename), false, false);
            file->ReadHead(stream);
            std::vector<Epoch::UniquePtr_t> epochs;
            bool hasMore;
            do
            {
                hasMore = file->ReadBody(stream, 10);
                
                for (auto& epoch : file->Body())
                {
                    epochs.push_back(std::move(epoch));
                }

                file->Body().clear();
            } while (hasMore);

            // Assert
            EXPECT_TRUE(epochs.size() == 90);
            for (int i = 0; i < epochs.size(); i++)
            {
                auto& expectedEpoch = exceptedFile->Body()[i];
                auto& actualEpoch = epochs[i];
                EXPECT_EQ(expectedEpoch->Messages.size(), actualEpoch->Messages.size());
                sHelpers.assertBinaryArray(expectedEpoch->ToByteArray(), actualEpoch->ToByteArray());
            }
        }
    }
}
