#include "GpsEphReqDataCustomType.h"
#include "ProjectBase/Logger.h"
#include <cassert>

namespace Greis
{
    GpsEphReqDataCustomType::GpsEphReqDataCustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _sv);
        p_message += sizeof(_sv);
        _serializer.Deserialize(p_message, _tow);
        p_message += sizeof(_tow);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, _iodc);
        p_message += sizeof(_iodc);
        _serializer.Deserialize(p_message, _toc);
        p_message += sizeof(_toc);
        _serializer.Deserialize(p_message, _ura);
        p_message += sizeof(_ura);
        _serializer.Deserialize(p_message, _healthS);
        p_message += sizeof(_healthS);
        _serializer.Deserialize(p_message, _wn);
        p_message += sizeof(_wn);
        _serializer.Deserialize(p_message, _tgd);
        p_message += sizeof(_tgd);
        _serializer.Deserialize(p_message, _af2);
        p_message += sizeof(_af2);
        _serializer.Deserialize(p_message, _af1);
        p_message += sizeof(_af1);
        _serializer.Deserialize(p_message, _af0);
        p_message += sizeof(_af0);
        _serializer.Deserialize(p_message, _toe);
        p_message += sizeof(_toe);
        _serializer.Deserialize(p_message, _iode);
        p_message += sizeof(_iode);
        _serializer.Deserialize(p_message, _rootA);
        p_message += sizeof(_rootA);
        _serializer.Deserialize(p_message, _ecc);
        p_message += sizeof(_ecc);
        _serializer.Deserialize(p_message, _m0);
        p_message += sizeof(_m0);
        _serializer.Deserialize(p_message, _omega0);
        p_message += sizeof(_omega0);
        _serializer.Deserialize(p_message, _inc0);
        p_message += sizeof(_inc0);
        _serializer.Deserialize(p_message, _argPer);
        p_message += sizeof(_argPer);
        _serializer.Deserialize(p_message, _deln);
        p_message += sizeof(_deln);
        _serializer.Deserialize(p_message, _omegaDot);
        p_message += sizeof(_omegaDot);
        _serializer.Deserialize(p_message, _incDot);
        p_message += sizeof(_incDot);
        _serializer.Deserialize(p_message, _crc);
        p_message += sizeof(_crc);
        _serializer.Deserialize(p_message, _crs);
        p_message += sizeof(_crs);
        _serializer.Deserialize(p_message, _cuc);
        p_message += sizeof(_cuc);
        _serializer.Deserialize(p_message, _cus);
        p_message += sizeof(_cus);
        _serializer.Deserialize(p_message, _cic);
        p_message += sizeof(_cic);
        _serializer.Deserialize(p_message, _cis);
        p_message += sizeof(_cis);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GpsEphReqDataCustomType::GpsEphReqDataCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray GpsEphReqDataCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_sv, result);
        _serializer.Serialize(_tow, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_iodc, result);
        _serializer.Serialize(_toc, result);
        _serializer.Serialize(_ura, result);
        _serializer.Serialize(_healthS, result);
        _serializer.Serialize(_wn, result);
        _serializer.Serialize(_tgd, result);
        _serializer.Serialize(_af2, result);
        _serializer.Serialize(_af1, result);
        _serializer.Serialize(_af0, result);
        _serializer.Serialize(_toe, result);
        _serializer.Serialize(_iode, result);
        _serializer.Serialize(_rootA, result);
        _serializer.Serialize(_ecc, result);
        _serializer.Serialize(_m0, result);
        _serializer.Serialize(_omega0, result);
        _serializer.Serialize(_inc0, result);
        _serializer.Serialize(_argPer, result);
        _serializer.Serialize(_deln, result);
        _serializer.Serialize(_omegaDot, result);
        _serializer.Serialize(_incDot, result);
        _serializer.Serialize(_crc, result);
        _serializer.Serialize(_crs, result);
        _serializer.Serialize(_cuc, result);
        _serializer.Serialize(_cus, result);
        _serializer.Serialize(_cic, result);
        _serializer.Serialize(_cis, result);
        
        assert(result.size() == Size());
        return result;
    }
}
