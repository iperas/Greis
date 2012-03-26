#include "SatElevationStdMessage.h"

namespace Greis
{
    SatElevationStdMessage::SatElevationStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string SatElevationStdMessage::ToString() const
    {
        return toString("SatElevationStdMessage");
    }

    QByteArray SatElevationStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
