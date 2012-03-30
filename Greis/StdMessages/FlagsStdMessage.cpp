#include "FlagsStdMessage.h"

namespace Greis
{
    FlagsStdMessage::FlagsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string FlagsStdMessage::ToString() const
    {
        return toString("FlagsStdMessage");
    }

    QByteArray FlagsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
