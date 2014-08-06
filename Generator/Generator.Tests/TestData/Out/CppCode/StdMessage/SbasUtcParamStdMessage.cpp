#include "SbasUtcParamStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"

namespace Greis
{
    SbasUtcParamStdMessage::SbasUtcParamStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 23, _utc);
        p_message += 23;
        _serializer.Deserialize(p_message, _utcsi);
        p_message += sizeof(_utcsi);
        _serializer.Deserialize(p_message, _tow);
        p_message += sizeof(_tow);
        _serializer.Deserialize(p_message, _wn);
        p_message += sizeof(_wn);
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
    
    SbasUtcParamStdMessage::SbasUtcParamStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string SbasUtcParamStdMessage::ToString() const
    {
        return toString("SbasUtcParamStdMessage");
    }
    
    bool SbasUtcParamStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void SbasUtcParamStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray SbasUtcParamStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_utc, result);
        _serializer.Serialize(_utcsi, result);
        _serializer.Serialize(_tow, result);
        _serializer.Serialize(_wn, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
