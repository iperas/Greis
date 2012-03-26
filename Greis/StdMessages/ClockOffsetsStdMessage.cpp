#include "ClockOffsetsStdMessage.h"

namespace Greis
{
    ClockOffsetsStdMessage::ClockOffsetsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string ClockOffsetsStdMessage::ToString() const
    {
        return toString("ClockOffsetsStdMessage");
    }

    QByteArray ClockOffsetsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
