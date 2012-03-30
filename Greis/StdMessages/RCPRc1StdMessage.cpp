#include "RCPRc1StdMessage.h"

namespace Greis
{
    RCPRc1StdMessage::RCPRc1StdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RCPRc1StdMessage::ToString() const
    {
        return toString("RCPRc1StdMessage");
    }

    QByteArray RCPRc1StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
