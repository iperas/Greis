#include "SPRStdMessage.h"

namespace Greis
{
    SPRStdMessage::SPRStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string SPRStdMessage::ToString() const
    {
        return toString("SPRStdMessage");
    }

    QByteArray SPRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
