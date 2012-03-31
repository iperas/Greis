#ifndef RcvOscOffsStdMessage_h__
#define RcvOscOffsStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RcvOscOffsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RcvOscOffsStdMessage);

        RcvOscOffsStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Oscillator offset [s/s]
        const Types::f4& Val() const { return _val; }
        Types::f4& Val() { return _val; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _val;
        Types::u1 _cs;
    };
}

#endif // RcvOscOffsStdMessage_h__
