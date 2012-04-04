#include "WaasUtcParamStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    WaasUtcParamStdMessage::WaasUtcParamStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 23, _utc);
        p_message += 23;
        _serializer.Deserialize(p_message, _utcsi);
        p_message += sizeof(_utcsi);
        _serializer.Deserialize(p_message, _tow);
        p_message += sizeof(_tow);
        _serializer.Deserialize(p_message, _wn);
        p_message += sizeof(_wn);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    WaasUtcParamStdMessage::WaasUtcParamStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string WaasUtcParamStdMessage::ToString() const
    {
        return toString("WaasUtcParamStdMessage");
    }
    
    bool WaasUtcParamStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void WaasUtcParamStdMessage::RecalculateChecksum()
    {
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray WaasUtcParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_utc, result);
        _serializer.Serialize(_utcsi, result);
        _serializer.Serialize(_tow, result);
        _serializer.Serialize(_wn, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
