#ifndef Epoch_h__
#define Epoch_h__

#include <QtCore/QDateTime>
#include <vector>
#include "Message.h"

namespace Greis
{
    struct Epoch
    {
        SMART_PTR_T(Epoch);

        QDateTime DateTime;
        std::vector<Message::UniquePtr_t> Messages;
    };
}

#endif // Epoch_h__
