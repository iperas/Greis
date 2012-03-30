#include "WAASAlmanacStdMessage.h"

namespace Greis
{
    WAASAlmanacStdMessage::WAASAlmanacStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string WAASAlmanacStdMessage::ToString() const
    {
        return toString("WAASAlmanacStdMessage");
    }

    QByteArray WAASAlmanacStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
