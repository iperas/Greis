#include "SPRStdMessage.h"
#include <cassert>

namespace Greis
{
    SPRStdMessage::SPRStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 4;

        _serializer.Deserialize(p_message, sizeof(std::vector<Types::i4>::value_type) * arraySizeInUniformFillFields, _spr);
        p_message += sizeof(std::vector<Types::i4>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    SPRStdMessage::SPRStdMessage( const std::string& p_id, int p_bodySize ) 
        : _id(p_id), _bodySize(p_bodySize)
    {
    }

    std::string SPRStdMessage::ToString() const
    {
        return toString("SPRStdMessage");
    }
    bool SPRStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray SPRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_spr, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
