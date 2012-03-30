#include "PosVelVectorStdMessage.h"

namespace Greis
{
    PosVelVectorStdMessage::PosVelVectorStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string PosVelVectorStdMessage::ToString() const
    {
        return toString("PosVelVectorStdMessage");
    }

    QByteArray PosVelVectorStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
