#ifndef GPSAlm0StdMessage_h__
#define GPSAlm0StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class GPSAlm0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GPSAlm0StdMessage);

        GPSAlm0StdMessage(const char* p_message, int p_length);
        GPSAlm0StdMessage(const std::string& p_id, int p_bodySize);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GPSAlm0; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV PRN number within the range [1…37]
        const Types::u1& Sv() const { return _sv; }
        Types::u1& Sv() { return _sv; }

        // Almanac reference week []
        const Types::i2& Wna() const { return _wna; }
        Types::i2& Wna() { return _wna; }

        // Almanac reference time of week [s]
        const Types::i4& Toa() const { return _toa; }
        Types::i4& Toa() { return _toa; }

        // Health summary (from almanac), [bitfield]
        // 0…4 - code for health of SV signal components
        // 5…7 - navigation data health indicators
        const Types::u1& HealthA() const { return _healthA; }
        Types::u1& HealthA() { return _healthA; }

        // Satellite health (page 25 of subframe 5) []
        const Types::u1& HealthS() const { return _healthS; }
        Types::u1& HealthS() { return _healthS; }

        // Satellite configuration (page 25 of subframe 4)
        // [bitfield]:
        // 0…2 - satellite configuration
        // 3 - anti-spoofing flag
        // 4…7 - reserved
        // ======= Clock data =======
        const Types::u1& Config() const { return _config; }
        Types::u1& Config() { return _config; }

        // Polynomial coefficient [s/s]
        const Types::f4& Af1() const { return _af1; }
        Types::f4& Af1() { return _af1; }

        // Polynomial coefficient [s]
        // ===== Ephemeris data =====
        // --- Keplerian orbital parameters ---
        const Types::f4& Af0() const { return _af0; }
        Types::f4& Af0() { return _af0; }

        // Square root of the semi-major axis [m^0.5]
        const Types::f4& RootA() const { return _rootA; }
        Types::f4& RootA() { return _rootA; }

        // Eccentricity []
        const Types::f4& Ecc() const { return _ecc; }
        Types::f4& Ecc() { return _ecc; }

        // Mean Anomaly at reference time [semi-circles]
        const Types::f4& M0() const { return _m0; }
        Types::f4& M0() { return _m0; }

        // Longitude of ascending node of orbit plane
        // at the start of week ‘wna’ [semi-circles]
        const Types::f4& Omega0() const { return _omega0; }
        Types::f4& Omega0() { return _omega0; }

        // Argument of perigee [semi-circles]
        // --- Corrections to orbital parameters ---
        const Types::f4& ArgPer() const { return _argPer; }
        Types::f4& ArgPer() { return _argPer; }

        // Correction to inclination angle [semi-circles]
        const Types::f4& Deli() const { return _deli; }
        Types::f4& Deli() { return _deli; }

        // Rate of right ascension [semi-circle/s]
        const Types::f4& OmegaDot() const { return _omegaDot; }
        Types::f4& OmegaDot() { return _omegaDot; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _sv;
        Types::i2 _wna;
        Types::i4 _toa;
        Types::u1 _healthA;
        Types::u1 _healthS;
        Types::u1 _config;
        Types::f4 _af1;
        Types::f4 _af0;
        Types::f4 _rootA;
        Types::f4 _ecc;
        Types::f4 _m0;
        Types::f4 _omega0;
        Types::f4 _argPer;
        Types::f4 _deli;
        Types::f4 _omegaDot;
        Types::u1 _cs;
    };
}

#endif // GPSAlm0StdMessage_h__
