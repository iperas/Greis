#include "RPRStdMessage.h"

namespace Greis
{
    RPRStdMessage::RPRStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RPRStdMessage::ToString() const
    {
        return toString("RPRStdMessage");
    }

    QByteArray RPRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
