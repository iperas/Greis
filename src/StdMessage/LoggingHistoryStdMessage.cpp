#include "LoggingHistoryStdMessage.h"
#include <cassert>
#include "Common/Logger.h"
#include "Greis/ChecksumComputer.h"

namespace Greis
{
    LoggingHistoryStdMessage::LoggingHistoryStdMessage( const char* pc_message, int p_length ) 
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
    
    LoggingHistoryStdMessage::LoggingHistoryStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string LoggingHistoryStdMessage::ToString() const
    {
        return toString("LoggingHistoryStdMessage");
    }
    
    bool LoggingHistoryStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void LoggingHistoryStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray LoggingHistoryStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_svsCount, result);
        _serializer.Serialize(_targetStream, result);
        _serializer.Serialize(_issue, result);
        _serializer.Serialize(_bitsCount, result);
        _serializer.Serialize(_lastBitTime, result);
        _serializer.Serialize(_uids, result);
        _serializer.Serialize(_pad, result);
        _serializer.Serialize(_hist, result);
        
        assert(result.size() == Size());
        return result;
    }
}
