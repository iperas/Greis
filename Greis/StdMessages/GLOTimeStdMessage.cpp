#include "GLOTimeStdMessage.h"
#include <cassert>

namespace Greis
{
    GLOTimeStdMessage::GLOTimeStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _tod);
        p_message += sizeof(_tod);
        _serializer.Deserialize(p_message, _dn);
        p_message += sizeof(_dn);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GLOTimeStdMessage::ToString() const
    {
        return toString("GLOTimeStdMessage");
    }

    QByteArray GLOTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_tod, result);
        _serializer.Serialize(_dn, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
