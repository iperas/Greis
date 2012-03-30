#include "RefEpochStdMessage.h"

namespace Greis
{
    RefEpochStdMessage::RefEpochStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RefEpochStdMessage::ToString() const
    {
        return toString("RefEpochStdMessage");
    }

    QByteArray RefEpochStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
