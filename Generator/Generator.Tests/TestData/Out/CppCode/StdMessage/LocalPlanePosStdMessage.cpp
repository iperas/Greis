#include "LocalPlanePosStdMessage.h"
#include <cassert>
#include "Common/Logger.h"
#include "Greis/ChecksumComputer.h"

namespace Greis
{
    LocalPlanePosStdMessage::LocalPlanePosStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _n);
        p_message += sizeof(_n);
        _serializer.Deserialize(p_message, _e);
        p_message += sizeof(_e);
        _serializer.Deserialize(p_message, _u);
        p_message += sizeof(_u);
        _serializer.Deserialize(p_message, _sep);
        p_message += sizeof(_sep);
        _serializer.Deserialize(p_message, _pSigma);
        p_message += sizeof(_pSigma);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _geoid);
        p_message += sizeof(_geoid);
        _serializer.Deserialize(p_message, _prj);
        p_message += sizeof(_prj);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    LocalPlanePosStdMessage::LocalPlanePosStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string LocalPlanePosStdMessage::ToString() const
    {
        return toString("LocalPlanePosStdMessage");
    }
    
    bool LocalPlanePosStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void LocalPlanePosStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray LocalPlanePosStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_n, result);
        _serializer.Serialize(_e, result);
        _serializer.Serialize(_u, result);
        _serializer.Serialize(_sep, result);
        _serializer.Serialize(_pSigma, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_geoid, result);
        _serializer.Serialize(_prj, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
