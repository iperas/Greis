#include "REStdMessage.h"

namespace Greis
{
    REStdMessage::REStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string REStdMessage::ToString() const
    {
        return toString("REStdMessage");
    }

    QByteArray REStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
