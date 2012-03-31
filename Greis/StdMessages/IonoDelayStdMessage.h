#ifndef IonoDelayStdMessage_h__
#define IonoDelayStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class IonoDelayStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(IonoDelayStdMessage);

        IonoDelayStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Ionospheric delay [s]
        const std::vector<Types::f4>& Delay() const { return _delay; }
        std::vector<Types::f4>& Delay() { return _delay; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::f4> _delay;
        Types::u1 _cs;
    };
}

#endif // IonoDelayStdMessage_h__
