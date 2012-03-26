#include "GpsNavDataStdMessage.h"

namespace Greis
{
    GpsNavDataStdMessage::GpsNavDataStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GpsNavDataStdMessage::ToString() const
    {
        return toString("GpsNavDataStdMessage");
    }

    QByteArray GpsNavDataStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
