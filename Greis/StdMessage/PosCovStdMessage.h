#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class PosCovStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PosCovStdMessage);

        PosCovStdMessage(const char* p_message, int p_length);
        PosCovStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PosCov; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // [m^2] 
        const Types::f4& Xx() const { return _xx; }
        Types::f4& Xx() { return _xx; }

        // [m^2] 
        const Types::f4& Yy() const { return _yy; }
        Types::f4& Yy() { return _yy; }

        // [m^2] 
        const Types::f4& Zz() const { return _zz; }
        Types::f4& Zz() { return _zz; }

        // [m^2] 
        const Types::f4& Tt() const { return _tt; }
        Types::f4& Tt() { return _tt; }

        // [m^2] 
        const Types::f4& Xy() const { return _xy; }
        Types::f4& Xy() { return _xy; }

        // [m^2] 
        const Types::f4& Xz() const { return _xz; }
        Types::f4& Xz() { return _xz; }

        // [m^2] 
        const Types::f4& Xt() const { return _xt; }
        Types::f4& Xt() { return _xt; }

        // [m^2] 
        const Types::f4& Yz() const { return _yz; }
        Types::f4& Yz() { return _yz; }

        // [m^2] 
        const Types::f4& Yt() const { return _yt; }
        Types::f4& Yt() { return _yt; }

        // [m^2]
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
        bool _isCorrect;

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
