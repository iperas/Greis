#include "WAASRawMessageStdMessage.h"

namespace Greis
{
    WAASRawMessageStdMessage::WAASRawMessageStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string WAASRawMessageStdMessage::ToString() const
    {
        return toString("WAASRawMessageStdMessage");
    }

    QByteArray WAASRawMessageStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
