#ifndef GLOAlmanacStdMessage_h__
#define GLOAlmanacStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class GLOAlmanacStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GLOAlmanacStdMessage);

        GLOAlmanacStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Satellite orbit slot number within [1…24] []
        const Types::u1& Sv() const { return _sv; }
        Types::u1& Sv() { return _sv; }

        // Satellite frequency channel number [-7…24] []
        const Types::i1& FrqNum() const { return _frqNum; }
        Types::i1& FrqNum() { return _frqNum; }

        // Day number within 4-year period starting
        // with the leap year []
        const Types::i2& Dna() const { return _dna; }
        Types::i2& Dna() { return _dna; }

        // Time of the first ascending node passage
        // on day ‘dna’ [s]
        const Types::f4& Tlam() const { return _tlam; }
        Types::f4& Tlam() { return _tlam; }

        // Satellite flags [bitfield]:
        // 0 - health: 1 - healthy SV, as specified
        // by ‘Cn’, 0 - unhealthy
        // 1 - SVs type: 0 - GLONASS, 1 - GLONASS-M
        // 2…7 - reserved
        // ======= Clock data =======
        const Types::u1& Flags() const { return _flags; }
        Types::u1& Flags() { return _flags; }

        // Coarse time correction to SV clock
        // with respect to GLONASS system time [s]
        const Types::f4& TauN() const { return _tauN; }
        Types::f4& TauN() { return _tauN; }

        // Correction to GLONASS system time with respect
        // to UTC(SU) [s]
        // ===== Ephemeris data =====
        const Types::f8& TauSys() const { return _tauSys; }
        Types::f8& TauSys() { return _tauSys; }

        // Eccentricity at reference time ‘tlam’ []
        const Types::f4& Ecc() const { return _ecc; }
        Types::f4& Ecc() { return _ecc; }

        // Longitude of ascending node
        // at reference time ‘tlam’ [semi-circles]
        const Types::f4& Lambda() const { return _lambda; }
        Types::f4& Lambda() { return _lambda; }

        // Argument of perigee
        // at reference time ‘tlam’ [semi-circles]
        const Types::f4& ArgPer() const { return _argPer; }
        Types::f4& ArgPer() { return _argPer; }

        // Correction to mean Draconic period
        // at reference time ‘tlam’ [s/period]
        const Types::f4& DelT() const { return _delT; }
        Types::f4& DelT() { return _delT; }

        // Rate of change of Draconic period [s/period^2]
        const Types::f4& DelTdt() const { return _delTdt; }
        Types::f4& DelTdt() { return _delTdt; }

        // Correction to inclination
        // at reference time ‘tlam’[semi-circles]
        const Types::f4& Deli() const { return _deli; }
        Types::f4& Deli() { return _deli; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _sv;
        Types::i1 _frqNum;
        Types::i2 _dna;
        Types::f4 _tlam;
        Types::u1 _flags;
        Types::f4 _tauN;
        Types::f8 _tauSys;
        Types::f4 _ecc;
        Types::f4 _lambda;
        Types::f4 _argPer;
        Types::f4 _delT;
        Types::f4 _delTdt;
        Types::f4 _deli;
        Types::u1 _cs;
    };
}

#endif // GLOAlmanacStdMessage_h__
