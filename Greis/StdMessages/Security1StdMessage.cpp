#include "Security1StdMessage.h"
#include <cassert>

namespace Greis
{
    Security1StdMessage::Security1StdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * 6, _data);
        p_message += sizeof(std::vector<Types::u1>::value_type) * 6;
        _serializer.Deserialize(p_message, _crc16);
        p_message += sizeof(_crc16);
        
        assert(p_message - pc_message == p_length);
    }

    std::string Security1StdMessage::ToString() const
    {
        return toString("Security1StdMessage");
    }
    bool Security1StdMessage::Validate() const
    {
        if (!Validate())
        {
            return false;
        }

        return true;
    }

    QByteArray Security1StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_data, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
