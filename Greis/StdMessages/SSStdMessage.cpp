#include "SSStdMessage.h"

namespace Greis
{
    SSStdMessage::SSStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string SSStdMessage::ToString() const
    {
        return toString("SSStdMessage");
    }

    QByteArray SSStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
