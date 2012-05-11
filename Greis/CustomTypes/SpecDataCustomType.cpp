#include "SpecDataCustomType.h"
#include <cassert>

namespace Greis
{
    SpecDataCustomType::SpecDataCustomType( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        throw ProjectBase::NotImplementedException();
        
        assert(p_message - pc_message == p_length);
    }
    
    SpecDataCustomType::SpecDataCustomType( int p_size ) 
        : _size(p_size)
    {
    }

    QByteArray SpecDataCustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_spec, result);
        
        assert(result.size() == Size());
        return result;
    }
}
