#include "GLOAlmanacStdMessage.h"
#include <cassert>
#include "Common/Logger.h"
#include "Greis/ChecksumComputer.h"

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
        _serializer.Deserialize(p_message, _n4);
        p_message += sizeof(_n4);
        if (BodySize() == 52)
        {
            // Optional Data Block
            _serializer.Deserialize(p_message, _reserved);
            p_message += sizeof(_reserved);
            _serializer.Deserialize(p_message, _gammaN);
            p_message += sizeof(_gammaN);
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
    
    GLOAlmanacStdMessage::GLOAlmanacStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string GLOAlmanacStdMessage::ToString() const
    {
        return toString("GLOAlmanacStdMessage");
    }
    
    bool GLOAlmanacStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void GLOAlmanacStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray GLOAlmanacStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

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
        _serializer.Serialize(_n4, result);
        if (BodySize() == 52)
        {
            // Optional Data Block
            _serializer.Serialize(_reserved, result);
            _serializer.Serialize(_gammaN, result);
        }
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
