#include "DopsStdMessage.h"
#include <cassert>

namespace Greis
{
    DopsStdMessage::DopsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _hdop);
        p_message += sizeof(_hdop);
        _serializer.Deserialize(p_message, _vdop);
        p_message += sizeof(_vdop);
        _serializer.Deserialize(p_message, _tdop);
        p_message += sizeof(_tdop);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    DopsStdMessage::DopsStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string DopsStdMessage::ToString() const
    {
        return toString("DopsStdMessage");
    }
    bool DopsStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray DopsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_hdop, result);
        _serializer.Serialize(_vdop, result);
        _serializer.Serialize(_tdop, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
