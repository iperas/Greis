#ifndef RotationMatrixStdMessage_h__
#define RotationMatrixStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RotationMatrixStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RotationMatrixStdMessage);

        RotationMatrixStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // receiver time [ms]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // components of the rotation matrix Q []
        const Types::f4& Q00() const { return _q00; }
        Types::f4& Q00() { return _q00; }

        // components of the rotation matrix Q []
        const Types::f4& Q01() const { return _q01; }
        Types::f4& Q01() { return _q01; }

        // components of the rotation matrix Q []
        const Types::f4& Q02() const { return _q02; }
        Types::f4& Q02() { return _q02; }

        // components of the rotation matrix Q []
        const Types::f4& Q12() const { return _q12; }
        Types::f4& Q12() { return _q12; }

        // estimated accuracy for three baseline vectors [m]
        const std::vector<Types::f4>& Rms() const { return _rms; }
        std::vector<Types::f4>& Rms() { return _rms; }

        // solution type10 for three baseline vectors
        const std::vector<Types::u1>& SolType() const { return _solType; }
        std::vector<Types::u1>& SolType() { return _solType; }

        // 0 – components of matrix Q are invalid, 1 - valid
        const Types::u1& Flag() const { return _flag; }
        Types::u1& Flag() { return _flag; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u4 _time;
        Types::f4 _q00;
        Types::f4 _q01;
        Types::f4 _q02;
        Types::f4 _q12;
        std::vector<Types::f4> _rms;
        std::vector<Types::u1> _solType;
        Types::u1 _flag;
        Types::u1 _cs;
    };
}

#endif // RotationMatrixStdMessage_h__
