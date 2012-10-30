#include "GPSEphemeris0StdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"

namespace Greis
{
    GPSEphemeris0StdMessage::GPSEphemeris0StdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 122, _req);
        p_message += 122;
        if (BodySize() == 148)
        {
            // Optional Data Block
            _serializer.Deserialize(p_message, _cNavType);
            p_message += sizeof(_cNavType);
            _serializer.Deserialize(p_message, _lTope);
            p_message += sizeof(_lTope);
            _serializer.Deserialize(p_message, _lTopc);
            p_message += sizeof(_lTopc);
            _serializer.Deserialize(p_message, _dADot);
            p_message += sizeof(_dADot);
            _serializer.Deserialize(p_message, _fDelnDot);
            p_message += sizeof(_fDelnDot);
            _serializer.Deserialize(p_message, _cURAoe);
            p_message += sizeof(_cURAoe);
            _serializer.Deserialize(p_message, _cURAoc);
            p_message += sizeof(_cURAoc);
            _serializer.Deserialize(p_message, _cURAoc1);
            p_message += sizeof(_cURAoc1);
            _serializer.Deserialize(p_message, _cURAoc2);
            p_message += sizeof(_cURAoc2);
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
        if (BodySize() == 148)
        {
            // Optional Data Block
            _serializer.Serialize(_cNavType, result);
            _serializer.Serialize(_lTope, result);
            _serializer.Serialize(_lTopc, result);
            _serializer.Serialize(_dADot, result);
            _serializer.Serialize(_fDelnDot, result);
            _serializer.Serialize(_cURAoe, result);
            _serializer.Serialize(_cURAoc, result);
            _serializer.Serialize(_cURAoc1, result);
            _serializer.Serialize(_cURAoc2, result);
        }
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
