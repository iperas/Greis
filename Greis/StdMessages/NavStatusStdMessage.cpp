#include "NavStatusStdMessage.h"

namespace Greis
{
    NavStatusStdMessage::NavStatusStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string NavStatusStdMessage::ToString() const
    {
        return toString("NavStatusStdMessage");
    }

    QByteArray NavStatusStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
