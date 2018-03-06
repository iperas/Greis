#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class RotationAnglesStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RotationAnglesStdMessage);

        RotationAnglesStdMessage(const char* p_message, int p_length);
        RotationAnglesStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RotationAngles; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Receiver time [ms] 
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Pitch ,roll , heading angles [deg] 
        const Types::f4& P() const { return _p; }
        Types::f4& P() { return _p; }

        // Pitch ,roll , heading angles [deg] 
        const Types::f4& R() const { return _r; }
        Types::f4& R() { return _r; }

        // Pitch ,roll , heading angles [deg] 
        const Types::f4& H() const { return _h; }
        Types::f4& H() { return _h; }

        // Pitch, roll, heading angles RMS[deg]
        const Types::f4& Sp() const { return _sp; }
        Types::f4& Sp() { return _sp; }

        // Pitch, roll, heading angles RMS[deg]
        const Types::f4& Sr() const { return _sr; }
        Types::f4& Sr() { return _sr; }

        // Pitch, roll, heading angles RMS[deg]
        const Types::f4& Sh() const { return _sh; }
        Types::f4& Sh() { return _sh; }

        // Solution type for 3 base lines
        const std::vector<Types::u1>& SolType() const { return _solType; }
        std::vector<Types::u1>& SolType() { return _solType; }

        // flags [bitfield]:
        // 0: 0 - no data available 
        // 1 - data are valid 
        // 7�1: reserved 
        const Types::u1& Flags() const { return _flags; }
        Types::u1& Flags() { return _flags; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u4 _time;
        Types::f4 _p;
        Types::f4 _r;
        Types::f4 _h;
        Types::f4 _sp;
        Types::f4 _sr;
        Types::f4 _sh;
        std::vector<Types::u1> _solType;
        Types::u1 _flags;
        Types::u1 _cs;
    };
}
