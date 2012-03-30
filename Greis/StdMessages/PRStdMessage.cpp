#include "PRStdMessage.h"

namespace Greis
{
    PRStdMessage::PRStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string PRStdMessage::ToString() const
    {
        return toString("PRStdMessage");
    }

    QByteArray PRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
