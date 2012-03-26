#include "StdMessage.h"
#include <map>

using std::map;

#define CHAR2_TO_USHORT(c_id) ((((unsigned short)(c_id)[0]) << 8) | (c_id)[1])

namespace Greis
{
    EMessageId::Type StdMessage::MapIdStrToEnum( char* p_id )
    {
        static map<unsigned short, EMessageId::Type> cache;
        if (cache.size() == 0)
        {
            cache[CHAR2_TO_USHORT("AV")] = EMessageId::AngularVelocity;
            cache[CHAR2_TO_USHORT("AN")] = EMessageId::AntName;
            cache[CHAR2_TO_USHORT("BI")] = EMessageId::BaseInfo;
            cache[CHAR2_TO_USHORT("BL")] = EMessageId::BaseLine;
            cache[CHAR2_TO_USHORT("rT")] = EMessageId::ClockOffsets;
            cache[CHAR2_TO_USHORT("EC")] = EMessageId::CNR;
            cache[CHAR2_TO_USHORT("E1")] = EMessageId::CNR;
            cache[CHAR2_TO_USHORT("E2")] = EMessageId::CNR;
            cache[CHAR2_TO_USHORT("E3")] = EMessageId::CNR;
            cache[CHAR2_TO_USHORT("E5")] = EMessageId::CNR;
            cache[CHAR2_TO_USHORT("CE")] = EMessageId::CNR4;
            cache[CHAR2_TO_USHORT("1E")] = EMessageId::CNR4;
            cache[CHAR2_TO_USHORT("2E")] = EMessageId::CNR4;
            cache[CHAR2_TO_USHORT("3E")] = EMessageId::CNR4;
            cache[CHAR2_TO_USHORT("5E")] = EMessageId::CNR4;
            cache[CHAR2_TO_USHORT("PC")] = EMessageId::CP;
            cache[CHAR2_TO_USHORT("P1")] = EMessageId::CP;
            cache[CHAR2_TO_USHORT("P2")] = EMessageId::CP;
            cache[CHAR2_TO_USHORT("P3")] = EMessageId::CP;
            cache[CHAR2_TO_USHORT("P5")] = EMessageId::CP;
            cache[CHAR2_TO_USHORT("DP")] = EMessageId::Dops;
            cache[CHAR2_TO_USHORT("DC")] = EMessageId::DP;
            cache[CHAR2_TO_USHORT("D1")] = EMessageId::DP;
            cache[CHAR2_TO_USHORT("D2")] = EMessageId::DP;
            cache[CHAR2_TO_USHORT("D3")] = EMessageId::DP;
            cache[CHAR2_TO_USHORT("D5")] = EMessageId::DP;
            cache[CHAR2_TO_USHORT("||")] = EMessageId::EpochEnd;
            cache[CHAR2_TO_USHORT("::")] = EMessageId::EpochTime;
            cache[CHAR2_TO_USHORT("ER")] = EMessageId::ER;
            cache[CHAR2_TO_USHORT("==")] = EMessageId::Event;
            cache[CHAR2_TO_USHORT("XA")] = EMessageId::ExtEvent;
            cache[CHAR2_TO_USHORT("XB")] = EMessageId::ExtEvent;
            cache[CHAR2_TO_USHORT("JP")] = EMessageId::FileId;
            cache[CHAR2_TO_USHORT("FC")] = EMessageId::Flags;
            cache[CHAR2_TO_USHORT("F1")] = EMessageId::Flags;
            cache[CHAR2_TO_USHORT("F2")] = EMessageId::Flags;
            cache[CHAR2_TO_USHORT("F3")] = EMessageId::Flags;
            cache[CHAR2_TO_USHORT("F5")] = EMessageId::Flags;
            cache[CHAR2_TO_USHORT("EA")] = EMessageId::GALAlm;
            cache[CHAR2_TO_USHORT("EN")] = EMessageId::GALEphemeris;
            cache[CHAR2_TO_USHORT("ED")] = EMessageId::GALRawMessage;
            cache[CHAR2_TO_USHORT("EU")] = EMessageId::GalUtcGpsParam;
            cache[CHAR2_TO_USHORT("PG")] = EMessageId::GeoPos;
            cache[CHAR2_TO_USHORT("VG")] = EMessageId::GeoVel;
            cache[CHAR2_TO_USHORT("NA")] = EMessageId::GLOAlmanac;
            cache[CHAR2_TO_USHORT("NE")] = EMessageId::GLOEphemeris;
            cache[CHAR2_TO_USHORT("LD")] = EMessageId::GloNavData;
            cache[CHAR2_TO_USHORT("gC")] = EMessageId::GloPhaseDelay;
            cache[CHAR2_TO_USHORT("g1")] = EMessageId::GloPhaseDelay;
            cache[CHAR2_TO_USHORT("g2")] = EMessageId::GloPhaseDelay;
            cache[CHAR2_TO_USHORT("g3")] = EMessageId::GloPhaseDelay;
            cache[CHAR2_TO_USHORT("NT")] = EMessageId::GLOTime;
            cache[CHAR2_TO_USHORT("NU")] = EMessageId::GloUtcGpsParam;
            cache[CHAR2_TO_USHORT("GA")] = EMessageId::GPSAlm0;
            cache[CHAR2_TO_USHORT("GE")] = EMessageId::GPSEphemeris0;
            cache[CHAR2_TO_USHORT("GD")] = EMessageId::GpsNavData;
            cache[CHAR2_TO_USHORT("GT")] = EMessageId::GPSTime;
            cache[CHAR2_TO_USHORT("UO")] = EMessageId::GpsUtcParam;
            cache[CHAR2_TO_USHORT("IM")] = EMessageId::InertialMeasurements;
            cache[CHAR2_TO_USHORT("ID")] = EMessageId::IonoDelay;
            cache[CHAR2_TO_USHORT("IO")] = EMessageId::IonoParams;
            cache[CHAR2_TO_USHORT("LT")] = EMessageId::Latency;
            cache[CHAR2_TO_USHORT("LH")] = EMessageId::LoggingHistory;
            cache[CHAR2_TO_USHORT("MF")] = EMessageId::MsgFmt;
            cache[CHAR2_TO_USHORT("SS")] = EMessageId::NavStatus;
            cache[CHAR2_TO_USHORT("PM")] = EMessageId::Params;
            cache[CHAR2_TO_USHORT("PO")] = EMessageId::Pos;
            cache[CHAR2_TO_USHORT("PT")] = EMessageId::PosCompTime;
            cache[CHAR2_TO_USHORT("SP")] = EMessageId::PosCov;
            cache[CHAR2_TO_USHORT("PS")] = EMessageId::PosStat;
            cache[CHAR2_TO_USHORT("PV")] = EMessageId::PosVel;
            cache[CHAR2_TO_USHORT("rV")] = EMessageId::PosVelVector;
            cache[CHAR2_TO_USHORT("ZA")] = EMessageId::PPSOffset;
            cache[CHAR2_TO_USHORT("ZB")] = EMessageId::PPSOffset;
            cache[CHAR2_TO_USHORT("RC")] = EMessageId::PR;
            cache[CHAR2_TO_USHORT("R1")] = EMessageId::PR;
            cache[CHAR2_TO_USHORT("R2")] = EMessageId::PR;
            cache[CHAR2_TO_USHORT("R3")] = EMessageId::PR;
            cache[CHAR2_TO_USHORT("R5")] = EMessageId::PR;
            cache[CHAR2_TO_USHORT("rM")] = EMessageId::RawMeas;
            cache[CHAR2_TO_USHORT("cp")] = EMessageId::RCPRc1;
            cache[CHAR2_TO_USHORT("1p")] = EMessageId::RCPRc1;
            cache[CHAR2_TO_USHORT("2p")] = EMessageId::RCPRc1;
            cache[CHAR2_TO_USHORT("3p")] = EMessageId::RCPRc1;
            cache[CHAR2_TO_USHORT("5p")] = EMessageId::RCPRc1;
            cache[CHAR2_TO_USHORT("CP")] = EMessageId::RCPRC0;
            cache[CHAR2_TO_USHORT("1P")] = EMessageId::RCPRC0;
            cache[CHAR2_TO_USHORT("2P")] = EMessageId::RCPRC0;
            cache[CHAR2_TO_USHORT("3P")] = EMessageId::RCPRC0;
            cache[CHAR2_TO_USHORT("5P")] = EMessageId::RCPRC0;
            cache[CHAR2_TO_USHORT("RD")] = EMessageId::RcvDate;
            cache[CHAR2_TO_USHORT("EO")] = EMessageId::RcvGALTimeOffset;
            cache[CHAR2_TO_USHORT("NO")] = EMessageId::RcvGLOTimeOffset;
            cache[CHAR2_TO_USHORT("GO")] = EMessageId::RcvGPSTimeOffset;
            cache[CHAR2_TO_USHORT("OO")] = EMessageId::RcvOscOffs;
            cache[CHAR2_TO_USHORT("~~")] = EMessageId::RcvTime;
            cache[CHAR2_TO_USHORT("BP")] = EMessageId::RcvTimeAccuracy;
            cache[CHAR2_TO_USHORT("YA")] = EMessageId::RcvTimeOffsAtPPS;
            cache[CHAR2_TO_USHORT("YB")] = EMessageId::RcvTimeOffsAtPPS;
            cache[CHAR2_TO_USHORT("TO")] = EMessageId::RcvTimeOffset;
            cache[CHAR2_TO_USHORT("DO")] = EMessageId::RcvTimeOffsetDot;
            cache[CHAR2_TO_USHORT("WO")] = EMessageId::RcvWAASTimeOffset;
            cache[CHAR2_TO_USHORT("RE")] = EMessageId::RE;
            cache[CHAR2_TO_USHORT("rE")] = EMessageId::RefEpoch;
            cache[CHAR2_TO_USHORT("SG")] = EMessageId::Rms;
            cache[CHAR2_TO_USHORT("AR")] = EMessageId::RotationAngles;
            cache[CHAR2_TO_USHORT("MR")] = EMessageId::RotationMatrix;
            cache[CHAR2_TO_USHORT("mr")] = EMessageId::RotationMatrixAndVectors;
            cache[CHAR2_TO_USHORT("1R")] = EMessageId::RPR;
            cache[CHAR2_TO_USHORT("2R")] = EMessageId::RPR;
            cache[CHAR2_TO_USHORT("3R")] = EMessageId::RPR;
            cache[CHAR2_TO_USHORT("5R")] = EMessageId::RPR;
            cache[CHAR2_TO_USHORT("AZ")] = EMessageId::SatAzimuth;
            cache[CHAR2_TO_USHORT("EL")] = EMessageId::SatElevation;
            cache[CHAR2_TO_USHORT("SI")] = EMessageId::SatIndex;
            cache[CHAR2_TO_USHORT("NN")] = EMessageId::SatNumbers;
            cache[CHAR2_TO_USHORT("CC")] = EMessageId::SC;
            cache[CHAR2_TO_USHORT("C1")] = EMessageId::SC;
            cache[CHAR2_TO_USHORT("C2")] = EMessageId::SC;
            cache[CHAR2_TO_USHORT("C3")] = EMessageId::SC;
            cache[CHAR2_TO_USHORT("C5")] = EMessageId::SC;
            cache[CHAR2_TO_USHORT("pc")] = EMessageId::SCP;
            cache[CHAR2_TO_USHORT("p1")] = EMessageId::SCP;
            cache[CHAR2_TO_USHORT("p2")] = EMessageId::SCP;
            cache[CHAR2_TO_USHORT("p3")] = EMessageId::SCP;
            cache[CHAR2_TO_USHORT("p5")] = EMessageId::SCP;
            cache[CHAR2_TO_USHORT("SE")] = EMessageId::Security0;
            cache[CHAR2_TO_USHORT("SM")] = EMessageId::Security1;
            cache[CHAR2_TO_USHORT("ST")] = EMessageId::SolutionTime;
            cache[CHAR2_TO_USHORT("rc")] = EMessageId::SPR;
            cache[CHAR2_TO_USHORT("r1")] = EMessageId::SPR;
            cache[CHAR2_TO_USHORT("r2")] = EMessageId::SPR;
            cache[CHAR2_TO_USHORT("r3")] = EMessageId::SPR;
            cache[CHAR2_TO_USHORT("r5")] = EMessageId::SPR;
            cache[CHAR2_TO_USHORT("1d")] = EMessageId::SRDP;
            cache[CHAR2_TO_USHORT("2d")] = EMessageId::SRDP;
            cache[CHAR2_TO_USHORT("3d")] = EMessageId::SRDP;
            cache[CHAR2_TO_USHORT("5d")] = EMessageId::SRDP;
            cache[CHAR2_TO_USHORT("1r")] = EMessageId::SRPR;
            cache[CHAR2_TO_USHORT("2r")] = EMessageId::SRPR;
            cache[CHAR2_TO_USHORT("3r")] = EMessageId::SRPR;
            cache[CHAR2_TO_USHORT("5r")] = EMessageId::SRPR;
            cache[CHAR2_TO_USHORT("cc")] = EMessageId::SS;
            cache[CHAR2_TO_USHORT("c1")] = EMessageId::SS;
            cache[CHAR2_TO_USHORT("c2")] = EMessageId::SS;
            cache[CHAR2_TO_USHORT("c3")] = EMessageId::SS;
            cache[CHAR2_TO_USHORT("c5")] = EMessageId::SS;
            cache[CHAR2_TO_USHORT("TT")] = EMessageId::TrackingTime;
            cache[CHAR2_TO_USHORT("TC")] = EMessageId::TrackingTimeCA;
            cache[CHAR2_TO_USHORT("VE")] = EMessageId::Vel;
            cache[CHAR2_TO_USHORT("SV")] = EMessageId::VelCov;
            cache[CHAR2_TO_USHORT("WA")] = EMessageId::WAASAlmanac;
            cache[CHAR2_TO_USHORT("WE")] = EMessageId::WAASEhemeris;
            cache[CHAR2_TO_USHORT("WD")] = EMessageId::WAASRawMessage;
            cache[CHAR2_TO_USHORT("WU")] = EMessageId::WaasUtcParam;
            cache[CHAR2_TO_USHORT(">>")] = EMessageId::Wrapper;
        }
        auto it = cache.find(CHAR2_TO_USHORT(p_id));

        return it != cache.end() 
            ? it->second 
            : EMessageId::Unknown;
    }
}
