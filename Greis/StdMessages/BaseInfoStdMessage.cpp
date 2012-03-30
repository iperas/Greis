#include "BaseInfoStdMessage.h"

namespace Greis
{
    BaseInfoStdMessage::BaseInfoStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string BaseInfoStdMessage::ToString() const
    {
        return toString("BaseInfoStdMessage");
    }

    QByteArray BaseInfoStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
