#include "ESICustomType.h"
#include <cassert>
#include "common/Logger.h"

namespace Greis
{
    ESICustomType::ESICustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _ssid);
        p_message += sizeof(_ssid);
        _serializer.Deserialize(p_message, _svid);
        p_message += sizeof(_svid);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    ESICustomType::ESICustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray ESICustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_ssid, result);
        _serializer.Serialize(_svid, result);
        
        assert(result.size() == Size());
        return result;
    }
}
