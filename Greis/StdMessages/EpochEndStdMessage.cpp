#include "EpochEndStdMessage.h"

namespace Greis
{
    EpochEndStdMessage::EpochEndStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string EpochEndStdMessage::ToString() const
    {
        return toString("EpochEndStdMessage");
    }

    QByteArray EpochEndStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
