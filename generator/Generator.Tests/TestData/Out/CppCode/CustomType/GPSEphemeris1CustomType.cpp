#include "GPSEphemeris1CustomType.h"
#include <cassert>
#include "common/Logger.h"

namespace Greis
{
    GPSEphemeris1CustomType::GPSEphemeris1CustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, 122, _req);
        p_message += 122;
        _serializer.Deserialize(p_message, 36, _opt);
        p_message += 36;

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
        _serializer.Serialize(_opt, result);
        
        assert(result.size() == Size());
        return result;
    }
}
