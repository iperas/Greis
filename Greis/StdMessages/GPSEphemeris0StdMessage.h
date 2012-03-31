#ifndef GPSEphemeris0StdMessage_h__
#define GPSEphemeris0StdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class GPSEphemeris0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GPSEphemeris0StdMessage);

        GPSEphemeris0StdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV PRN number within the range [1…37]
        const Types::u1& Sv() const { return _sv; }
        Types::u1& Sv() { return _sv; }

        // Time of week [s]
        const Types::u4& Tow() const { return _tow; }
        Types::u4& Tow() { return _tow; }

        // Flags (see GPS ICD for details)[bitfield]:
        // 0 - curve fit interval
        // 1 - data flag for L2 P-code
        // 2,3 - code on L2 channel
        // 4 - anti-spoof (A-S) flag (from HOW)
        // 5 - ‘Alert’ flag (from HOW)
        // 6 - ephemeris was retrieved from non-volatile memory
        // 7 - reserved
        // ===== Clock data (Subframe 1) =====
        const Types::u1& Flags() const { return _flags; }
        Types::u1& Flags() { return _flags; }

        // Issue of data, clock []
        const Types::i2& Iodc() const { return _iodc; }
        Types::i2& Iodc() { return _iodc; }

        // Clock data reference time [s]
        const Types::i4& Toc() const { return _toc; }
        Types::i4& Toc() { return _toc; }

        // User range accuracy []
        const Types::i1& Ura() const { return _ura; }
        Types::i1& Ura() { return _ura; }

        // Satellite health []
        const Types::u1& HealthS() const { return _healthS; }
        Types::u1& HealthS() { return _healthS; }

        // Week number []
        const Types::i2& Wn() const { return _wn; }
        Types::i2& Wn() { return _wn; }

        // Estimated group delay differential [s]
        const Types::f4& Tgd() const { return _tgd; }
        Types::f4& Tgd() { return _tgd; }

        // Polynomial coefficient [s/(s^2)]
        const Types::f4& Af2() const { return _af2; }
        Types::f4& Af2() { return _af2; }

        // Polynomial coefficient [s/s]
        const Types::f4& Af1() const { return _af1; }
        Types::f4& Af1() { return _af1; }

        // Polynomial coefficient [s]
        // ===== Ephemeris data (Subframes 2 and 3) =====
        const Types::f4& Af0() const { return _af0; }
        Types::f4& Af0() { return _af0; }

        // Ephemeris reference time [s]
        const Types::i4& Toe() const { return _toe; }
        Types::i4& Toe() { return _toe; }

        // Issue of data, ephemeris []
        // --- Keplerian orbital parameters ---
        const Types::i2& Iode() const { return _iode; }
        Types::i2& Iode() { return _iode; }

        // Square root of the semi-major axis [m^0.5]
        const Types::f8& RootA() const { return _rootA; }
        Types::f8& RootA() { return _rootA; }

        // Eccentricity []
        const Types::f8& Ecc() const { return _ecc; }
        Types::f8& Ecc() { return _ecc; }

        // Mean Anomaly at reference time (wn,toe)
        // [semi-circles]
        const Types::f8& M0() const { return _m0; }
        Types::f8& M0() { return _m0; }

        // Longitude of ascending node of orbit plane at the
        // start of week ‘wn’ [semi-circles]
        const Types::f8& Omega0() const { return _omega0; }
        Types::f8& Omega0() { return _omega0; }

        // Inclination angle at reference time [semi-circles]
        const Types::f8& Inc0() const { return _inc0; }
        Types::f8& Inc0() { return _inc0; }

        // Argument of perigee [semi-circles]
        // --- Corrections to orbital parameters ---
        const Types::f8& ArgPer() const { return _argPer; }
        Types::f8& ArgPer() { return _argPer; }

        // Mean motion difference from computed value
        // [semi-circle/s]
        const Types::f4& Deln() const { return _deln; }
        Types::f4& Deln() { return _deln; }

        // Rate of right ascension [semi-circle/s]
        const Types::f4& OmegaDot() const { return _omegaDot; }
        Types::f4& OmegaDot() { return _omegaDot; }

        // Rate of inclination angle [semi-circle/s]
        const Types::f4& IncDot() const { return _incDot; }
        Types::f4& IncDot() { return _incDot; }

        // Amplitude of the cosine harmonic correction term
        // to the orbit radius [m]
        const Types::f4& Crc() const { return _crc; }
        Types::f4& Crc() { return _crc; }

        // Amplitude of the cosine harmonic correction term
        // to the orbit radius [m]
        const Types::f4& Crs() const { return _crs; }
        Types::f4& Crs() { return _crs; }

        // Amplitude of the cosine harmonic correction term
        // to the argument of latitude [rad]
        const Types::f4& Cuc() const { return _cuc; }
        Types::f4& Cuc() { return _cuc; }

        // Amplitude of the cosine harmonic correction term
        // to the argument of latitude [rad]
        const Types::f4& Cus() const { return _cus; }
        Types::f4& Cus() { return _cus; }

        // Amplitude of the cosine harmonic correction term
        // to the angle of inclination [rad]
        const Types::f4& Cic() const { return _cic; }
        Types::f4& Cic() { return _cic; }

        // Amplitude of the sine harmonic correction term
        // to the angle of inclination [rad]
        const Types::f4& Cis() const { return _cis; }
        Types::f4& Cis() { return _cis; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _sv;
        Types::u4 _tow;
        Types::u1 _flags;
        Types::i2 _iodc;
        Types::i4 _toc;
        Types::i1 _ura;
        Types::u1 _healthS;
        Types::i2 _wn;
        Types::f4 _tgd;
        Types::f4 _af2;
        Types::f4 _af1;
        Types::f4 _af0;
        Types::i4 _toe;
        Types::i2 _iode;
        Types::f8 _rootA;
        Types::f8 _ecc;
        Types::f8 _m0;
        Types::f8 _omega0;
        Types::f8 _inc0;
        Types::f8 _argPer;
        Types::f4 _deln;
        Types::f4 _omegaDot;
        Types::f4 _incDot;
        Types::f4 _crc;
        Types::f4 _crs;
        Types::f4 _cuc;
        Types::f4 _cus;
        Types::f4 _cic;
        Types::f4 _cis;
        Types::u1 _cs;
    };
}

#endif // GPSEphemeris0StdMessage_h__
