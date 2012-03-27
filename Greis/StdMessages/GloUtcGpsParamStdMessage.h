#ifndef GloUtcGpsParamStdMessage_h__
#define GloUtcGpsParamStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class GloUtcGpsParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GloUtcGpsParamStdMessage);

        GloUtcGpsParamStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Time correction to GLONASS time scale (vs. UTC(SU))
        // tauSys = Tutc(su) - Tglo [s]
        const Types::f8& TauSys() const { return _tauSys; }
        Types::f8& TauSys() { return _tauSys; }

        // tauGps = Tgps - Tglo [s]
        const Types::f4& TauGps() const { return _tauGps; }
        Types::f4& TauGps() { return _tauGps; }

        // Coefficient for calculation of UT1
        const Types::f4& B1() const { return _B1; }
        Types::f4& B1() { return _B1; }

        // Coefficient for calculation of UT1
        const Types::f4& B2() const { return _B2; }
        Types::f4& B2() { return _B2; }

        // Leap second information
        const Types::u1& KP() const { return _KP; }
        Types::u1& KP() { return _KP; }

        // Number of 4-year cycle [1…31]
        const Types::u1& N4() const { return _N4; }
        Types::u1& N4() { return _N4; }

        // Day number within 4-year period []
        const Types::i2& Dn() const { return _Dn; }
        Types::i2& Dn() { return _Dn; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f8 _tauSys;
        Types::f4 _tauGps;
        Types::f4 _B1;
        Types::f4 _B2;
        Types::u1 _KP;
        Types::u1 _N4;
        Types::i2 _Dn;
        Types::u1 _cs;
    };
}

#endif // GloUtcGpsParamStdMessage_h__
