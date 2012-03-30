#include "ExtEventStdMessage.h"

namespace Greis
{
    ExtEventStdMessage::ExtEventStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string ExtEventStdMessage::ToString() const
    {
        return toString("ExtEventStdMessage");
    }

    QByteArray ExtEventStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
