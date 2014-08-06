#include "GLOEphemerisStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "Common/Logger.h"

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
        if (BodySize() == 103)
        {
            // Optional Data Block
            _serializer.Deserialize(p_message, _navType);
            p_message += sizeof(_navType);
            _serializer.Deserialize(p_message, _beta);
            p_message += sizeof(_beta);
            _serializer.Deserialize(p_message, _tauSysDot);
            p_message += sizeof(_tauSysDot);
            _serializer.Deserialize(p_message, _ec);
            p_message += sizeof(_ec);
            _serializer.Deserialize(p_message, _ee);
            p_message += sizeof(_ee);
            _serializer.Deserialize(p_message, _fc);
            p_message += sizeof(_fc);
            _serializer.Deserialize(p_message, _fe);
            p_message += sizeof(_fe);
            _serializer.Deserialize(p_message, _reserv);
            p_message += sizeof(_reserv);
        }
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GLOEphemerisStdMessage::GLOEphemerisStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string GLOEphemerisStdMessage::ToString() const
    {
        return toString("GLOEphemerisStdMessage");
    }
    
    bool GLOEphemerisStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void GLOEphemerisStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray GLOEphemerisStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

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
        if (BodySize() == 103)
        {
            // Optional Data Block
            _serializer.Serialize(_navType, result);
            _serializer.Serialize(_beta, result);
            _serializer.Serialize(_tauSysDot, result);
            _serializer.Serialize(_ec, result);
            _serializer.Serialize(_ee, result);
            _serializer.Serialize(_fc, result);
            _serializer.Serialize(_fe, result);
            _serializer.Serialize(_reserv, result);
        }
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
