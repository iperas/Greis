#include "GPSEphemeris0StdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    GPSEphemeris0StdMessage::GPSEphemeris0StdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 122, _req);
        p_message += 122;
        if (BodySize() == 160)
        {
            // Optional Data Block
            _serializer.Deserialize(p_message, 37, _opt);
            p_message += 37;
        }
        if (BodySize() == 168)
        {
            // Optional Data Block
            _serializer.Deserialize(p_message, 45, _opt);
            p_message += 45;
        }
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GPSEphemeris0StdMessage::GPSEphemeris0StdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string GPSEphemeris0StdMessage::ToString() const
    {
        return toString("GPSEphemeris0StdMessage");
    }
    
    bool GPSEphemeris0StdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void GPSEphemeris0StdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray GPSEphemeris0StdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_req, result);
        if (BodySize() == 120)
        {
            // Optional Data Block
            _serializer.Serialize(_opt, result);
        }
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
