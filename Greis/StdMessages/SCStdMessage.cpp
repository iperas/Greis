#include "SCStdMessage.h"

namespace Greis
{
    SCStdMessage::SCStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string SCStdMessage::ToString() const
    {
        return toString("SCStdMessage");
    }

    QByteArray SCStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
