#include "GloNavDataStdMessage.h"

namespace Greis
{
    GloNavDataStdMessage::GloNavDataStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GloNavDataStdMessage::ToString() const
    {
        return toString("GloNavDataStdMessage");
    }

    QByteArray GloNavDataStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
