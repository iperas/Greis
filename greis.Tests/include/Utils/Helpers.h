#pragma once

#include <QtCore/QtCore>
#include "common/Singleton.h"
#include "common/SmartPtr.h"
#include "common/Exception.h"
#include "common/Connection.h"
#include <greis/Epoch.h>
#include <greis/DataChunk.h>

using namespace Common;

namespace Greis
{
    namespace Tests
    {
        class Helpers
        {
            SINGLETON_BLOCK(Helpers)
        public:
            Helpers();
            ~Helpers();

            void assertBinaryArray(const QByteArray& expected, const QByteArray& actual);
            void assertMessages(const std::vector<Message::UniquePtr_t>& expectedMessages, const std::vector<Message::UniquePtr_t>& actualMessages);
            void assertEpoch(Epoch* expected, Epoch* actual);
            void assertDataChunk(DataChunk* expected, DataChunk* actual, bool assertHead);
            void saveToFile(const QString& fileName, DataChunk* data);
        };
    }
}

#define sHelpers SINGLETON_INSTANCE(::Greis::Tests::Helpers)