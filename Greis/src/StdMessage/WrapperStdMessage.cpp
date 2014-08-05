#include "WrapperStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"

namespace Greis
{
    WrapperStdMessage::WrapperStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 3) / 1;

        _serializer.Deserialize(p_message, _idField);
        p_message += sizeof(_idField);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields, _data);
        p_message += sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, 2, _cs);
        p_message += 2;

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    WrapperStdMessage::WrapperStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string WrapperStdMessage::ToString() const
    {
        return toString("WrapperStdMessage");
    }
    
    bool WrapperStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Ascii(message.data(), message.size());
    }
    
    void WrapperStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        auto cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
        auto ba = QString::number(cs, 16).toAscii();
        _cs[0] = ba[0]; _cs[1] = ba[1];
    }

    QByteArray WrapperStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_idField, result);
        _serializer.Serialize(_data, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
