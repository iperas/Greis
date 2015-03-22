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

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class GreisMessageStreamTests : public BaseTest
        {
        };

        TEST_F(GreisMessageStreamTests, ShouldDeserializeIntoObjectModelThenSerializeTheSameBinary)
        {
            // Arrange
            QString filename("../../../TestData/ifz-data-0.jps");
            QByteArray expected;
            {
                auto file = File::OpenReadBinary(filename);
                expected = file->readAll();
            }

            // Act
            DataChunk::UniquePtr_t file = DataChunk::FromFile(filename);
            QByteArray actual = file->ToByteArray();

            // Assert
            sHelpers.assertBinaryArray(expected, actual);
        }

        TEST_F(GreisMessageStreamTests, ShouldMakeItMultiThreaded)
        {
            // Arrange
            // Reading file content
            QString filename("../../../TestData/ifz-data-0.jps");
            auto file = File::OpenReadBinary(filename);
            file->close();
            // Making object stream of it
            GreisMessageStream stream(std::make_shared<FileBinaryStream>(filename), false, false);
            std::vector<Message::UniquePtr_t> messages;
            messages.reserve(100000);
            Message::UniquePtr_t msg;
            int i = 1;
            while ((msg = stream.Next()).get())
            {
                messages.push_back(std::move(msg));
                if (i % 100000 == 0)
                {
                    sLogger.Info(QString("100k messages deserialized. %1 total.").arg(i));
                }
                i++;
            }

            // Act
            QByteArray actual;
            {
                int coreCount = boost::thread::hardware_concurrency();
                std::vector<QByteArray> results(coreCount);
                int startOffset = std::ceil(messages.size() / (float)coreCount);
                boost::thread_group threads;
                for (int i = 0; i < coreCount; ++i)
                {
                    auto startIt = messages.cbegin() + i * startOffset;
                    auto endIt = i + 1 == coreCount
                        ? messages.cend()
                        : messages.cbegin() + (i + 1) * startOffset;
                    sLogger.Info(QString("Thread %1 serializing range %2-%3.").arg(i + 1).arg(i * startOffset).
                        arg(i + 1 == coreCount ? messages.size() - 1 : (i + 1) * startOffset - 1));
                    threads.create_thread(
                        [i, startIt, endIt, &results]
                    {
                        QByteArray& result = results[i];
                        int msgIndex = 1;
                        for (auto it = startIt; it != endIt; ++it)
                        {
                            result.append((*it)->ToByteArray());
                            if (msgIndex % 100000 == 0)
                            {
                                sLogger.Info(QString("100k messages serialized in thread %2. %1 total.").
                                    arg(msgIndex).arg(i + 1));
                            }
                            msgIndex++;
                        }
                        sLogger.Info(QString("Thread %1 finished the job.").arg(i + 1));
                    });
                }
                threads.join_all();
                sLogger.Info(QString("All threads finished the job."));
                for (int i = 0; i < coreCount; ++i)
                {
                    actual.append(results[i]);
                }
            }

            // Assert
            QByteArray expected;
            for (auto& msg : messages)
            {
                expected.append(msg->ToByteArray());
            }
            sHelpers.assertBinaryArray(expected, actual);
        }
    }
}
