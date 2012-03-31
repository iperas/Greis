#include "SmoothCustomType.h"
#include <cassert>

namespace Greis
{
    SmoothCustomType::SmoothCustomType( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _value);
        p_message += sizeof(_value);
        _serializer.Deserialize(p_message, _interval);
        p_message += sizeof(_interval);
        
        assert(p_message - pc_message == p_length);
    }

    QByteArray SmoothCustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_value, result);
        _serializer.Serialize(_interval, result);
        
        assert(result.size() == Size());
        return result;
    }
}
