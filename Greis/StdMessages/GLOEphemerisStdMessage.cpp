#include "GLOEphemerisStdMessage.h"
#include <cassert>

namespace Greis
{
    GLOEphemerisStdMessage::GLOEphemerisStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _sv);
        p_message += sizeof(_sv);
        _serializer.Deserialize(p_message, _frqNum);
        p_message += sizeof(_frqNum);
        _serializer.Deserialize(p_message, _dne);
        p_message += sizeof(_dne);
        _serializer.Deserialize(p_message, _tk);
        p_message += sizeof(_tk);
        _serializer.Deserialize(p_message, _tb);
        p_message += sizeof(_tb);
        _serializer.Deserialize(p_message, _health);
        p_message += sizeof(_health);
        _serializer.Deserialize(p_message, _age);
        p_message += sizeof(_age);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f8>::value_type) * 3, _r);
        p_message += sizeof(std::vector<Types::f8>::value_type) * 3;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * 3, _v);
        p_message += sizeof(std::vector<Types::f4>::value_type) * 3;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * 3, _w);
        p_message += sizeof(std::vector<Types::f4>::value_type) * 3;
        _serializer.Deserialize(p_message, _tauSys);
        p_message += sizeof(_tauSys);
        _serializer.Deserialize(p_message, _tau);
        p_message += sizeof(_tau);
        _serializer.Deserialize(p_message, _gamma);
        p_message += sizeof(_gamma);
        _serializer.Deserialize(p_message, _fDelTauN);
        p_message += sizeof(_fDelTauN);
        _serializer.Deserialize(p_message, _nFt);
        p_message += sizeof(_nFt);
        _serializer.Deserialize(p_message, _nN4);
        p_message += sizeof(_nN4);
        _serializer.Deserialize(p_message, _flags2);
        p_message += sizeof(_flags2);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GLOEphemerisStdMessage::ToString() const
    {
        return toString("GLOEphemerisStdMessage");
    }
    bool GLOEphemerisStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray GLOEphemerisStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_sv, result);
        _serializer.Serialize(_frqNum, result);
        _serializer.Serialize(_dne, result);
        _serializer.Serialize(_tk, result);
        _serializer.Serialize(_tb, result);
        _serializer.Serialize(_health, result);
        _serializer.Serialize(_age, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_r, result);
        _serializer.Serialize(_v, result);
        _serializer.Serialize(_w, result);
        _serializer.Serialize(_tauSys, result);
        _serializer.Serialize(_tau, result);
        _serializer.Serialize(_gamma, result);
        _serializer.Serialize(_fDelTauN, result);
        _serializer.Serialize(_nFt, result);
        _serializer.Serialize(_nN4, result);
        _serializer.Serialize(_flags2, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
