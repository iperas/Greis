#include "TrackingTimeStdMessage.h"

namespace Greis
{
    TrackingTimeStdMessage::TrackingTimeStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string TrackingTimeStdMessage::ToString() const
    {
        return toString("TrackingTimeStdMessage");
    }

    QByteArray TrackingTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
