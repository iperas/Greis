#ifndef LoggingHistoryStdMessage_h__
#define LoggingHistoryStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class LoggingHistoryStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(LoggingHistoryStdMessage);

        LoggingHistoryStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::LoggingHistory; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Number of SVs
        const Types::u1& SvsCount() const { return _svsCount; }
        Types::u1& SvsCount() { return _svsCount; }

        // Stream ID
        const Types::u1& TargetStream() const { return _targetStream; }
        Types::u1& TargetStream() { return _targetStream; }

        // Issue of the history
        const Types::u2& Issue() const { return _issue; }
        Types::u2& Issue() { return _issue; }

        // Number of bits
        const Types::u2& BitsCount() const { return _bitsCount; }
        Types::u2& BitsCount() { return _bitsCount; }

        // Time since the last history shift [ms]
        const Types::u4& LastBitTime() const { return _lastBitTime; }
        Types::u4& LastBitTime() { return _lastBitTime; }

        // SVs UIDs
        const std::vector<Types::u1>& Uids() const { return _uids; }
        std::vector<Types::u1>& Uids() { return _uids; }

        // Padding
        const std::vector<Types::u1>& Pad() const { return _pad; }
        std::vector<Types::u1>& Pad() { return _pad; }

        // History bits
        const std::vector<std::vector<Types::u4>>& Hist() const { return _hist; }
        std::vector<std::vector<Types::u4>>& Hist() { return _hist; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _svsCount;
        Types::u1 _targetStream;
        Types::u2 _issue;
        Types::u2 _bitsCount;
        Types::u4 _lastBitTime;
        std::vector<Types::u1> _uids;
        std::vector<Types::u1> _pad;
        std::vector<std::vector<Types::u4>> _hist;
    };
}

#endif // LoggingHistoryStdMessage_h__
