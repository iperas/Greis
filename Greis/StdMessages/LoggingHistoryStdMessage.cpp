#include "LoggingHistoryStdMessage.h"
#include <cassert>

namespace Greis
{
    LoggingHistoryStdMessage::LoggingHistoryStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        throw ProjectBase::NotImplementedException();
        
        assert(p_message - pc_message == p_length);
    }

    std::string LoggingHistoryStdMessage::ToString() const
    {
        return toString("LoggingHistoryStdMessage");
    }
    bool LoggingHistoryStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        return true;
    }

    QByteArray LoggingHistoryStdMessage::ToByteArray() const
    {
        QByteArray result;
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
