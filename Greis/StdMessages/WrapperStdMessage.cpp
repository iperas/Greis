#include "WrapperStdMessage.h"

namespace Greis
{
    WrapperStdMessage::WrapperStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string WrapperStdMessage::ToString() const
    {
        return toString("WrapperStdMessage");
    }

    QByteArray WrapperStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
