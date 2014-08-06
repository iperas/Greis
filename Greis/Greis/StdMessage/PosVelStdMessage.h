#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class PosVelStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PosVelStdMessage);

        PosVelStdMessage(const char* p_message, int p_length);
        PosVelStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PosVel; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
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

        // Position SEP [m]
        const Types::f4& PSigma() const { return _pSigma; }
        Types::f4& PSigma() { return _pSigma; }

        // Cartesian velocities [m/s]
        const Types::f4& Vx() const { return _vx; }
        Types::f4& Vx() { return _vx; }

        // Cartesian velocities [m/s]
        const Types::f4& Vy() const { return _vy; }
        Types::f4& Vy() { return _vy; }

        // Cartesian velocities [m/s]
        const Types::f4& Vz() const { return _vz; }
        Types::f4& Vz() { return _vz; }

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

        Types::f8 _x;
        Types::f8 _y;
        Types::f8 _z;
        Types::f4 _pSigma;
        Types::f4 _vx;
        Types::f4 _vy;
        Types::f4 _vz;
        Types::f4 _vSigma;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}
