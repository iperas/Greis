#include "WAASEhemerisStdMessage.h"

namespace Greis
{
    WAASEhemerisStdMessage::WAASEhemerisStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string WAASEhemerisStdMessage::ToString() const
    {
        return toString("WAASEhemerisStdMessage");
    }

    QByteArray WAASEhemerisStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
