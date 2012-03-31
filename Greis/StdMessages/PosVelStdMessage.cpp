#include "PosVelStdMessage.h"
#include <cassert>

namespace Greis
{
    PosVelStdMessage::PosVelStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _x);
        p_message += sizeof(_x);
        _serializer.Deserialize(p_message, _y);
        p_message += sizeof(_y);
        _serializer.Deserialize(p_message, _z);
        p_message += sizeof(_z);
        _serializer.Deserialize(p_message, _pSigma);
        p_message += sizeof(_pSigma);
        _serializer.Deserialize(p_message, _vx);
        p_message += sizeof(_vx);
        _serializer.Deserialize(p_message, _vy);
        p_message += sizeof(_vy);
        _serializer.Deserialize(p_message, _vz);
        p_message += sizeof(_vz);
        _serializer.Deserialize(p_message, _vSigma);
        p_message += sizeof(_vSigma);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string PosVelStdMessage::ToString() const
    {
        return toString("PosVelStdMessage");
    }
    bool PosVelStdMessage::Validate() const
    {
        if (!Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray PosVelStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_x, result);
        _serializer.Serialize(_y, result);
        _serializer.Serialize(_z, result);
        _serializer.Serialize(_pSigma, result);
        _serializer.Serialize(_vx, result);
        _serializer.Serialize(_vy, result);
        _serializer.Serialize(_vz, result);
        _serializer.Serialize(_vSigma, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
