#include "RefEpochStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    RefEpochStdMessage::RefEpochStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _sample);
        p_message += sizeof(_sample);
        _serializer.Deserialize(p_message, _scale);
        p_message += sizeof(_scale);
        _serializer.Deserialize(p_message, _reftime);
        p_message += sizeof(_reftime);
        _serializer.Deserialize(p_message, _crc16);
        p_message += sizeof(_crc16);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    RefEpochStdMessage::RefEpochStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string RefEpochStdMessage::ToString() const
    {
        return toString("RefEpochStdMessage");
    }
    
    bool RefEpochStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void RefEpochStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray RefEpochStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_sample, result);
        _serializer.Serialize(_scale, result);
        _serializer.Serialize(_reftime, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
