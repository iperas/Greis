#include "SatIndexStdMessage.h"

namespace Greis
{
    SatIndexStdMessage::SatIndexStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string SatIndexStdMessage::ToString() const
    {
        return toString("SatIndexStdMessage");
    }

    QByteArray SatIndexStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
