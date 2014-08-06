#include "RotationMatrixStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"

namespace Greis
{
    RotationMatrixStdMessage::RotationMatrixStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _q00);
        p_message += sizeof(_q00);
        _serializer.Deserialize(p_message, _q01);
        p_message += sizeof(_q01);
        _serializer.Deserialize(p_message, _q02);
        p_message += sizeof(_q02);
        _serializer.Deserialize(p_message, _q12);
        p_message += sizeof(_q12);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * 3, _rms);
        p_message += sizeof(std::vector<Types::f4>::value_type) * 3;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * 3, _solType);
        p_message += sizeof(std::vector<Types::u1>::value_type) * 3;
        _serializer.Deserialize(p_message, _flag);
        p_message += sizeof(_flag);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    RotationMatrixStdMessage::RotationMatrixStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string RotationMatrixStdMessage::ToString() const
    {
        return toString("RotationMatrixStdMessage");
    }
    
    bool RotationMatrixStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void RotationMatrixStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray RotationMatrixStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_time, result);
        _serializer.Serialize(_q00, result);
        _serializer.Serialize(_q01, result);
        _serializer.Serialize(_q02, result);
        _serializer.Serialize(_q12, result);
        _serializer.Serialize(_rms, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_flag, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
