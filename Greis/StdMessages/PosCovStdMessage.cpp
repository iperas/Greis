#include "PosCovStdMessage.h"
#include <cassert>

namespace Greis
{
    PosCovStdMessage::PosCovStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _xx);
        p_message += sizeof(_xx);
        _serializer.Deserialize(p_message, _yy);
        p_message += sizeof(_yy);
        _serializer.Deserialize(p_message, _zz);
        p_message += sizeof(_zz);
        _serializer.Deserialize(p_message, _tt);
        p_message += sizeof(_tt);
        _serializer.Deserialize(p_message, _xy);
        p_message += sizeof(_xy);
        _serializer.Deserialize(p_message, _xz);
        p_message += sizeof(_xz);
        _serializer.Deserialize(p_message, _xt);
        p_message += sizeof(_xt);
        _serializer.Deserialize(p_message, _yz);
        p_message += sizeof(_yz);
        _serializer.Deserialize(p_message, _yt);
        p_message += sizeof(_yt);
        _serializer.Deserialize(p_message, _zt);
        p_message += sizeof(_zt);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string PosCovStdMessage::ToString() const
    {
        return toString("PosCovStdMessage");
    }

    QByteArray PosCovStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_xx, result);
        _serializer.Serialize(_yy, result);
        _serializer.Serialize(_zz, result);
        _serializer.Serialize(_tt, result);
        _serializer.Serialize(_xy, result);
        _serializer.Serialize(_xz, result);
        _serializer.Serialize(_xt, result);
        _serializer.Serialize(_yz, result);
        _serializer.Serialize(_yt, result);
        _serializer.Serialize(_zt, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
