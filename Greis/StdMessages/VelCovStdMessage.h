#ifndef VelCovStdMessage_h__
#define VelCovStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class VelCovStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(VelCovStdMessage);

        VelCovStdMessage(const char* p_message, int p_length);
        VelCovStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::VelCov; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // [(m/s)^2]
        const Types::f4& Xx() const { return _xx; }
        Types::f4& Xx() { return _xx; }

        // [(m/s)^2]
        const Types::f4& Yy() const { return _yy; }
        Types::f4& Yy() { return _yy; }

        // [(m/s)^2]
        const Types::f4& Zz() const { return _zz; }
        Types::f4& Zz() { return _zz; }

        // [(m/s)^2]
        const Types::f4& Tt() const { return _tt; }
        Types::f4& Tt() { return _tt; }

        // [(m/s)^2]
        const Types::f4& Xy() const { return _xy; }
        Types::f4& Xy() { return _xy; }

        // [(m/s)^2]
        const Types::f4& Xz() const { return _xz; }
        Types::f4& Xz() { return _xz; }

        // [(m/s)^2]
        const Types::f4& Xt() const { return _xt; }
        Types::f4& Xt() { return _xt; }

        // [(m/s)^2]
        const Types::f4& Yz() const { return _yz; }
        Types::f4& Yz() { return _yz; }

        // [(m/s)^2]
        const Types::f4& Yt() const { return _yt; }
        Types::f4& Yt() { return _yt; }

        // [(m/s)^2]
        const Types::f4& Zt() const { return _zt; }
        Types::f4& Zt() { return _zt; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _xx;
        Types::f4 _yy;
        Types::f4 _zz;
        Types::f4 _tt;
        Types::f4 _xy;
        Types::f4 _xz;
        Types::f4 _xt;
        Types::f4 _yz;
        Types::f4 _yt;
        Types::f4 _zt;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // VelCovStdMessage_h__
