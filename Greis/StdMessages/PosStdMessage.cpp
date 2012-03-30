#include "PosStdMessage.h"

namespace Greis
{
    PosStdMessage::PosStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string PosStdMessage::ToString() const
    {
        return toString("PosStdMessage");
    }

    QByteArray PosStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
