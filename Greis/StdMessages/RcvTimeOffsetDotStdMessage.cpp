#include "RcvTimeOffsetDotStdMessage.h"

namespace Greis
{
    RcvTimeOffsetDotStdMessage::RcvTimeOffsetDotStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RcvTimeOffsetDotStdMessage::ToString() const
    {
        return toString("RcvTimeOffsetDotStdMessage");
    }

    QByteArray RcvTimeOffsetDotStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
