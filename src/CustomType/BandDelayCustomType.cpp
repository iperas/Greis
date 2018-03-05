#include "BandDelayCustomType.h"
#include <cassert>
#include "Common/Logger.h"

namespace Greis
{
    BandDelayCustomType::BandDelayCustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _band);
        p_message += sizeof(_band);
        _serializer.Deserialize(p_message, _signal);
        p_message += sizeof(_signal);
        _serializer.Deserialize(p_message, _delay);
        p_message += sizeof(_delay);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    BandDelayCustomType::BandDelayCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray BandDelayCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_band, result);
        _serializer.Serialize(_signal, result);
        _serializer.Serialize(_delay, result);
        
        assert(result.size() == Size());
        return result;
    }
}
