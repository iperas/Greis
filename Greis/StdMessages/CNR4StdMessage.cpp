#include "CNR4StdMessage.h"

namespace Greis
{
    CNR4StdMessage::CNR4StdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string CNR4StdMessage::ToString() const
    {
        return toString("CNR4StdMessage");
    }

    QByteArray CNR4StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
