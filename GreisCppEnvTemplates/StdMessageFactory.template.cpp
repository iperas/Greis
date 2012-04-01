#include "StdMessageFactory.h"
#include "ProjectBase/Logger.h"
#include "RawStdMessage.h"
// ${includes}

namespace Greis
{
    StdMessage::UniquePtr_t StdMessageFactory::Create( char* p_message, int p_length )
    {
#ifdef _DEBUG
        sLogger.Debug(QString("StdMessageFactory::Create: creating standard message with id `%1`...").
            arg(QString::fromAscii(p_message, 2)));
#endif
        auto id = StdMessage::MapIdStrToEnum(p_message);
        switch (id)
        {
        // ${stub}
        default:
            return StdMessage::UniquePtr_t(new RawStdMessage(p_message, p_length));
        }
    }
}
