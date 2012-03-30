#include "GLOEphemerisStdMessage.h"

namespace Greis
{
    GLOEphemerisStdMessage::GLOEphemerisStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GLOEphemerisStdMessage::ToString() const
    {
        return toString("GLOEphemerisStdMessage");
    }

    QByteArray GLOEphemerisStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
