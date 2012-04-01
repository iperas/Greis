#ifndef CPStdMessage_h__
#define CPStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class CPStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CPStdMessage);

        CPStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::CP; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // CP, [cycles]
        const std::vector<Types::f8>& Cp() const { return _cp; }
        std::vector<Types::f8>& Cp() { return _cp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::f8> _cp;
        Types::u1 _cs;
    };
}

#endif // CPStdMessage_h__
