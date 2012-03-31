#include "MsgFmtStdMessage.h"
#include <cassert>

namespace Greis
{
    MsgFmtStdMessage::MsgFmtStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 2, _idField);
        p_message += 2;
        _serializer.Deserialize(p_message, 2, _majorVer);
        p_message += 2;
        _serializer.Deserialize(p_message, 2, _minorVer);
        p_message += 2;
        _serializer.Deserialize(p_message, _order);
        p_message += sizeof(_order);
        _serializer.Deserialize(p_message, 2, _cs);
        p_message += 2;
        
        assert(p_message - pc_message == p_length);
    }

    std::string MsgFmtStdMessage::ToString() const
    {
        return toString("MsgFmtStdMessage");
    }
    bool MsgFmtStdMessage::Validate() const
    {
        if (!Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Ascii(message.data(), message.size());
    }

    QByteArray MsgFmtStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_idField, result);
        _serializer.Serialize(_majorVer, result);
        _serializer.Serialize(_minorVer, result);
        _serializer.Serialize(_order, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
