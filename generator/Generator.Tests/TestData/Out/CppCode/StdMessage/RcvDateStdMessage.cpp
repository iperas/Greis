#include "RcvDateStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    RcvDateStdMessage::RcvDateStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _year);
        p_message += sizeof(_year);
        _serializer.Deserialize(p_message, _month);
        p_message += sizeof(_month);
        _serializer.Deserialize(p_message, _day);
        p_message += sizeof(_day);
        _serializer.Deserialize(p_message, _base);
        p_message += sizeof(_base);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    RcvDateStdMessage::RcvDateStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string RcvDateStdMessage::ToString() const
    {
        return toString("RcvDateStdMessage");
    }
    
    bool RcvDateStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void RcvDateStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray RcvDateStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_year, result);
        _serializer.Serialize(_month, result);
        _serializer.Serialize(_day, result);
        _serializer.Serialize(_base, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
