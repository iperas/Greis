#include "SRPRStdMessage.h"

namespace Greis
{
    SRPRStdMessage::SRPRStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string SRPRStdMessage::ToString() const
    {
        return toString("SRPRStdMessage");
    }

    QByteArray SRPRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
