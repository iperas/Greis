#include "RmsStdMessage.h"

namespace Greis
{
    RmsStdMessage::RmsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RmsStdMessage::ToString() const
    {
        return toString("RmsStdMessage");
    }

    QByteArray RmsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
