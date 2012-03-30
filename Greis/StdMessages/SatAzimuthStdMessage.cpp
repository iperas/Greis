#include "SatAzimuthStdMessage.h"

namespace Greis
{
    SatAzimuthStdMessage::SatAzimuthStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string SatAzimuthStdMessage::ToString() const
    {
        return toString("SatAzimuthStdMessage");
    }

    QByteArray SatAzimuthStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
