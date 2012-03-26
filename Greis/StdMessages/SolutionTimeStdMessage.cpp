#include "SolutionTimeStdMessage.h"

namespace Greis
{
    SolutionTimeStdMessage::SolutionTimeStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string SolutionTimeStdMessage::ToString() const
    {
        return toString("SolutionTimeStdMessage");
    }

    QByteArray SolutionTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
