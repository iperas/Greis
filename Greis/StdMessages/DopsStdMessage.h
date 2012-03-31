#ifndef DopsStdMessage_h__
#define DopsStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class DopsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(DopsStdMessage);

        DopsStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Horizontal dilution of precision (HDOP)[]
        const Types::f4& Hdop() const { return _hdop; }
        Types::f4& Hdop() { return _hdop; }

        // Vertical dilution of precision (VDOP) []
        const Types::f4& Vdop() const { return _vdop; }
        Types::f4& Vdop() { return _vdop; }

        // Time dilution of precision (TDOP) []
        const Types::f4& Tdop() const { return _tdop; }
        Types::f4& Tdop() { return _tdop; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _hdop;
        Types::f4 _vdop;
        Types::f4 _tdop;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // DopsStdMessage_h__
