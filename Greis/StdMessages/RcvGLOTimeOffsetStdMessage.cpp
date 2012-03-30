#include "RcvGLOTimeOffsetStdMessage.h"

namespace Greis
{
    RcvGLOTimeOffsetStdMessage::RcvGLOTimeOffsetStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RcvGLOTimeOffsetStdMessage::ToString() const
    {
        return toString("RcvGLOTimeOffsetStdMessage");
    }

    QByteArray RcvGLOTimeOffsetStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
