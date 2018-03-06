#include "BeiDouEphemerisStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    BeiDouEphemerisStdMessage::BeiDouEphemerisStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 122, _req);
        p_message += 122;
        _serializer.Deserialize(p_message, _tgd2);
        p_message += sizeof(_tgd2);
        _serializer.Deserialize(p_message, _navType);
        p_message += sizeof(_navType);
        _serializer.Deserialize(p_message, _DAf0);
        p_message += sizeof(_DAf0);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    BeiDouEphemerisStdMessage::BeiDouEphemerisStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string BeiDouEphemerisStdMessage::ToString() const
    {
        return toString("BeiDouEphemerisStdMessage");
    }
    
    bool BeiDouEphemerisStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void BeiDouEphemerisStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray BeiDouEphemerisStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_req, result);
        _serializer.Serialize(_tgd2, result);
        _serializer.Serialize(_navType, result);
        _serializer.Serialize(_DAf0, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
