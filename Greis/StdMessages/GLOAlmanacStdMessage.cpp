#include "GLOAlmanacStdMessage.h"

namespace Greis
{
    GLOAlmanacStdMessage::GLOAlmanacStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GLOAlmanacStdMessage::ToString() const
    {
        return toString("GLOAlmanacStdMessage");
    }

    QByteArray GLOAlmanacStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
