#include "TrackingTimeCAStdMessage.h"

namespace Greis
{
    TrackingTimeCAStdMessage::TrackingTimeCAStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string TrackingTimeCAStdMessage::ToString() const
    {
        return toString("TrackingTimeCAStdMessage");
    }

    QByteArray TrackingTimeCAStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
