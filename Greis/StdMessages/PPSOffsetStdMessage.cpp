#include "PPSOffsetStdMessage.h"

namespace Greis
{
    PPSOffsetStdMessage::PPSOffsetStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string PPSOffsetStdMessage::ToString() const
    {
        return toString("PPSOffsetStdMessage");
    }

    QByteArray PPSOffsetStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
