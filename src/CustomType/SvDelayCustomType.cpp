#include "SvDelayCustomType.h"
#include <cassert>
#include "Common/Logger.h"

namespace Greis
{
    SvDelayCustomType::SvDelayCustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _fcn);
        p_message += sizeof(_fcn);
        _serializer.Deserialize(p_message, _phase);
        p_message += sizeof(_phase);
        _serializer.Deserialize(p_message, _range);
        p_message += sizeof(_range);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    SvDelayCustomType::SvDelayCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray SvDelayCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_fcn, result);
        _serializer.Serialize(_phase, result);
        _serializer.Serialize(_range, result);
        
        assert(result.size() == Size());
        return result;
    }
}
