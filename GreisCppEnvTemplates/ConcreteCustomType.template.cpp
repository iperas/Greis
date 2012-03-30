#include "${ClassName}.h"

namespace Greis
{
    ${ClassName}::${ClassName}( char* p_message, int p_length ) 
        : _size(p_length)
    {
        // ${DeserializationConstructorStub}
    }

    QByteArray ${ClassName}::ToByteArray() const
    {
        QByteArray result;

        // ${ToByteArrayStub}
        
        return result;
    }
}
