#include "SbasRawNavDataStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    SbasRawNavDataStdMessage::SbasRawNavDataStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _prn);
        p_message += sizeof(_prn);
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _type);
        p_message += sizeof(_type);
        _serializer.Deserialize(p_message, _len);
        p_message += sizeof(_len);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * 32, _data);
        p_message += sizeof(std::vector<Types::u1>::value_type) * 32;
        _serializer.Deserialize(p_message, _errCorr);
        p_message += sizeof(_errCorr);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    SbasRawNavDataStdMessage::SbasRawNavDataStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string SbasRawNavDataStdMessage::ToString() const
    {
        return toString("SbasRawNavDataStdMessage");
    }
    
    bool SbasRawNavDataStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void SbasRawNavDataStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray SbasRawNavDataStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_prn, result);
        _serializer.Serialize(_time, result);
        _serializer.Serialize(_type, result);
        _serializer.Serialize(_len, result);
        _serializer.Serialize(_data, result);
        _serializer.Serialize(_errCorr, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
