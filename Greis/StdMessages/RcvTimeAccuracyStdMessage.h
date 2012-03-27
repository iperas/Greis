#ifndef RcvTimeAccuracyStdMessage_h__
#define RcvTimeAccuracyStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RcvTimeAccuracyStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RcvTimeAccuracyStdMessage);

        RcvTimeAccuracyStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Accuracy [s]
        const Types::f4& Acc() const { return _acc; }
        Types::f4& Acc() { return _acc; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _acc;
        Types::u1 _cs;
    };
}

#endif // RcvTimeAccuracyStdMessage_h__
