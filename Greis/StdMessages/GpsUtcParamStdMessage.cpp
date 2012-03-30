#include "GpsUtcParamStdMessage.h"

namespace Greis
{
    GpsUtcParamStdMessage::GpsUtcParamStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GpsUtcParamStdMessage::ToString() const
    {
        return toString("GpsUtcParamStdMessage");
    }

    QByteArray GpsUtcParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
