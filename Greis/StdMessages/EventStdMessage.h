#ifndef EventStdMessage_h__
#define EventStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class EventStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(EventStdMessage);

        EventStdMessage(const char* p_message, int p_length);
        EventStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Event; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Receiver time of event occurrence modulo day, [ms]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Event type (see below), []
        const Types::u1& Type() const { return _type; }
        Types::u1& Type() { return _type; }

        // Event contents
        const std::vector<Types::u1>& Data() const { return _data; }
        std::vector<Types::u1>& Data() { return _data; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u4 _time;
        Types::u1 _type;
        std::vector<Types::u1> _data;
        Types::u1 _cs;
    };
}

#endif // EventStdMessage_h__
