#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class VelStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(VelStdMessage);

        VelStdMessage(const char* p_message, int p_length);
        VelStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Vel; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
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
        const Types::f4& VSigma() const { return _vSigma; }
        Types::f4& VSigma() { return _vSigma; }

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

        Types::f4 _x;
        Types::f4 _y;
        Types::f4 _z;
        Types::f4 _vSigma;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}
