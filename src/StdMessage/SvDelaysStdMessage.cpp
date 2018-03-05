#include "SvDelaysStdMessage.h"
#include <cassert>
#include "Common/Logger.h"
#include "Greis/ChecksumComputer.h"

namespace Greis
{
    SvDelaysStdMessage::SvDelaysStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _fcn);
        p_message += sizeof(_fcn);
        _serializer.Deserialize(p_message, _phase);
        p_message += sizeof(_phase);
        _serializer.Deserialize(p_message, _range);
        p_message += sizeof(_range);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    SvDelaysStdMessage::SvDelaysStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string SvDelaysStdMessage::ToString() const
    {
        return toString("SvDelaysStdMessage");
    }
    
    bool SvDelaysStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void SvDelaysStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray SvDelaysStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_fcn, result);
        _serializer.Serialize(_phase, result);
        _serializer.Serialize(_range, result);
        
        assert(result.size() == Size());
        return result;
    }
}
