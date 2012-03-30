#include "GeoVelStdMessage.h"

namespace Greis
{
    GeoVelStdMessage::GeoVelStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GeoVelStdMessage::ToString() const
    {
        return toString("GeoVelStdMessage");
    }

    QByteArray GeoVelStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
