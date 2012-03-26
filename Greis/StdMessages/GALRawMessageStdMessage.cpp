#include "GALRawMessageStdMessage.h"

namespace Greis
{
    GALRawMessageStdMessage::GALRawMessageStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GALRawMessageStdMessage::ToString() const
    {
        return toString("GALRawMessageStdMessage");
    }

    QByteArray GALRawMessageStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
