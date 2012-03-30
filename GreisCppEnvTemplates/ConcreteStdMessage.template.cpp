#include "${ClassName}.h"

namespace Greis
{
    ${ClassName}::${ClassName}( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string ${ClassName}::ToString() const
    {
        return toString("${ClassName}");
    }

    QByteArray ${ClassName}::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
