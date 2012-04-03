#ifndef RotationAnglesStdMessage_h__
#define RotationAnglesStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class RotationAnglesStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RotationAnglesStdMessage);

        RotationAnglesStdMessage(const char* p_message, int p_length);
        RotationAnglesStdMessage(const std::string& p_id, int p_bodySize);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RotationAngles; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // receiver time [ms]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // pitch angle [deg]
        const Types::f4& Pitch() const { return _pitch; }
        Types::f4& Pitch() { return _pitch; }

        // roll angle [deg]
        const Types::f4& Roll() const { return _roll; }
        Types::f4& Roll() { return _roll; }

        // heading angle [deg]
        const Types::f4& Heading() const { return _heading; }
        Types::f4& Heading() { return _heading; }

        // pitch angle RMS [deg]
        const Types::f4& PitchRms() const { return _pitchRms; }
        Types::f4& PitchRms() { return _pitchRms; }

        // roll angle RMS [deg]
        const Types::f4& RollRms() const { return _rollRms; }
        Types::f4& RollRms() { return _rollRms; }

        // heading angle RMS [deg]
        const Types::f4& HeadingRms() const { return _headingRms; }
        Types::f4& HeadingRms() { return _headingRms; }

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

        Types::u4 _time;
        Types::f4 _pitch;
        Types::f4 _roll;
        Types::f4 _heading;
        Types::f4 _pitchRms;
        Types::f4 _rollRms;
        Types::f4 _headingRms;
        Types::u1 _flags;
        Types::u1 _cs;
    };
}

#endif // RotationAnglesStdMessage_h__
