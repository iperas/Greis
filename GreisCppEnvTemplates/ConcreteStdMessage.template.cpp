#include "${ClassName}.h"
#include <cassert>

namespace Greis
{
    ${ClassName}::${ClassName}( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        // ${DeserializationConstructorStub}
        
        assert(p_message - pc_message == p_length);
    }
    
    ${ClassName}::${ClassName}( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string ${ClassName}::ToString() const
    {
        return toString("${ClassName}");
    }
    bool ${ClassName}::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }// ${ValidateStub}
    }

    QByteArray ${ClassName}::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        assert(result.size() == Size());
        return result;
    }
}
