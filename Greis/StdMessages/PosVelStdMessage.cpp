#include "PosVelStdMessage.h"

namespace Greis
{
    PosVelStdMessage::PosVelStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string PosVelStdMessage::ToString() const
    {
        return toString("PosVelStdMessage");
    }

    QByteArray PosVelStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
