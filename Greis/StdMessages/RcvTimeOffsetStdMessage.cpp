#include "RcvTimeOffsetStdMessage.h"

namespace Greis
{
    RcvTimeOffsetStdMessage::RcvTimeOffsetStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RcvTimeOffsetStdMessage::ToString() const
    {
        return toString("RcvTimeOffsetStdMessage");
    }

    QByteArray RcvTimeOffsetStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
