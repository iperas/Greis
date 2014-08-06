#include "PosVelVectorStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "Common/Logger.h"

namespace Greis
{
    PosVelVectorStdMessage::PosVelVectorStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _sample);
        p_message += sizeof(_sample);
        _serializer.Deserialize(p_message, _delta);
        p_message += sizeof(_delta);
        _serializer.Deserialize(p_message, _word1);
        p_message += sizeof(_word1);
        _serializer.Deserialize(p_message, _word2);
        p_message += sizeof(_word2);
        _serializer.Deserialize(p_message, _word3);
        p_message += sizeof(_word3);
        _serializer.Deserialize(p_message, _word4);
        p_message += sizeof(_word4);
        _serializer.Deserialize(p_message, _word5);
        p_message += sizeof(_word5);
        _serializer.Deserialize(p_message, _word6);
        p_message += sizeof(_word6);
        _serializer.Deserialize(p_message, _word7);
        p_message += sizeof(_word7);
        _serializer.Deserialize(p_message, _word8);
        p_message += sizeof(_word8);
        _serializer.Deserialize(p_message, _word9);
        p_message += sizeof(_word9);
        _serializer.Deserialize(p_message, _crc16);
        p_message += sizeof(_crc16);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    PosVelVectorStdMessage::PosVelVectorStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string PosVelVectorStdMessage::ToString() const
    {
        return toString("PosVelVectorStdMessage");
    }
    
    bool PosVelVectorStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void PosVelVectorStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray PosVelVectorStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_sample, result);
        _serializer.Serialize(_delta, result);
        _serializer.Serialize(_word1, result);
        _serializer.Serialize(_word2, result);
        _serializer.Serialize(_word3, result);
        _serializer.Serialize(_word4, result);
        _serializer.Serialize(_word5, result);
        _serializer.Serialize(_word6, result);
        _serializer.Serialize(_word7, result);
        _serializer.Serialize(_word8, result);
        _serializer.Serialize(_word9, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
