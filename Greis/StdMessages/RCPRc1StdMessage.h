#ifndef RCPRc1StdMessage_h__
#define RCPRc1StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class RCPRc1StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RCPRc1StdMessage);

        RCPRc1StdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RCPRc1; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // cp / FLn - pr_rc, [s*2-40]
        const std::vector<Types::i4>& Rcp() const { return _rcp; }
        std::vector<Types::i4>& Rcp() { return _rcp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i4> _rcp;
        Types::u1 _cs;
    };
}

#endif // RCPRc1StdMessage_h__
