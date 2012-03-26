#include "RcvOscOffsStdMessage.h"

namespace Greis
{
    RcvOscOffsStdMessage::RcvOscOffsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RcvOscOffsStdMessage::ToString() const
    {
        return toString("RcvOscOffsStdMessage");
    }

    QByteArray RcvOscOffsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
