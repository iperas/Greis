#include "RcvGPSTimeOffsetStdMessage.h"

namespace Greis
{
    RcvGPSTimeOffsetStdMessage::RcvGPSTimeOffsetStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RcvGPSTimeOffsetStdMessage::ToString() const
    {
        return toString("RcvGPSTimeOffsetStdMessage");
    }

    QByteArray RcvGPSTimeOffsetStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
