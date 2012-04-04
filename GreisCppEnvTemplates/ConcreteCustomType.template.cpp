#include "${ClassName}.h"
#include <cassert>

namespace Greis
{
    ${ClassName}::${ClassName}( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        // ${DeserializationConstructorStub}
        
        assert(p_message - pc_message == p_length);
    }
    
    ${ClassName}::${ClassName}( int p_size ) 
        : _size(p_size)
    {
    }

    QByteArray ${ClassName}::ToByteArray() const
    {
        QByteArray result;

        // ${ToByteArrayStub}
        
        assert(result.size() == Size());
        return result;
    }
}
