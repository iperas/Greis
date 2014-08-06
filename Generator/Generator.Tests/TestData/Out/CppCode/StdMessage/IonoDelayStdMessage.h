#ifndef IonoDelayStdMessage_h__
#define IonoDelayStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class IonoDelayStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(IonoDelayStdMessage);

        IonoDelayStdMessage(const char* p_message, int p_length);
        IonoDelayStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::IonoDelay; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
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
        bool _isCorrect;

        std::vector<Types::f4> _delay;
        Types::u1 _cs;
    };
}

#endif // IonoDelayStdMessage_h__
