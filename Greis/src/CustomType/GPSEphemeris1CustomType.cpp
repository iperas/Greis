#include "GPSEphemeris1CustomType.h"
#include <cassert>
#include "Common/Logger.h"

namespace Greis
{
    GPSEphemeris1CustomType::GPSEphemeris1CustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, 122, _req);
        p_message += 122;
        _serializer.Deserialize(p_message, _cNavType);
        p_message += sizeof(_cNavType);
        _serializer.Deserialize(p_message, _lTope);
        p_message += sizeof(_lTope);
        _serializer.Deserialize(p_message, _lTopc);
        p_message += sizeof(_lTopc);
        _serializer.Deserialize(p_message, _dADot);
        p_message += sizeof(_dADot);
        _serializer.Deserialize(p_message, _fDelnDot);
        p_message += sizeof(_fDelnDot);
        _serializer.Deserialize(p_message, _cURAoe);
        p_message += sizeof(_cURAoe);
        _serializer.Deserialize(p_message, _cURAoc);
        p_message += sizeof(_cURAoc);
        _serializer.Deserialize(p_message, _cURAoc1);
        p_message += sizeof(_cURAoc1);
        _serializer.Deserialize(p_message, _cURAoc2);
        p_message += sizeof(_cURAoc2);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GPSEphemeris1CustomType::GPSEphemeris1CustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray GPSEphemeris1CustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_req, result);
        _serializer.Serialize(_cNavType, result);
        _serializer.Serialize(_lTope, result);
        _serializer.Serialize(_lTopc, result);
        _serializer.Serialize(_dADot, result);
        _serializer.Serialize(_fDelnDot, result);
        _serializer.Serialize(_cURAoe, result);
        _serializer.Serialize(_cURAoc, result);
        _serializer.Serialize(_cURAoc1, result);
        _serializer.Serialize(_cURAoc2, result);
        
        assert(result.size() == Size());
        return result;
    }
}
