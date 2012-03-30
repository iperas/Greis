#include "LoggingHistoryStdMessage.h"

namespace Greis
{
    LoggingHistoryStdMessage::LoggingHistoryStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string LoggingHistoryStdMessage::ToString() const
    {
        return toString("LoggingHistoryStdMessage");
    }

    QByteArray LoggingHistoryStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
