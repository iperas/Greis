#include "EventStdMessage.h"
#include <cassert>

namespace Greis
{
    EventStdMessage::EventStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 6) / 1;

        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _type);
        p_message += sizeof(_type);
        _serializer.Deserialize(p_message, sizeof(_data) * arraySizeInUniformFillFields, _data);
        p_message += sizeof(_data) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string EventStdMessage::ToString() const
    {
        return toString("EventStdMessage");
    }

    QByteArray EventStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_time, result);
        _serializer.Serialize(_type, result);
        _serializer.Serialize(_data, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}