#include "RotationAnglesStdMessage.h"
#include <cassert>

namespace Greis
{
    RotationAnglesStdMessage::RotationAnglesStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _pitch);
        p_message += sizeof(_pitch);
        _serializer.Deserialize(p_message, _roll);
        p_message += sizeof(_roll);
        _serializer.Deserialize(p_message, _heading);
        p_message += sizeof(_heading);
        _serializer.Deserialize(p_message, _pitchRms);
        p_message += sizeof(_pitchRms);
        _serializer.Deserialize(p_message, _rollRms);
        p_message += sizeof(_rollRms);
        _serializer.Deserialize(p_message, _headingRms);
        p_message += sizeof(_headingRms);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    RotationAnglesStdMessage::RotationAnglesStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string RotationAnglesStdMessage::ToString() const
    {
        return toString("RotationAnglesStdMessage");
    }
    bool RotationAnglesStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray RotationAnglesStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_time, result);
        _serializer.Serialize(_pitch, result);
        _serializer.Serialize(_roll, result);
        _serializer.Serialize(_heading, result);
        _serializer.Serialize(_pitchRms, result);
        _serializer.Serialize(_rollRms, result);
        _serializer.Serialize(_headingRms, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
