#include "RcvTimeStdMessage.h"

namespace Greis
{
    RcvTimeStdMessage::RcvTimeStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RcvTimeStdMessage::ToString() const
    {
        return toString("RcvTimeStdMessage");
    }

    QByteArray RcvTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
