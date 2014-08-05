#include "SlotRecCustomType.h"
#include "ProjectBase/Logger.h"
#include <cassert>

namespace Greis
{
    SlotRecCustomType::SlotRecCustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _svstOrDelrange);
        p_message += sizeof(_svstOrDelrange);
        _serializer.Deserialize(p_message, _word1);
        p_message += sizeof(_word1);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, _lock);
        p_message += sizeof(_lock);
        _serializer.Deserialize(p_message, _word2);
        p_message += sizeof(_word2);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    SlotRecCustomType::SlotRecCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray SlotRecCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_svstOrDelrange, result);
        _serializer.Serialize(_word1, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_lock, result);
        _serializer.Serialize(_word2, result);
        
        assert(result.size() == Size());
        return result;
    }
}
