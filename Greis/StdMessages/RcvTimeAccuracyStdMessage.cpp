#include "RcvTimeAccuracyStdMessage.h"

namespace Greis
{
    RcvTimeAccuracyStdMessage::RcvTimeAccuracyStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string RcvTimeAccuracyStdMessage::ToString() const
    {
        return toString("RcvTimeAccuracyStdMessage");
    }

    QByteArray RcvTimeAccuracyStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
