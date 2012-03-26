#include "GPSAlm0StdMessage.h"

namespace Greis
{
    GPSAlm0StdMessage::GPSAlm0StdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GPSAlm0StdMessage::ToString() const
    {
        return toString("GPSAlm0StdMessage");
    }

    QByteArray GPSAlm0StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
