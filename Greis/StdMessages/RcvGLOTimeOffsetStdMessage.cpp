#include "RcvGLOTimeOffsetStdMessage.h"

namespace Greis
{
    RcvGLOTimeOffsetStdMessage::RcvGLOTimeOffsetStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string RcvGLOTimeOffsetStdMessage::ToString() const
    {
        return toString("RcvGLOTimeOffsetStdMessage");
    }

    QByteArray RcvGLOTimeOffsetStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
