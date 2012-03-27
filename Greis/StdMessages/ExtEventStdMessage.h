#ifndef ExtEventStdMessage_h__
#define ExtEventStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class ExtEventStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(ExtEventStdMessage);

        ExtEventStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ms part of event time tag
        const Types::i4& Ms() const { return _ms; }
        Types::i4& Ms() { return _ms; }

        // ns part of event time tag
        const Types::i4& Ns() const { return _ns; }
        Types::i4& Ns() { return _ns; }

        // time scale
        const Types::u1& TimeScale() const { return _timeScale; }
        Types::u1& TimeScale() { return _timeScale; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::i4 _ms;
        Types::i4 _ns;
        Types::u1 _timeScale;
        Types::u1 _cs;
    };
}

#endif // ExtEventStdMessage_h__
