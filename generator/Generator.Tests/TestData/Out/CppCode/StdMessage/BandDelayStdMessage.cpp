#include "BandDelayStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    BandDelayStdMessage::BandDelayStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _band);
        p_message += sizeof(_band);
        _serializer.Deserialize(p_message, _signal);
        p_message += sizeof(_signal);
        _serializer.Deserialize(p_message, _delay);
        p_message += sizeof(_delay);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    BandDelayStdMessage::BandDelayStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string BandDelayStdMessage::ToString() const
    {
        return toString("BandDelayStdMessage");
    }
    
    bool BandDelayStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void BandDelayStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray BandDelayStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_band, result);
        _serializer.Serialize(_signal, result);
        _serializer.Serialize(_delay, result);
        
        assert(result.size() == Size());
        return result;
    }
}
