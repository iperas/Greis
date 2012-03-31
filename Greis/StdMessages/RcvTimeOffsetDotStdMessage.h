#ifndef RcvTimeOffsetDotStdMessage_h__
#define RcvTimeOffsetDotStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RcvTimeOffsetDotStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RcvTimeOffsetDotStdMessage);

        RcvTimeOffsetDotStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Derivative of (Trr - Tr) [s/s]
        const Types::f4& Val() const { return _val; }
        Types::f4& Val() { return _val; }

        // Smoothed derivative of (Trr - Tr) [s/s]
        const Types::f4& Sval() const { return _sval; }
        Types::f4& Sval() { return _sval; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _val;
        Types::f4 _sval;
        Types::u1 _cs;
    };
}

#endif // RcvTimeOffsetDotStdMessage_h__
