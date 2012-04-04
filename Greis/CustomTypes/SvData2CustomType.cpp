#include "SvData2CustomType.h"
#include <cassert>

namespace Greis
{
    SvData2CustomType::SvData2CustomType( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        throw ProjectBase::NotImplementedException();
        
        assert(p_message - pc_message == p_length);
    }
    
    SvData2CustomType::SvData2CustomType( int p_size ) 
        : _size(p_size)
    {
    }

    QByteArray SvData2CustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_header, result);
        _serializer.Serialize(_slot, result);
        
        assert(result.size() == Size());
        return result;
    }
}
