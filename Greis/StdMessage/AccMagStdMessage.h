#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class AccMagStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(AccMagStdMessage);

        AccMagStdMessage(const char* p_message, int p_length);
        AccMagStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::AccMag; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // receiver time [ms]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // ax, ay, az [cm/sec2]
        const std::vector<Types::f4>& Accelerations() const { return _accelerations; }
        std::vector<Types::f4>& Accelerations() { return _accelerations; }

        // bx, by, bz 
        const std::vector<Types::f4>& Induction() const { return _induction; }
        std::vector<Types::f4>& Induction() { return _induction; }

        // Value of magnetic field 
        const Types::f4& Magnitude() const { return _magnitude; }
        Types::f4& Magnitude() { return _magnitude; }

        // Temperature of magnetic sensor [deg C] 
        const Types::f4& Temperature() const { return _temperature; }
        Types::f4& Temperature() { return _temperature; }

        // 1 - calibrated, 0 - not calibrated 
        const Types::u1& Calibrated() const { return _calibrated; }
        Types::u1& Calibrated() { return _calibrated; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u4 _time;
        std::vector<Types::f4> _accelerations;
        std::vector<Types::f4> _induction;
        Types::f4 _magnitude;
        Types::f4 _temperature;
        Types::u1 _calibrated;
        Types::u1 _cs;
    };
}
