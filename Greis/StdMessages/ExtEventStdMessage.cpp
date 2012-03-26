#include "ExtEventStdMessage.h"

namespace Greis
{
    ExtEventStdMessage::ExtEventStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string ExtEventStdMessage::ToString() const
    {
        return toString("ExtEventStdMessage");
    }

    QByteArray ExtEventStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
