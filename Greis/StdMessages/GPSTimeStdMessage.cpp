#include "GPSTimeStdMessage.h"

namespace Greis
{
    GPSTimeStdMessage::GPSTimeStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GPSTimeStdMessage::ToString() const
    {
        return toString("GPSTimeStdMessage");
    }

    QByteArray GPSTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
