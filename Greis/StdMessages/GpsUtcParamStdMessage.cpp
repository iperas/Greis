#include "GpsUtcParamStdMessage.h"
#include <cassert>

namespace Greis
{
    GpsUtcParamStdMessage::GpsUtcParamStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 23, _utc);
        p_message += 23;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GpsUtcParamStdMessage::ToString() const
    {
        return toString("GpsUtcParamStdMessage");
    }

    QByteArray GpsUtcParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_utc, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
