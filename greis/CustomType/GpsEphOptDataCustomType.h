#pragma once

#include <QtCore/QByteArray>
#include "greis/CustomType.h"
#include "greis/ECustomTypeId.h"

namespace Greis
{
    class GpsEphOptDataCustomType : public CustomType
    {
    public:
        SMART_PTR_T(GpsEphOptDataCustomType);

        GpsEphOptDataCustomType(const char* p_message, int p_length);
        GpsEphOptDataCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::GpsEphOptData; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Signal type [bitfield]
        // 0 - L1 NAV 
        // 1 - L2C CNAV 
        // 2 - L5 CNAV 
        // 3 - L1C CNAV2 
        const Types::u1& NavType() const { return _navType; }
        Types::u1& NavType() { return _navType; }

        // Time of prediction for ephemeris data 
        const Types::i4& LTope() const { return _lTope; }
        Types::i4& LTope() { return _lTope; }

        // Time of prediction for clock data 
        const Types::i4& LTopc() const { return _lTopc; }
        Types::i4& LTopc() { return _lTopc; }

        // Change rate in semi-major axisf4 fDelnDot; // Rate of mean motioni1 cURAoe; // SV ephemeris URA index 
        const Types::f8& DADot() const { return _dADot; }
        Types::f8& DADot() { return _dADot; }

        // SV clock URA index 
        const Types::i1& CURAoc() const { return _cURAoc; }
        Types::i1& CURAoc() { return _cURAoc; }

        // SV clock URA change index 
        const Types::i1& CURAoc1() const { return _cURAoc1; }
        Types::i1& CURAoc1() { return _cURAoc1; }

        // SV clock URA change rate index 
        const Types::i1& CURAoc2() const { return _cURAoc2; }
        Types::i1& CURAoc2() { return _cURAoc2; }

        // Inter-signal correction between L1P(Y) and L1 C/Af4 fIscL2C; // Inter-signal correction between L1P(Y) and L2C
        const Types::f4& FIscL1CA() const { return _fIscL1CA; }
        Types::f4& FIscL1CA() { return _fIscL1CA; }

        // Inter-signal correction between L1P(Y) and L5I5f4 fIscL5Q5; // Inter-signal correction between L1P(Y) and L5Q5
        const Types::f4& FIscL5I5() const { return _fIscL5I5; }
        Types::f4& FIscL5I5() { return _fIscL5I5; }

        // Inter-signal correction between L1P(Y) and L1CPf4 fIscL1CD; // Inter-signal correction between L1P(Y) and L1CD
        const Types::f4& FIscL1CP() const { return _fIscL1CP; }
        Types::f4& FIscL1CP() { return _fIscL1CP; }

        // correction to ‘af0’. Exact term = af0 + DAF0 
        const Types::f4& DAf0() const { return _DAf0; }
        Types::f4& DAf0() { return _DAf0; }
    private:
        int _size;
        bool _isCorrect;

        Types::u1 _navType;
        Types::i4 _lTope;
        Types::i4 _lTopc;
        Types::f8 _dADot;
        Types::i1 _cURAoc;
        Types::i1 _cURAoc1;
        Types::i1 _cURAoc2;
        Types::f4 _fIscL1CA;
        Types::f4 _fIscL5I5;
        Types::f4 _fIscL1CP;
        Types::f4 _DAf0;
    };
}
