#include "AntNameStdMessage.h"

namespace Greis
{
    AntNameStdMessage::AntNameStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string AntNameStdMessage::ToString() const
    {
        return toString("AntNameStdMessage");
    }

    QByteArray AntNameStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
