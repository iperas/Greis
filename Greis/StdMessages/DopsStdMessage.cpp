#include "DopsStdMessage.h"

namespace Greis
{
    DopsStdMessage::DopsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string DopsStdMessage::ToString() const
    {
        return toString("DopsStdMessage");
    }

    QByteArray DopsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
