#ifndef SCPStdMessage_h__
#define SCPStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class SCPStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SCPStdMessage);

        SCPStdMessage(const char* p_message, int p_length);
        SCPStdMessage(const std::string& p_id, int p_bodySize);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SCP; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // CP, [cycles/1024]
        const std::vector<Types::u4>& Scp() const { return _scp; }
        std::vector<Types::u4>& Scp() { return _scp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u4> _scp;
        Types::u1 _cs;
    };
}

#endif // SCPStdMessage_h__
