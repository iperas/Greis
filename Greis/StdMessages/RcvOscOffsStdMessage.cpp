#include "RcvOscOffsStdMessage.h"

namespace Greis
{
    RcvOscOffsStdMessage::RcvOscOffsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RcvOscOffsStdMessage::ToString() const
    {
        return toString("RcvOscOffsStdMessage");
    }

    QByteArray RcvOscOffsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
