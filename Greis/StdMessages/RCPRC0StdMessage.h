#ifndef RCPRC0StdMessage_h__
#define RCPRC0StdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RCPRC0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RCPRC0StdMessage);

        RCPRC0StdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // cp / FLn - prRC [s]
        const std::vector<Types::f4>& Rcp() const { return _rcp; }
        std::vector<Types::f4>& Rcp() { return _rcp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::f4> _rcp;
        Types::u1 _cs;
    };
}

#endif // RCPRC0StdMessage_h__
