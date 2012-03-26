#include "MsgFmtStdMessage.h"

namespace Greis
{
    MsgFmtStdMessage::MsgFmtStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string MsgFmtStdMessage::ToString() const
    {
        return toString("MsgFmtStdMessage");
    }

    QByteArray MsgFmtStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
