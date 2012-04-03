#include "WrapperStdMessage.h"
#include <cassert>

namespace Greis
{
    WrapperStdMessage::WrapperStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 3) / 1;

        _serializer.Deserialize(p_message, _idField);
        p_message += sizeof(_idField);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields, _data);
        p_message += sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, 2, _cs);
        p_message += 2;
        
        assert(p_message - pc_message == p_length);
    }
    
    WrapperStdMessage::WrapperStdMessage( const std::string& p_id, int p_bodySize ) 
        : _id(p_id), _bodySize(p_bodySize)
    {
    }

    std::string WrapperStdMessage::ToString() const
    {
        return toString("WrapperStdMessage");
    }
    bool WrapperStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Ascii(message.data(), message.size());
    }

    QByteArray WrapperStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_idField, result);
        _serializer.Serialize(_data, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
