#include "GALEphemerisStdMessage.h"

namespace Greis
{
    GALEphemerisStdMessage::GALEphemerisStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GALEphemerisStdMessage::ToString() const
    {
        return toString("GALEphemerisStdMessage");
    }

    QByteArray GALEphemerisStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
