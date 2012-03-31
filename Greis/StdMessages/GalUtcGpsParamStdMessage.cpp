#include "GalUtcGpsParamStdMessage.h"
#include <cassert>

namespace Greis
{
    GalUtcGpsParamStdMessage::GalUtcGpsParamStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 23, _utc);
        p_message += 23;
        _serializer.Deserialize(p_message, _a0g);
        p_message += sizeof(_a0g);
        _serializer.Deserialize(p_message, _a1g);
        p_message += sizeof(_a1g);
        _serializer.Deserialize(p_message, _t0g);
        p_message += sizeof(_t0g);
        _serializer.Deserialize(p_message, _wn0g);
        p_message += sizeof(_wn0g);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GalUtcGpsParamStdMessage::ToString() const
    {
        return toString("GalUtcGpsParamStdMessage");
    }

    QByteArray GalUtcGpsParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_utc, result);
        _serializer.Serialize(_a0g, result);
        _serializer.Serialize(_a1g, result);
        _serializer.Serialize(_t0g, result);
        _serializer.Serialize(_wn0g, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
