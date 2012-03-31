#ifndef RcvGPSTimeOffsetStdMessage_h__
#define RcvGPSTimeOffsetStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RcvGPSTimeOffsetStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RcvGPSTimeOffsetStdMessage);

        RcvGPSTimeOffsetStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // (Tg - Tr) [s]
        const Types::f8& Val() const { return _val; }
        Types::f8& Val() { return _val; }

        // Smoothed (Tg - Tr) [s]
        const Types::f8& Sval() const { return _sval; }
        Types::f8& Sval() { return _sval; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f8 _val;
        Types::f8 _sval;
        Types::u1 _cs;
    };
}

#endif // RcvGPSTimeOffsetStdMessage_h__
