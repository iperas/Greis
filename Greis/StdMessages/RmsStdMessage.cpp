#include "RmsStdMessage.h"
#include <cassert>

namespace Greis
{
    RmsStdMessage::RmsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _hpos);
        p_message += sizeof(_hpos);
        _serializer.Deserialize(p_message, _vpos);
        p_message += sizeof(_vpos);
        _serializer.Deserialize(p_message, _hvel);
        p_message += sizeof(_hvel);
        _serializer.Deserialize(p_message, _vvel);
        p_message += sizeof(_vvel);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    RmsStdMessage::RmsStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string RmsStdMessage::ToString() const
    {
        return toString("RmsStdMessage");
    }
    bool RmsStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray RmsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_hpos, result);
        _serializer.Serialize(_vpos, result);
        _serializer.Serialize(_hvel, result);
        _serializer.Serialize(_vvel, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
