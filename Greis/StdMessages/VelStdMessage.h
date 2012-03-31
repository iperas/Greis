#ifndef VelStdMessage_h__
#define VelStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class VelStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(VelStdMessage);

        VelStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Cartesian velocity vector [m/s]
        const Types::f4& X() const { return _x; }
        Types::f4& X() { return _x; }

        // Cartesian velocity vector [m/s]
        const Types::f4& Y() const { return _y; }
        Types::f4& Y() { return _y; }

        // Cartesian velocity vector [m/s]
        const Types::f4& Z() const { return _z; }
        Types::f4& Z() { return _z; }

        // Velocity SEP [m/s]
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

        Types::f4 _x;
        Types::f4 _y;
        Types::f4 _z;
        Types::f4 _sigma;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // VelStdMessage_h__
