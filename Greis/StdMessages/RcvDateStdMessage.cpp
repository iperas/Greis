#include "RcvDateStdMessage.h"
#include <cassert>

namespace Greis
{
    RcvDateStdMessage::RcvDateStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _year);
        p_message += sizeof(_year);
        _serializer.Deserialize(p_message, _month);
        p_message += sizeof(_month);
        _serializer.Deserialize(p_message, _day);
        p_message += sizeof(_day);
        _serializer.Deserialize(p_message, _base);
        p_message += sizeof(_base);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string RcvDateStdMessage::ToString() const
    {
        return toString("RcvDateStdMessage");
    }
    bool RcvDateStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray RcvDateStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_year, result);
        _serializer.Serialize(_month, result);
        _serializer.Serialize(_day, result);
        _serializer.Serialize(_base, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
