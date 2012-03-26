#include "GloUtcGpsParamStdMessage.h"

namespace Greis
{
    GloUtcGpsParamStdMessage::GloUtcGpsParamStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string GloUtcGpsParamStdMessage::ToString() const
    {
        return toString("GloUtcGpsParamStdMessage");
    }

    QByteArray GloUtcGpsParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
