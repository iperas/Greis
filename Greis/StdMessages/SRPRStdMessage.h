#ifndef SRPRStdMessage_h__
#define SRPRStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SRPRStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SRPRStdMessage);

        SRPRStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // (PR[s] - CA/L1 PR[s] - 2*10-7) * 1011
        const std::vector<Types::i2>& Srpr() const { return _srpr; }
        std::vector<Types::i2>& Srpr() { return _srpr; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i2> _srpr;
        Types::u1 _cs;
    };
}

#endif // SRPRStdMessage_h__
