#include "CPStdMessage.h"

namespace Greis
{
    CPStdMessage::CPStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string CPStdMessage::ToString() const
    {
        return toString("CPStdMessage");
    }

    QByteArray CPStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
