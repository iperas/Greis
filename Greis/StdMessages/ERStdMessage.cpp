#include "ERStdMessage.h"

namespace Greis
{
    ERStdMessage::ERStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string ERStdMessage::ToString() const
    {
        return toString("ERStdMessage");
    }

    QByteArray ERStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
