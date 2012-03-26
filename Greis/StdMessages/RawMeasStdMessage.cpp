#include "RawMeasStdMessage.h"

namespace Greis
{
    RawMeasStdMessage::RawMeasStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RawMeasStdMessage::ToString() const
    {
        return toString("RawMeasStdMessage");
    }

    QByteArray RawMeasStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
