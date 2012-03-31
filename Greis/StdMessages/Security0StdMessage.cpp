#include "Security0StdMessage.h"
#include <cassert>

namespace Greis
{
    Security0StdMessage::Security0StdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, sizeof(_data) * 5, _data);
        p_message += sizeof(_data) * 5;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string Security0StdMessage::ToString() const
    {
        return toString("Security0StdMessage");
    }

    QByteArray Security0StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_data, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
