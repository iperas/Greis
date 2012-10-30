#include "StdMessageFactory.h"
#include "ProjectBase/Logger.h"
#include "RawStdMessage.h"
#include "AllStdMessages.h"

namespace Greis
{
    StdMessage::UniquePtr_t StdMessageFactory::Create( char* p_message, int p_length )
    {
#ifdef _DEBUG
        sLogger.Debug(QString("StdMessageFactory::Create: creating standard message with id `%1`...").
            arg(QString::fromAscii(p_message, 2)));
#endif
        auto id = StdMessage::MapIdStrToEnum(p_message);
        auto msg = createById(id, p_message, p_length);
        if (!msg->IsCorrect())
        {
            msg = StdMessage::UniquePtr_t(new RawStdMessage(p_message, p_length));
        }
        return msg;
    }

    StdMessage::UniquePtr_t StdMessageFactory::createById( EMessageId::Type id, char* p_message, int p_length )
    {
        switch (id)
        {
            // ${stub}
        default:
            return StdMessage::UniquePtr_t(new RawStdMessage(p_message, p_length));
        }
    }
}
