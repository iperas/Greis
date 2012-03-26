#include "VelCovStdMessage.h"

namespace Greis
{
    VelCovStdMessage::VelCovStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string VelCovStdMessage::ToString() const
    {
        return toString("VelCovStdMessage");
    }

    QByteArray VelCovStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
