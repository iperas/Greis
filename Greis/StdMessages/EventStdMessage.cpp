#include "EventStdMessage.h"

namespace Greis
{
    EventStdMessage::EventStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string EventStdMessage::ToString() const
    {
        return toString("EventStdMessage");
    }

    QByteArray EventStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
