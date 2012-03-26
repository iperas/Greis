#include "WaasUtcParamStdMessage.h"

namespace Greis
{
    WaasUtcParamStdMessage::WaasUtcParamStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string WaasUtcParamStdMessage::ToString() const
    {
        return toString("WaasUtcParamStdMessage");
    }

    QByteArray WaasUtcParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
