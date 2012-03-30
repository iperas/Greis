#include "PosCovStdMessage.h"

namespace Greis
{
    PosCovStdMessage::PosCovStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string PosCovStdMessage::ToString() const
    {
        return toString("PosCovStdMessage");
    }

    QByteArray PosCovStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
