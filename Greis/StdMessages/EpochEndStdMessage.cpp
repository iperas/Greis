#include "EpochEndStdMessage.h"
#include <cassert>

namespace Greis
{
    EpochEndStdMessage::EpochEndStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    EpochEndStdMessage::EpochEndStdMessage( const std::string& p_id, int p_bodySize ) 
        : _id(p_id), _bodySize(p_bodySize)
    {
    }

    std::string EpochEndStdMessage::ToString() const
    {
        return toString("EpochEndStdMessage");
    }
    bool EpochEndStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray EpochEndStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
