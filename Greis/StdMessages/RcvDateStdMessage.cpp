#include "RcvDateStdMessage.h"

namespace Greis
{
    RcvDateStdMessage::RcvDateStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RcvDateStdMessage::ToString() const
    {
        return toString("RcvDateStdMessage");
    }

    QByteArray RcvDateStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
