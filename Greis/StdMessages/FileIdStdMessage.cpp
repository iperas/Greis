#include "FileIdStdMessage.h"

namespace Greis
{
    FileIdStdMessage::FileIdStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string FileIdStdMessage::ToString() const
    {
        return toString("FileIdStdMessage");
    }

    QByteArray FileIdStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
