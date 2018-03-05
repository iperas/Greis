#include "RotationAnglesStdMessage.h"
#include <cassert>
#include "Common/Logger.h"
#include "Greis/ChecksumComputer.h"

namespace Greis
{
    RotationAnglesStdMessage::RotationAnglesStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _p);
        p_message += sizeof(_p);
        _serializer.Deserialize(p_message, _r);
        p_message += sizeof(_r);
        _serializer.Deserialize(p_message, _h);
        p_message += sizeof(_h);
        _serializer.Deserialize(p_message, _sp);
        p_message += sizeof(_sp);
        _serializer.Deserialize(p_message, _sr);
        p_message += sizeof(_sr);
        _serializer.Deserialize(p_message, _sh);
        p_message += sizeof(_sh);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * 3, _solType);
        p_message += sizeof(std::vector<Types::u1>::value_type) * 3;
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
    
    RotationAnglesStdMessage::RotationAnglesStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string RotationAnglesStdMessage::ToString() const
    {
        return toString("RotationAnglesStdMessage");
    }
    
    bool RotationAnglesStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void RotationAnglesStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray RotationAnglesStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_time, result);
        _serializer.Serialize(_p, result);
        _serializer.Serialize(_r, result);
        _serializer.Serialize(_h, result);
        _serializer.Serialize(_sp, result);
        _serializer.Serialize(_sr, result);
        _serializer.Serialize(_sh, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
