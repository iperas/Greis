#include "RotationAnglesStdMessage.h"

namespace Greis
{
    RotationAnglesStdMessage::RotationAnglesStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RotationAnglesStdMessage::ToString() const
    {
        return toString("RotationAnglesStdMessage");
    }

    QByteArray RotationAnglesStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
