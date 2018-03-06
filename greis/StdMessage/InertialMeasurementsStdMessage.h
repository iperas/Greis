#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class InertialMeasurementsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(InertialMeasurementsStdMessage);

        InertialMeasurementsStdMessage(const char* p_message, int p_length);
        InertialMeasurementsStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::InertialMeasurements; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ax,ay,az [m/sec2]
        const std::vector<Types::f4>& Accelerations() const { return _accelerations; }
        std::vector<Types::f4>& Accelerations() { return _accelerations; }

        // wx,wy,wz [rad/sec] 
        const std::vector<Types::f4>& AngularVelocities() const { return _angularVelocities; }
        std::vector<Types::f4>& AngularVelocities() { return _angularVelocities; }

        // 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::f4> _accelerations;
        std::vector<Types::f4> _angularVelocities;
        Types::u1 _cs;
    };
}
