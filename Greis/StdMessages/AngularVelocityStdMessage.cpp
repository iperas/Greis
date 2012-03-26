#include "AngularVelocityStdMessage.h"

namespace Greis
{
    AngularVelocityStdMessage::AngularVelocityStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string AngularVelocityStdMessage::ToString() const
    {
        return toString("AngularVelocityStdMessage");
    }

    QByteArray AngularVelocityStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
