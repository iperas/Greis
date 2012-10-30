#include "IonoParams0StdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"

namespace Greis
{
    IonoParams0StdMessage::IonoParams0StdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _tot);
        p_message += sizeof(_tot);
        _serializer.Deserialize(p_message, _wn);
        p_message += sizeof(_wn);
        _serializer.Deserialize(p_message, _alpha0);
        p_message += sizeof(_alpha0);
        _serializer.Deserialize(p_message, _alpha1);
        p_message += sizeof(_alpha1);
        _serializer.Deserialize(p_message, _alpha2);
        p_message += sizeof(_alpha2);
        _serializer.Deserialize(p_message, _alpha3);
        p_message += sizeof(_alpha3);
        _serializer.Deserialize(p_message, _beta0);
        p_message += sizeof(_beta0);
        _serializer.Deserialize(p_message, _beta1);
        p_message += sizeof(_beta1);
        _serializer.Deserialize(p_message, _beta2);
        p_message += sizeof(_beta2);
        _serializer.Deserialize(p_message, _beta3);
        p_message += sizeof(_beta3);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    IonoParams0StdMessage::IonoParams0StdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string IonoParams0StdMessage::ToString() const
    {
        return toString("IonoParams0StdMessage");
    }
    
    bool IonoParams0StdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void IonoParams0StdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray IonoParams0StdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_tot, result);
        _serializer.Serialize(_wn, result);
        _serializer.Serialize(_alpha0, result);
        _serializer.Serialize(_alpha1, result);
        _serializer.Serialize(_alpha2, result);
        _serializer.Serialize(_alpha3, result);
        _serializer.Serialize(_beta0, result);
        _serializer.Serialize(_beta1, result);
        _serializer.Serialize(_beta2, result);
        _serializer.Serialize(_beta3, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
