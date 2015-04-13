#pragma once

#include <QtCore/QtCore>
#include "Common/Singleton.h"
#include "Common/SmartPtr.h"
#include "Common/Exception.h"
#include "Common/Connection.h"
#include <Greis/Epoch.h>
#include <Greis/DataChunk.h>

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
        };
    }
}

#define sHelpers SINGLETON_INSTANCE(::Greis::Tests::Helpers)