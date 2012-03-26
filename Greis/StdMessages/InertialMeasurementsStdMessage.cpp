#include "InertialMeasurementsStdMessage.h"

namespace Greis
{
    InertialMeasurementsStdMessage::InertialMeasurementsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string InertialMeasurementsStdMessage::ToString() const
    {
        return toString("InertialMeasurementsStdMessage");
    }

    QByteArray InertialMeasurementsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
