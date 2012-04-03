#include "GloUtcGpsParamStdMessage.h"
#include <cassert>

namespace Greis
{
    GloUtcGpsParamStdMessage::GloUtcGpsParamStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _tauSys);
        p_message += sizeof(_tauSys);
        _serializer.Deserialize(p_message, _tauGps);
        p_message += sizeof(_tauGps);
        _serializer.Deserialize(p_message, _B1);
        p_message += sizeof(_B1);
        _serializer.Deserialize(p_message, _B2);
        p_message += sizeof(_B2);
        _serializer.Deserialize(p_message, _KP);
        p_message += sizeof(_KP);
        _serializer.Deserialize(p_message, _N4);
        p_message += sizeof(_N4);
        _serializer.Deserialize(p_message, _Dn);
        p_message += sizeof(_Dn);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    GloUtcGpsParamStdMessage::GloUtcGpsParamStdMessage( const std::string& p_id, int p_bodySize ) 
        : _id(p_id), _bodySize(p_bodySize)
    {
    }

    std::string GloUtcGpsParamStdMessage::ToString() const
    {
        return toString("GloUtcGpsParamStdMessage");
    }
    bool GloUtcGpsParamStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray GloUtcGpsParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_tauSys, result);
        _serializer.Serialize(_tauGps, result);
        _serializer.Serialize(_B1, result);
        _serializer.Serialize(_B2, result);
        _serializer.Serialize(_KP, result);
        _serializer.Serialize(_N4, result);
        _serializer.Serialize(_Dn, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
