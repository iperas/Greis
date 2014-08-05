#include "PosStatStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"

namespace Greis
{
    PosStatStdMessage::PosStatStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _gpsLocked);
        p_message += sizeof(_gpsLocked);
        _serializer.Deserialize(p_message, _gloLocked);
        p_message += sizeof(_gloLocked);
        _serializer.Deserialize(p_message, _gpsAvail);
        p_message += sizeof(_gpsAvail);
        _serializer.Deserialize(p_message, _gloAvail);
        p_message += sizeof(_gloAvail);
        _serializer.Deserialize(p_message, _gpsUsed);
        p_message += sizeof(_gpsUsed);
        _serializer.Deserialize(p_message, _gloUsed);
        p_message += sizeof(_gloUsed);
        _serializer.Deserialize(p_message, _fixProg);
        p_message += sizeof(_fixProg);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    PosStatStdMessage::PosStatStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string PosStatStdMessage::ToString() const
    {
        return toString("PosStatStdMessage");
    }
    
    bool PosStatStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void PosStatStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray PosStatStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_gpsLocked, result);
        _serializer.Serialize(_gloLocked, result);
        _serializer.Serialize(_gpsAvail, result);
        _serializer.Serialize(_gloAvail, result);
        _serializer.Serialize(_gpsUsed, result);
        _serializer.Serialize(_gloUsed, result);
        _serializer.Serialize(_fixProg, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
