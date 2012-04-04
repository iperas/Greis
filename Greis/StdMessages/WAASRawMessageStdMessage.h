#ifndef WAASRawMessageStdMessage_h__
#define WAASRawMessageStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class WAASRawMessageStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(WAASRawMessageStdMessage);

        WAASRawMessageStdMessage(const char* p_message, int p_length);
        WAASRawMessageStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::WAASRawMessage; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV PRN number within the range [120…138]
        const Types::u1& Prn() const { return _prn; }
        Types::u1& Prn() { return _prn; }

        // Time of receiving of message [s]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Reserved
        const Types::u2& Reserv() const { return _reserv; }
        Types::u2& Reserv() { return _reserv; }

        // Navigation data block
        const std::vector<Types::u1>& Data() const { return _data; }
        std::vector<Types::u1>& Data() { return _data; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _prn;
        Types::u4 _time;
        Types::u2 _reserv;
        std::vector<Types::u1> _data;
        Types::u1 _cs;
    };
}

#endif // WAASRawMessageStdMessage_h__
