#include "RotationMatrixStdMessage.h"

namespace Greis
{
    RotationMatrixStdMessage::RotationMatrixStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RotationMatrixStdMessage::ToString() const
    {
        return toString("RotationMatrixStdMessage");
    }

    QByteArray RotationMatrixStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
