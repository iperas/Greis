#include "ExtEventStdMessage.h"
#include <cassert>

namespace Greis
{
    ExtEventStdMessage::ExtEventStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _ms);
        p_message += sizeof(_ms);
        _serializer.Deserialize(p_message, _ns);
        p_message += sizeof(_ns);
        _serializer.Deserialize(p_message, _timeScale);
        p_message += sizeof(_timeScale);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string ExtEventStdMessage::ToString() const
    {
        return toString("ExtEventStdMessage");
    }

    QByteArray ExtEventStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_ms, result);
        _serializer.Serialize(_ns, result);
        _serializer.Serialize(_timeScale, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
