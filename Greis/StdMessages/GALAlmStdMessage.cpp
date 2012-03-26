#include "GALAlmStdMessage.h"

namespace Greis
{
    GALAlmStdMessage::GALAlmStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GALAlmStdMessage::ToString() const
    {
        return toString("GALAlmStdMessage");
    }

    QByteArray GALAlmStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
