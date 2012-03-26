#include "DPStdMessage.h"

namespace Greis
{
    DPStdMessage::DPStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string DPStdMessage::ToString() const
    {
        return toString("DPStdMessage");
    }

    QByteArray DPStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
