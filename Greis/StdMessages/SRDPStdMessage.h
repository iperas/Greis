#ifndef SRDPStdMessage_h__
#define SRDPStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SRDPStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SRDPStdMessage);

        SRDPStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // (dp - dpCA1)[Hz*10-4]
        const std::vector<Types::i2>& Srdp() const { return _srdp; }
        std::vector<Types::i2>& Srdp() { return _srdp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i2> _srdp;
        Types::u1 _cs;
    };
}

#endif // SRDPStdMessage_h__
