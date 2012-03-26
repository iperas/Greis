#include "PosCompTimeStdMessage.h"

namespace Greis
{
    PosCompTimeStdMessage::PosCompTimeStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string PosCompTimeStdMessage::ToString() const
    {
        return toString("PosCompTimeStdMessage");
    }

    QByteArray PosCompTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
