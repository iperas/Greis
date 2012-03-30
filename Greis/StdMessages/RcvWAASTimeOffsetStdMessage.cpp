#include "RcvWAASTimeOffsetStdMessage.h"

namespace Greis
{
    RcvWAASTimeOffsetStdMessage::RcvWAASTimeOffsetStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RcvWAASTimeOffsetStdMessage::ToString() const
    {
        return toString("RcvWAASTimeOffsetStdMessage");
    }

    QByteArray RcvWAASTimeOffsetStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
