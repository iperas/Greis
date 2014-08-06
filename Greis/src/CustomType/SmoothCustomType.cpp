#include "SmoothCustomType.h"
#include <cassert>
#include "Common/Logger.h"

namespace Greis
{
    SmoothCustomType::SmoothCustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _value);
        p_message += sizeof(_value);
        _serializer.Deserialize(p_message, _interval);
        p_message += sizeof(_interval);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    SmoothCustomType::SmoothCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray SmoothCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_value, result);
        _serializer.Serialize(_interval, result);
        
        assert(result.size() == Size());
        return result;
    }
}
