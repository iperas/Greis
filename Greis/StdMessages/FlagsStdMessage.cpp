#include "FlagsStdMessage.h"
#include <cassert>

namespace Greis
{
    FlagsStdMessage::FlagsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 2;

        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u2>::value_type) * arraySizeInUniformFillFields, _flags);
        p_message += sizeof(std::vector<Types::u2>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string FlagsStdMessage::ToString() const
    {
        return toString("FlagsStdMessage");
    }
    bool FlagsStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray FlagsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
