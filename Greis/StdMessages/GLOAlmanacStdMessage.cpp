#include "GLOAlmanacStdMessage.h"
#include <cassert>

namespace Greis
{
    GLOAlmanacStdMessage::GLOAlmanacStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _sv);
        p_message += sizeof(_sv);
        _serializer.Deserialize(p_message, _frqNum);
        p_message += sizeof(_frqNum);
        _serializer.Deserialize(p_message, _dna);
        p_message += sizeof(_dna);
        _serializer.Deserialize(p_message, _tlam);
        p_message += sizeof(_tlam);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, _tauN);
        p_message += sizeof(_tauN);
        _serializer.Deserialize(p_message, _tauSys);
        p_message += sizeof(_tauSys);
        _serializer.Deserialize(p_message, _ecc);
        p_message += sizeof(_ecc);
        _serializer.Deserialize(p_message, _lambda);
        p_message += sizeof(_lambda);
        _serializer.Deserialize(p_message, _argPer);
        p_message += sizeof(_argPer);
        _serializer.Deserialize(p_message, _delT);
        p_message += sizeof(_delT);
        _serializer.Deserialize(p_message, _delTdt);
        p_message += sizeof(_delTdt);
        _serializer.Deserialize(p_message, _deli);
        p_message += sizeof(_deli);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    GLOAlmanacStdMessage::GLOAlmanacStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string GLOAlmanacStdMessage::ToString() const
    {
        return toString("GLOAlmanacStdMessage");
    }
    bool GLOAlmanacStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray GLOAlmanacStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_sv, result);
        _serializer.Serialize(_frqNum, result);
        _serializer.Serialize(_dna, result);
        _serializer.Serialize(_tlam, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_tauN, result);
        _serializer.Serialize(_tauSys, result);
        _serializer.Serialize(_ecc, result);
        _serializer.Serialize(_lambda, result);
        _serializer.Serialize(_argPer, result);
        _serializer.Serialize(_delT, result);
        _serializer.Serialize(_delTdt, result);
        _serializer.Serialize(_deli, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
