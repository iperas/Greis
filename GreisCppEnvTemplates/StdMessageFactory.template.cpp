#include "StdMessageFactory.h"
#include "RawStdMessage.h"
// ${includes}

namespace Greis
{
    StdMessage::UniquePtr_t StdMessageFactory::Create( char* p_message, int p_length )
    {
        auto id = StdMessage::MapIdStrToEnum(p_message);
        switch (id)
        {
        // ${stub}
        default:
            return StdMessage::UniquePtr_t(new RawStdMessage(p_message, p_length));
        }
    }
}
