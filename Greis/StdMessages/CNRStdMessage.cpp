#include "CNRStdMessage.h"

namespace Greis
{
    CNRStdMessage::CNRStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string CNRStdMessage::ToString() const
    {
        return toString("CNRStdMessage");
    }

    QByteArray CNRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
