#include "BaseLineStdMessage.h"

namespace Greis
{
    BaseLineStdMessage::BaseLineStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string BaseLineStdMessage::ToString() const
    {
        return toString("BaseLineStdMessage");
    }

    QByteArray BaseLineStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
