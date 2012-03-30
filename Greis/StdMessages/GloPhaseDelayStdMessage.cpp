#include "GloPhaseDelayStdMessage.h"

namespace Greis
{
    GloPhaseDelayStdMessage::GloPhaseDelayStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GloPhaseDelayStdMessage::ToString() const
    {
        return toString("GloPhaseDelayStdMessage");
    }

    QByteArray GloPhaseDelayStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
