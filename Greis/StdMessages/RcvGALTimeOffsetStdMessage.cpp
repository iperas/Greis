#include "RcvGALTimeOffsetStdMessage.h"

namespace Greis
{
    RcvGALTimeOffsetStdMessage::RcvGALTimeOffsetStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RcvGALTimeOffsetStdMessage::ToString() const
    {
        return toString("RcvGALTimeOffsetStdMessage");
    }

    QByteArray RcvGALTimeOffsetStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
