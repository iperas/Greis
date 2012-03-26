#include "CNRStdMessage.h"

namespace Greis
{
    CNRStdMessage::CNRStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string CNRStdMessage::ToString() const
    {
        return toString("CNRStdMessage");
    }

    QByteArray CNRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
