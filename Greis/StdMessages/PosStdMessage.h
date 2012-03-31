#ifndef PosStdMessage_h__
#define PosStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class PosStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PosStdMessage);

        PosStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Cartesian coordinates [m]
        const Types::f8& X() const { return _x; }
        Types::f8& X() { return _x; }

        // Cartesian coordinates [m]
        const Types::f8& Y() const { return _y; }
        Types::f8& Y() { return _y; }

        // Cartesian coordinates [m]
        const Types::f8& Z() const { return _z; }
        Types::f8& Z() { return _z; }

        // Position SEP6 [m]
        const Types::f4& Sigma() const { return _sigma; }
        Types::f4& Sigma() { return _sigma; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f8 _x;
        Types::f8 _y;
        Types::f8 _z;
        Types::f4 _sigma;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // PosStdMessage_h__
