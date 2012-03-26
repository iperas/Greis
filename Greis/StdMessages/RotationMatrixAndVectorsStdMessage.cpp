#include "RotationMatrixAndVectorsStdMessage.h"

namespace Greis
{
    RotationMatrixAndVectorsStdMessage::RotationMatrixAndVectorsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RotationMatrixAndVectorsStdMessage::ToString() const
    {
        return toString("RotationMatrixAndVectorsStdMessage");
    }

    QByteArray RotationMatrixAndVectorsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
