#include "SatNumbersStdMessage.h"

namespace Greis
{
    SatNumbersStdMessage::SatNumbersStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string SatNumbersStdMessage::ToString() const
    {
        return toString("SatNumbersStdMessage");
    }

    QByteArray SatNumbersStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
