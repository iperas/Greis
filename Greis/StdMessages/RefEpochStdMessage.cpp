#include "RefEpochStdMessage.h"
#include <cassert>

namespace Greis
{
    RefEpochStdMessage::RefEpochStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _sample);
        p_message += sizeof(_sample);
        _serializer.Deserialize(p_message, _scale);
        p_message += sizeof(_scale);
        _serializer.Deserialize(p_message, _reftime);
        p_message += sizeof(_reftime);
        _serializer.Deserialize(p_message, _crc16);
        p_message += sizeof(_crc16);
        
        assert(p_message - pc_message == p_length);
    }

    std::string RefEpochStdMessage::ToString() const
    {
        return toString("RefEpochStdMessage");
    }
    bool RefEpochStdMessage::Validate() const
    {
        if (!Validate())
        {
            return false;
        }

        return true;
    }

    QByteArray RefEpochStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_sample, result);
        _serializer.Serialize(_scale, result);
        _serializer.Serialize(_reftime, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
