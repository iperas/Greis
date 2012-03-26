#include "VelStdMessage.h"

namespace Greis
{
    VelStdMessage::VelStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string VelStdMessage::ToString() const
    {
        return toString("VelStdMessage");
    }

    QByteArray VelStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
