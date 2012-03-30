#include "ParamsStdMessage.h"

namespace Greis
{
    ParamsStdMessage::ParamsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string ParamsStdMessage::ToString() const
    {
        return toString("ParamsStdMessage");
    }

    QByteArray ParamsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
