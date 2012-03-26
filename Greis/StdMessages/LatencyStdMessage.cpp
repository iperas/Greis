#include "LatencyStdMessage.h"

namespace Greis
{
    LatencyStdMessage::LatencyStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string LatencyStdMessage::ToString() const
    {
        return toString("LatencyStdMessage");
    }

    QByteArray LatencyStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
