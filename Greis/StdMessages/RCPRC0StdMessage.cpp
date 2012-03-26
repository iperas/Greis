#include "RCPRC0StdMessage.h"

namespace Greis
{
    RCPRC0StdMessage::RCPRC0StdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RCPRC0StdMessage::ToString() const
    {
        return toString("RCPRC0StdMessage");
    }

    QByteArray RCPRC0StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
