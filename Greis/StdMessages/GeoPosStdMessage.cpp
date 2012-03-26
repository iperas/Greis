#include "GeoPosStdMessage.h"

namespace Greis
{
    GeoPosStdMessage::GeoPosStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GeoPosStdMessage::ToString() const
    {
        return toString("GeoPosStdMessage");
    }

    QByteArray GeoPosStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
