#include "SCPStdMessage.h"

namespace Greis
{
    SCPStdMessage::SCPStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string SCPStdMessage::ToString() const
    {
        return toString("SCPStdMessage");
    }

    QByteArray SCPStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
