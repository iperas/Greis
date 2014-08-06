#include "ClockOffsetsStdMessage.h"
#include <cassert>
#include "Common/Logger.h"
#include "Greis/ChecksumComputer.h"

namespace Greis
{
    ClockOffsetsStdMessage::ClockOffsetsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 7) / 8;

        _serializer.Deserialize(p_message, _sample);
        p_message += sizeof(_sample);
        _serializer.Deserialize(p_message, _reserved);
        p_message += sizeof(_reserved);
        _serializer.Deserialize(p_message, _recSize);
        p_message += sizeof(_recSize);
        _serializer.Deserialize(p_message, 8 * arraySizeInUniformFillFields, 8, _Offs);
        p_message += 8 * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _crc16);
        p_message += sizeof(_crc16);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    ClockOffsetsStdMessage::ClockOffsetsStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string ClockOffsetsStdMessage::ToString() const
    {
        return toString("ClockOffsetsStdMessage");
    }
    
    bool ClockOffsetsStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void ClockOffsetsStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray ClockOffsetsStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_sample, result);
        _serializer.Serialize(_reserved, result);
        _serializer.Serialize(_recSize, result);
        _serializer.Serialize(_Offs, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
