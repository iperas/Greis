#include "ExtSpecDataCustomType.h"
#include <cassert>

namespace Greis
{
    ExtSpecDataCustomType::ExtSpecDataCustomType( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        throw ProjectBase::NotImplementedException();
        
        assert(p_message - pc_message == p_length);
    }
    
    ExtSpecDataCustomType::ExtSpecDataCustomType( int p_size ) 
        : _size(p_size)
    {
    }

    QByteArray ExtSpecDataCustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_spec, result);
        _serializer.Serialize(_agcmin, result);
        _serializer.Serialize(_agcmax, result);
        
        assert(result.size() == Size());
        return result;
    }
}
