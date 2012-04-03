#include "PosStdMessage.h"
#include <cassert>

namespace Greis
{
    PosStdMessage::PosStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _x);
        p_message += sizeof(_x);
        _serializer.Deserialize(p_message, _y);
        p_message += sizeof(_y);
        _serializer.Deserialize(p_message, _z);
        p_message += sizeof(_z);
        _serializer.Deserialize(p_message, _sigma);
        p_message += sizeof(_sigma);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    PosStdMessage::PosStdMessage( const std::string& p_id, int p_bodySize ) 
        : _id(p_id), _bodySize(p_bodySize)
    {
    }

    std::string PosStdMessage::ToString() const
    {
        return toString("PosStdMessage");
    }
    bool PosStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray PosStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_x, result);
        _serializer.Serialize(_y, result);
        _serializer.Serialize(_z, result);
        _serializer.Serialize(_sigma, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
