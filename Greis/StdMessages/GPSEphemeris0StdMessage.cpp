#include "GPSEphemeris0StdMessage.h"

namespace Greis
{
    GPSEphemeris0StdMessage::GPSEphemeris0StdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GPSEphemeris0StdMessage::ToString() const
    {
        return toString("GPSEphemeris0StdMessage");
    }

    QByteArray GPSEphemeris0StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
