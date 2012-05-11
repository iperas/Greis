#include "SBASAlmanacStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    SBASAlmanacStdMessage::SBASAlmanacStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _waasPrn);
        p_message += sizeof(_waasPrn);
        _serializer.Deserialize(p_message, _gpsPrn);
        p_message += sizeof(_gpsPrn);
        _serializer.Deserialize(p_message, _idField);
        p_message += sizeof(_idField);
        _serializer.Deserialize(p_message, _healthS);
        p_message += sizeof(_healthS);
        _serializer.Deserialize(p_message, _tod);
        p_message += sizeof(_tod);
        _serializer.Deserialize(p_message, _xg);
        p_message += sizeof(_xg);
        _serializer.Deserialize(p_message, _yg);
        p_message += sizeof(_yg);
        _serializer.Deserialize(p_message, _zg);
        p_message += sizeof(_zg);
        _serializer.Deserialize(p_message, _vxg);
        p_message += sizeof(_vxg);
        _serializer.Deserialize(p_message, _vyg);
        p_message += sizeof(_vyg);
        _serializer.Deserialize(p_message, _vzg);
        p_message += sizeof(_vzg);
        _serializer.Deserialize(p_message, _tow);
        p_message += sizeof(_tow);
        _serializer.Deserialize(p_message, _wn);
        p_message += sizeof(_wn);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    SBASAlmanacStdMessage::SBASAlmanacStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string SBASAlmanacStdMessage::ToString() const
    {
        return toString("SBASAlmanacStdMessage");
    }
    
    bool SBASAlmanacStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void SBASAlmanacStdMessage::RecalculateChecksum()
    {
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray SBASAlmanacStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_waasPrn, result);
        _serializer.Serialize(_gpsPrn, result);
        _serializer.Serialize(_idField, result);
        _serializer.Serialize(_healthS, result);
        _serializer.Serialize(_tod, result);
        _serializer.Serialize(_xg, result);
        _serializer.Serialize(_yg, result);
        _serializer.Serialize(_zg, result);
        _serializer.Serialize(_vxg, result);
        _serializer.Serialize(_vyg, result);
        _serializer.Serialize(_vzg, result);
        _serializer.Serialize(_tow, result);
        _serializer.Serialize(_wn, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
