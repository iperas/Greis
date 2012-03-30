#include "Security0StdMessage.h"

namespace Greis
{
    Security0StdMessage::Security0StdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string Security0StdMessage::ToString() const
    {
        return toString("Security0StdMessage");
    }

    QByteArray Security0StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
