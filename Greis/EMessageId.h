#ifndef EMessageId_h__
#define EMessageId_h__

namespace Greis
{
    struct EMessageId
    {
        enum Type
        {
            Unknown,
            AngularVelocity, // [AV] Angular Velocities
            AntName, // [AN] Antenna Names
            BaseInfo, // [BI] Base Station Information
            BaseLine, // [BL] Base Line
            ClockOffsets, // [rT] Receiver Clock Offsets
            CNR, // [EC], [E1], [E2], [E3], [E5]: Carrier to Noise Ratio
            CNR4, // [CE], [1E], [2E], [3E], [5E]: Carrier to Noise Ratio x 
            CP, // [PC], [P1], [P2], [P3], [P5]: Carrier Phases
            Dops, // [DP] Dilution of Precision (DOP)
            DP, // [DC], [D1], [D2], [D3], [D5]: Doppler
            EpochEnd, // [||](EE) Epoch End
            EpochTime, // [::](ET) Epoch Time
            ER, // [ER] Error
            Event, // [==](EV) Event
            ExtEvent, // [XA], [XB] External Event
            FileId, // [JP] File Identifier
            Flags, // [FC], [F1], [F2], [F3], [F5]: Signal Lock Loop Flags
            GALAlm, // [EA] GALILEO Almanac
            GALEphemeris, // [EN] GALILEO Ephemeris
            GALRawMessage, // [ED] GALILEO Raw Navigation Data
            GalUtcGpsParam, // [EU] GALILEO UTC and GPS Time Parameters
            GeoPos, // [PG] Geodetic Position
            GeoVel, // [VG] Geodetic Velocity
            GLOAlmanac, // [NA] GLONASS Almanac
            GLOEphemeris, // [NE] GLONASS Ephemeris
            GloNavData, // [LD] GLONASS Raw Navigation Data
            GloPhaseDelay, // [gC], [g1], [g2], [g3]: GLONASS Phase Delays
            GLOTime, // [NT] GLONASS Time
            GloUtcGpsParam, // [NU] GLONASS UTC and GPS Time Parameters
            GPSAlm0, // [GA] GPS Almanac
            GPSEphemeris0, // [GE] GPS Ephemeris
            GpsNavData, // [GD] GPS Raw Navigation Data
            GPSTime, // [GT] GPS Time
            GpsUtcParam, // [UO] GPS UTC Time Parameters
            InertialMeasurements, // [IM] Inertial Measurements
            IonoDelay, // [ID] Ionospheric Delays
            IonoParams, // [IO] Ionospheric Parameters
            Latency, // [LT] Message Output Latency
            LoggingHistory, // [LH] Logging History
            MsgFmt, // [MF] Messages Format
            NavStatus, // [SS] Satellite Navigation Status
            Params, // [PM] Parameters
            Pos, // [PO] Cartesian Position
            PosCompTime, // [PT] Time of Continuous Position Computation
            PosCov, // [SP] Position Covariance Matrix
            PosStat, // [PS] Position Statistics
            PosVel, // [PV] Cartesian Position and Velocity
            PosVelVector, // [rV] Receiver’s Position and Velocity
            PPSOffset, // [ZA], [ZB] PPS Offset
            PR, // [RC], [R1], [R2], [R3], [R5]: Pseudoranges
            RawMeas, // [rM] Raw Measurements
            RCPRc1, // [cp], [1p], [2p], [3p], [5p]: Short Relative Carrier Phases
            RCPRC0, // [CP], [1P], [2P], [3P], [5P]: Short Relative Carrier Phases
            RcvDate, // [RD] Receiver Date
            RcvGALTimeOffset, // [EO] GALILEO to Receiver Time Offset
            RcvGLOTimeOffset, // [NO] GLONASS to Receiver Time Offset
            RcvGPSTimeOffset, // [GO] GPS to Receiver Time Offset
            RcvOscOffs, // [OO] Oscillator Offset
            RcvTime, // [~~](RT) Receiver Time
            RcvTimeAccuracy, // [BP] Rough Accuracy of Time Approximation
            RcvTimeOffsAtPPS, // [YA], [YB] Time Offset at PPS Generation Time
            RcvTimeOffset, // [TO] Reference Time to Receiver Time Offset
            RcvTimeOffsetDot, // [DO] Derivative of Receiver Time Offset
            RcvWAASTimeOffset, // [WO] WAAS to Receiver Time Offset
            RE, // [RE] Reply
            RefEpoch, // [rE] Reference Epoch
            Rms, // [SG] Position and Velocity RMS Errors
            RotationAngles, // [AR] Rotation Angles
            RotationMatrix, // [MR] Rotation Matrix
            RotationMatrixAndVectors, // [mr] Rotation Matrix and Vectors
            RPR, // [1R], [2R], [3R], [5R]: Relative Pseudoranges
            SatAzimuth, // [AZ] Satellite Azimuths
            SatElevation, // [EL] Satellite Elevations
            SatIndex, // [SI] Satellite Indices
            SatNumbers, // [NN] GLONASS Satellite System Numbers
            SC, // [CC], [C1], [C2], [C3], [C5]: Smoothing Corrections
            SCP, // [pc], [p1], [p2], [p3], [p5]: Short Carrier Phases
            Security0, // [SE] Security
            Security1, // [SM] Security for [rM]
            SolutionTime, // [ST] Solution Time-Tag
            SPR, // [rc], [r1], [r2], [r3], [r5]: Short Pseudoranges
            SRDP, // [1d], [2d], [3d], [5d]: Short Relative Doppler
            SRPR, // [1r], [2r], [3r], [5r]: Short Relative Pseudoranges
            SS, // [cc], [c1], [c2], [c3], [c5]: Short Smoothing Corrections
            TrackingTime, // [TT] CA/L1 Overall Continuous Tracking Time
            TrackingTimeCA, // [TC] CA/L1 Continuous Tracking Time
            Vel, // [VE] Cartesian Velocity
            VelCov, // [SV] Velocity Covariance Matrix
            WAASAlmanac, // [WA] WAAS Almanac
            WAASEhemeris, // [WE] WAAS Ephemeris
            WAASRawMessage, // [WD] WAAS Raw Navigation Data
            WaasUtcParam, // [WU] WAAS UTC Time Parameters
            Wrapper // [>>] Wrapper
        };
    };
}

#endif // EMessageId_h__
