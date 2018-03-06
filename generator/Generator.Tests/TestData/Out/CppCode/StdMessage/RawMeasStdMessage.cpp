#include "RawMeasStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    RawMeasStdMessage::RawMeasStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        /*throw Common::NotImplementedException();*/

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    RawMeasStdMessage::RawMeasStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string RawMeasStdMessage::ToString() const
    {
        return toString("RawMeasStdMessage");
    }
    
    bool RawMeasStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void RawMeasStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray RawMeasStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_sample, result);
        _serializer.Serialize(_scale, result);
        _serializer.Serialize(_reftime, result);
        _serializer.Serialize(_clock, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_svd, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
