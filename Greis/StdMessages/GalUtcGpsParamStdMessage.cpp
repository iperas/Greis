#include "GalUtcGpsParamStdMessage.h"

namespace Greis
{
    GalUtcGpsParamStdMessage::GalUtcGpsParamStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string GalUtcGpsParamStdMessage::ToString() const
    {
        return toString("GalUtcGpsParamStdMessage");
    }

    QByteArray GalUtcGpsParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
