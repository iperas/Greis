#include "Security1StdMessage.h"

namespace Greis
{
    Security1StdMessage::Security1StdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string Security1StdMessage::ToString() const
    {
        return toString("Security1StdMessage");
    }

    QByteArray Security1StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
