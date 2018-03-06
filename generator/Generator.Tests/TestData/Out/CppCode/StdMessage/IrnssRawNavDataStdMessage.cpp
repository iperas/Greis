#include "IrnssRawNavDataStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    IrnssRawNavDataStdMessage::IrnssRawNavDataStdMessage( const char* pc_message, int p_length ) 
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

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    IrnssRawNavDataStdMessage::IrnssRawNavDataStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string IrnssRawNavDataStdMessage::ToString() const
    {
        return toString("IrnssRawNavDataStdMessage");
    }
    
    bool IrnssRawNavDataStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void IrnssRawNavDataStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray IrnssRawNavDataStdMessage::ToByteArray() const
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
        
        assert(result.size() == Size());
        return result;
    }
}
