#include "EpochTimeStdMessage.h"

namespace Greis
{
    EpochTimeStdMessage::EpochTimeStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string EpochTimeStdMessage::ToString() const
    {
        return toString("EpochTimeStdMessage");
    }

    QByteArray EpochTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
