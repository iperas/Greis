#include "GLOTimeStdMessage.h"

namespace Greis
{
    GLOTimeStdMessage::GLOTimeStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GLOTimeStdMessage::ToString() const
    {
        return toString("GLOTimeStdMessage");
    }

    QByteArray GLOTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
