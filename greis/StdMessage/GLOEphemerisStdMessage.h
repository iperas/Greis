#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class GLOEphemerisStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GLOEphemerisStdMessage);

        GLOEphemerisStdMessage(const char* p_message, int p_length);
        GLOEphemerisStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GLOEphemeris; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Satellite orbit slot number [1�32] []
        const Types::u1& Sv() const { return _sv; }
        Types::u1& Sv() { return _sv; }

        // Satellite frequency channel number [-7�24] []
        const Types::i1& FrqNum() const { return _frqNum; }
        Types::i1& FrqNum() { return _frqNum; }

        // Day number within 4-year period [] 
        const Types::i2& Dne() const { return _dne; }
        Types::i2& Dne() { return _dne; }

        // Frame start time within current day [s] 
        const Types::i4& Tk() const { return _tk; }
        Types::i4& Tk() { return _tk; }

        // Ephemeris reference time (for day �dne�) [s]
        const Types::i4& Tb() const { return _tb; }
        Types::i4& Tb() { return _tb; }

        // Satellite health [bitfield] 
        // 0 - MSB taken from Bn word which indicates 
        // satellite health: 
        // 1 - satellite is unhealthy 
        // 0 - satellite is healthy 
        // 1 - If set, this flag indicates that params 
        // �tau� and �gamma� may be wrong 
        // (Note that receiver performs several 
        // �internal� data consistency checks allowing 
        // detection of problem broadcast parameters) 
        // 2 - If set, this flag indicates that initial 
        // conditions �r[3]� and �v[3]� may be wrong 
        // 3 - SV health (Cn word) status from almanac: 
        // 0 - satellite is unhealthy 
        // 1 - satellite is healthy 
        // 4 - If set, this flag indicates that SV health 
        // status from almanac is available 
        // 5�7 - reserved 
        // ===== Ephemeris data ======
        const Types::u1& Health() const { return _health; }
        Types::u1& Health() { return _health; }

        // Age of operational information (En) [days] 
        const Types::u1& Age() const { return _age; }
        Types::u1& Age() { return _age; }

        // Flags (for details, see GLONASS ICD) [bitfield]:
        // 0�1 - p1 word 
        // 2 - p2 word 
        // 3 - p3 word 
        // 4�5 - 2 LSB taken from Bn word 
        // 6 - ephemeris was retrieved from NV-memory 
        // 7 - SV is GLONASS-M or newer 
        const Types::u1& Flags() const { return _flags; }
        Types::u1& Flags() { return _flags; }

        // Satellite PE-90 coordinates [km] 
        const std::vector<Types::f8>& R() const { return _r; }
        std::vector<Types::f8>& R() { return _r; }

        // Satellite PE-90 velocities [km/s] 
        const std::vector<Types::f4>& V() const { return _v; }
        std::vector<Types::f4>& V() { return _v; }

        // Satellite PE-90 accelerations due to Luni-Solar 
        // gravitational perturbations [km/s^2]
        // ===== Clock data ======
        const std::vector<Types::f4>& W() const { return _w; }
        std::vector<Types::f4>& W() { return _w; }

        // Time correction to GLONASS time scale (vs. UTC(SU))
        // tauSys = TUTC(SU) - TGLN [s] 
        const Types::f8& TauSys() const { return _tauSys; }
        Types::f8& TauSys() { return _tauSys; }

        // Correction to satellite clock (vs. GLONASS time) 
        // tau = TGLN - TSV [s] 
        const Types::f4& Tau() const { return _tau; }
        Types::f4& Tau() { return _tau; }

        // Rate of satellite clock offset [s/s]
        // ===== GLONASS-M data ======
        const Types::f4& Gamma() const { return _gamma; }
        Types::f4& Gamma() { return _gamma; }

        // Delta Tau N - delay between L1 and L2 [s]
        const Types::f4& FDelTauN() const { return _fDelTauN; }
        Types::f4& FDelTauN() { return _fDelTauN; }

        // Ft (User Range Accuracy), see GLONASS ICD for values 
        const Types::u1& NFt() const { return _nFt; }
        Types::u1& NFt() { return _nFt; }

        // Number of 4-year cycle [1�31]
        const Types::u1& NN4() const { return _nN4; }
        Types::u1& NN4() { return _nN4; }

        // Flags (for details, see GLONASS ICD) [bitfield]:
        // 0 - GLONASS-M ln (third string) 
        // 1�2 - GLONASS-M P 
        // 3 - GLONASS-M P4 
        // 4�5 - GLONASS-M M 
        // 6 - GLONASS-M ln (fifth string) 
        // 7�15 - reserved 
        // --- Optional data block --
        const Types::u2& Flags2() const { return _flags2; }
        Types::u2& Flags2() { return _flags2; }

        // Signal type [bitfield]
        // 0 - L1 
        // 1 - L3 
        // 2 - L2C 
        // 3 - P1 
        // 4 - P2 
        const Types::u1& NavType() const { return _navType; }
        Types::u1& NavType() { return _navType; }

        // Derivation of rate of satellite clock offset [s/s/s]
        const Types::f4& Beta() const { return _beta; }
        Types::f4& Beta() { return _beta; }

        // Derivation of �tauSys� [s/s]
        const Types::f4& TauSysDot() const { return _tauSysDot; }
        Types::f4& TauSysDot() { return _tauSysDot; }

        // Age of clock information (days) 
        const Types::u1& Ec() const { return _ec; }
        Types::u1& Ec() { return _ec; }

        // Age of ephemeris information (days) 
        const Types::u1& Ee() const { return _ee; }
        Types::u1& Ee() { return _ee; }

        // Clock accuracy index 
        const Types::i1& Fc() const { return _fc; }
        Types::i1& Fc() { return _fc; }

        // Ephemeris accuracy index 
        const Types::i1& Fe() const { return _fe; }
        Types::i1& Fe() { return _fe; }

        // --- End of optional data block --
        const Types::u2& Reserv() const { return _reserv; }
        Types::u2& Reserv() { return _reserv; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u1 _sv;
        Types::i1 _frqNum;
        Types::i2 _dne;
        Types::i4 _tk;
        Types::i4 _tb;
        Types::u1 _health;
        Types::u1 _age;
        Types::u1 _flags;
        std::vector<Types::f8> _r;
        std::vector<Types::f4> _v;
        std::vector<Types::f4> _w;
        Types::f8 _tauSys;
        Types::f4 _tau;
        Types::f4 _gamma;
        Types::f4 _fDelTauN;
        Types::u1 _nFt;
        Types::u1 _nN4;
        Types::u2 _flags2;
        Types::u1 _navType;
        Types::f4 _beta;
        Types::f4 _tauSysDot;
        Types::u1 _ec;
        Types::u1 _ee;
        Types::i1 _fc;
        Types::i1 _fe;
        Types::u2 _reserv;
        Types::u1 _cs;
    };
}
