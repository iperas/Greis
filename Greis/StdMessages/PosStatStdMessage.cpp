#include "PosStatStdMessage.h"

namespace Greis
{
    PosStatStdMessage::PosStatStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string PosStatStdMessage::ToString() const
    {
        return toString("PosStatStdMessage");
    }

    QByteArray PosStatStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
