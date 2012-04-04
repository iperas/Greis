#include "HeaderCustomType.h"
#include <cassert>

namespace Greis
{
    HeaderCustomType::HeaderCustomType( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _refrange);
        p_message += sizeof(_refrange);
        _serializer.Deserialize(p_message, _usi);
        p_message += sizeof(_usi);
        _serializer.Deserialize(p_message, _num);
        p_message += sizeof(_num);
        
        assert(p_message - pc_message == p_length);
    }
    
    HeaderCustomType::HeaderCustomType( int p_size ) 
        : _size(p_size)
    {
    }

    QByteArray HeaderCustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_refrange, result);
        _serializer.Serialize(_usi, result);
        _serializer.Serialize(_num, result);
        
        assert(result.size() == Size());
        return result;
    }
}
