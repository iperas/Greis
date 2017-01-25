#include "GalUtcGpsParamStdMessage.h"
#include <cassert>
#include "Common/Logger.h"
#include "Greis/ChecksumComputer.h"

namespace Greis
{
    GalUtcGpsParamStdMessage::GalUtcGpsParamStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 23, _utc);
        p_message += 23;
        _serializer.Deserialize(p_message, _a0g);
        p_message += sizeof(_a0g);
        _serializer.Deserialize(p_message, _a1g);
        p_message += sizeof(_a1g);
        _serializer.Deserialize(p_message, _t0g);
        p_message += sizeof(_t0g);
        _serializer.Deserialize(p_message, _wn0g);
        p_message += sizeof(_wn0g);
        _serializer.Deserialize(p_message, _flags);
        p_message += sizeof(_flags);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GalUtcGpsParamStdMessage::GalUtcGpsParamStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string GalUtcGpsParamStdMessage::ToString() const
    {
        return toString("GalUtcGpsParamStdMessage");
    }
    
    bool GalUtcGpsParamStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void GalUtcGpsParamStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray GalUtcGpsParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_utc, result);
        _serializer.Serialize(_a0g, result);
        _serializer.Serialize(_a1g, result);
        _serializer.Serialize(_t0g, result);
        _serializer.Serialize(_wn0g, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
