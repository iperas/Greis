#ifndef AngularVelocityStdMessage_h__
#define AngularVelocityStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class AngularVelocityStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(AngularVelocityStdMessage);

        AngularVelocityStdMessage(const char* p_message, int p_length);
        AngularVelocityStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::AngularVelocity; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // receiver time [ms]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // X component of angular velocity [rad/s]
        const Types::f4& X() const { return _x; }
        Types::f4& X() { return _x; }

        // Y component of angular velocity [rad/s]
        const Types::f4& Y() const { return _y; }
        Types::f4& Y() { return _y; }

        // Z component of angular velocity [rad/s]
        const Types::f4& Z() const { return _z; }
        Types::f4& Z() { return _z; }

        // Angular velocity RMS [rad/s]
        const Types::f4& Rms() const { return _rms; }
        Types::f4& Rms() { return _rms; }

        // flags [bitfield]:
        // 0: 0 - no data available
        // 1 - data are valid
        // 7…1: reserved
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
        Types::f4 _x;
        Types::f4 _y;
        Types::f4 _z;
        Types::f4 _rms;
        Types::u1 _flags;
        Types::u1 _cs;
    };
}

#endif // AngularVelocityStdMessage_h__
