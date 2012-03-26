#include "GalUtcGpsParamStdMessage.h"

namespace Greis
{
    GalUtcGpsParamStdMessage::GalUtcGpsParamStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GalUtcGpsParamStdMessage::ToString() const
    {
        return toString("GalUtcGpsParamStdMessage");
    }

    QByteArray GalUtcGpsParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
