#include "RcvTimeOffsAtPPSStdMessage.h"

namespace Greis
{
    RcvTimeOffsAtPPSStdMessage::RcvTimeOffsAtPPSStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RcvTimeOffsAtPPSStdMessage::ToString() const
    {
        return toString("RcvTimeOffsAtPPSStdMessage");
    }

    QByteArray RcvTimeOffsAtPPSStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
