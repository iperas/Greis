#include "WAASRawMessageStdMessage.h"
#include <cassert>

namespace Greis
{
    WAASRawMessageStdMessage::WAASRawMessageStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _prn);
        p_message += sizeof(_prn);
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _reserv);
        p_message += sizeof(_reserv);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * 32, _data);
        p_message += sizeof(std::vector<Types::u1>::value_type) * 32;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string WAASRawMessageStdMessage::ToString() const
    {
        return toString("WAASRawMessageStdMessage");
    }
    bool WAASRawMessageStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray WAASRawMessageStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_prn, result);
        _serializer.Serialize(_time, result);
        _serializer.Serialize(_reserv, result);
        _serializer.Serialize(_data, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
