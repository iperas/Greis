#include "StdMessage.h"
#include <map>

using std::map;

#define CHAR2_TO_USHORT(c_id) ((((unsigned short)(c_id)[0]) << 8) | (c_id)[1])

namespace Greis
{
    EMessageId::Type StdMessage::MapIdStrToEnum( char* p_id )
    {
        static map<unsigned short, EMessageId::Type> cache;
        if (cache.size() == 0)
        {
            // ${stub}
        }
        auto it = cache.find(CHAR2_TO_USHORT(p_id));

        return it != cache.end() 
            ? it->second 
            : EMessageId::Unknown;
    }
}
