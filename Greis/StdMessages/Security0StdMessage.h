#ifndef Security0StdMessage_h__
#define Security0StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class Security0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(Security0StdMessage);

        Security0StdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Security0; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Opaque data
        const std::vector<Types::u1>& Data() const { return _data; }
        std::vector<Types::u1>& Data() { return _data; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u1> _data;
        Types::u1 _cs;
    };
}

#endif // Security0StdMessage_h__
