#include "SRDPStdMessage.h"

namespace Greis
{
    SRDPStdMessage::SRDPStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string SRDPStdMessage::ToString() const
    {
        return toString("SRDPStdMessage");
    }

    QByteArray SRDPStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
