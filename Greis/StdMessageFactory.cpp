#include "StdMessageFactory.h"
#include "ProjectBase/Logger.h"
#include "RawStdMessage.h"
#include "AllStdMessages.h"

namespace Greis
{
    StdMessage::UniquePtr_t StdMessageFactory::Create( char* p_message, int p_length )
    {
#ifdef _DEBUG
        sLogger.Debug(QString("StdMessageFactory::Create: creating standard message with id `%1`...").
            arg(QString::fromAscii(p_message, 2)));
#endif
        auto id = StdMessage::MapIdStrToEnum(p_message);
        switch (id)
        {
        case EMessageId::AngularVelocity:
            return StdMessage::UniquePtr_t(new AngularVelocityStdMessage(p_message, p_length));
        case EMessageId::AntName:
            return StdMessage::UniquePtr_t(new AntNameStdMessage(p_message, p_length));
        case EMessageId::BaseInfo:
            return StdMessage::UniquePtr_t(new BaseInfoStdMessage(p_message, p_length));
        case EMessageId::Baseline:
            return StdMessage::UniquePtr_t(new BaselineStdMessage(p_message, p_length));
        case EMessageId::ClockOffsets:
            return StdMessage::UniquePtr_t(new ClockOffsetsStdMessage(p_message, p_length));
        case EMessageId::CNR:
            return StdMessage::UniquePtr_t(new CNRStdMessage(p_message, p_length));
        case EMessageId::CNR4:
            return StdMessage::UniquePtr_t(new CNR4StdMessage(p_message, p_length));
        case EMessageId::CompRawNavData:
            return StdMessage::UniquePtr_t(new CompRawNavDataStdMessage(p_message, p_length));
        case EMessageId::CP:
            return StdMessage::UniquePtr_t(new CPStdMessage(p_message, p_length));
        case EMessageId::Dops:
            return StdMessage::UniquePtr_t(new DopsStdMessage(p_message, p_length));
        case EMessageId::DP:
            return StdMessage::UniquePtr_t(new DPStdMessage(p_message, p_length));
        case EMessageId::EpochEnd:
            return StdMessage::UniquePtr_t(new EpochEndStdMessage(p_message, p_length));
        case EMessageId::EpochTime:
            return StdMessage::UniquePtr_t(new EpochTimeStdMessage(p_message, p_length));
        case EMessageId::ER:
            return StdMessage::UniquePtr_t(new ERStdMessage(p_message, p_length));
        case EMessageId::Event:
            return StdMessage::UniquePtr_t(new EventStdMessage(p_message, p_length));
        case EMessageId::ExtEvent:
            return StdMessage::UniquePtr_t(new ExtEventStdMessage(p_message, p_length));
        case EMessageId::FileId:
            return StdMessage::UniquePtr_t(new FileIdStdMessage(p_message, p_length));
        case EMessageId::Flags:
            return StdMessage::UniquePtr_t(new FlagsStdMessage(p_message, p_length));
        case EMessageId::GALAlm:
            return StdMessage::UniquePtr_t(new GALAlmStdMessage(p_message, p_length));
        case EMessageId::GALEphemeris:
            return StdMessage::UniquePtr_t(new GALEphemerisStdMessage(p_message, p_length));
        case EMessageId::GalRawNavData:
            return StdMessage::UniquePtr_t(new GalRawNavDataStdMessage(p_message, p_length));
        case EMessageId::GalUtcGpsParam:
            return StdMessage::UniquePtr_t(new GalUtcGpsParamStdMessage(p_message, p_length));
        case EMessageId::GeoPos:
            return StdMessage::UniquePtr_t(new GeoPosStdMessage(p_message, p_length));
        case EMessageId::GeoVel:
            return StdMessage::UniquePtr_t(new GeoVelStdMessage(p_message, p_length));
        case EMessageId::GLOAlmanac:
            return StdMessage::UniquePtr_t(new GLOAlmanacStdMessage(p_message, p_length));
        case EMessageId::GLOEphemeris:
            return StdMessage::UniquePtr_t(new GLOEphemerisStdMessage(p_message, p_length));
        case EMessageId::GloNavData:
            return StdMessage::UniquePtr_t(new GloNavDataStdMessage(p_message, p_length));
        case EMessageId::GloPhaseDelay:
            return StdMessage::UniquePtr_t(new GloPhaseDelayStdMessage(p_message, p_length));
        case EMessageId::GloRawNavData:
            return StdMessage::UniquePtr_t(new GloRawNavDataStdMessage(p_message, p_length));
        case EMessageId::GLOTime:
            return StdMessage::UniquePtr_t(new GLOTimeStdMessage(p_message, p_length));
        case EMessageId::GloUtcGpsParam:
            return StdMessage::UniquePtr_t(new GloUtcGpsParamStdMessage(p_message, p_length));
        case EMessageId::GPSAlm0:
            return StdMessage::UniquePtr_t(new GPSAlm0StdMessage(p_message, p_length));
        case EMessageId::GPSEphemeris0:
            return StdMessage::UniquePtr_t(new GPSEphemeris0StdMessage(p_message, p_length));
        case EMessageId::GpsNavData0:
            return StdMessage::UniquePtr_t(new GpsNavData0StdMessage(p_message, p_length));
        case EMessageId::GpsRawNavData0:
            return StdMessage::UniquePtr_t(new GpsRawNavData0StdMessage(p_message, p_length));
        case EMessageId::GPSTime:
            return StdMessage::UniquePtr_t(new GPSTimeStdMessage(p_message, p_length));
        case EMessageId::GpsUtcParam:
            return StdMessage::UniquePtr_t(new GpsUtcParamStdMessage(p_message, p_length));
        case EMessageId::IAmp:
            return StdMessage::UniquePtr_t(new IAmpStdMessage(p_message, p_length));
        case EMessageId::InertialMeasurements:
            return StdMessage::UniquePtr_t(new InertialMeasurementsStdMessage(p_message, p_length));
        case EMessageId::IonoDelay:
            return StdMessage::UniquePtr_t(new IonoDelayStdMessage(p_message, p_length));
        case EMessageId::IonoParams0:
            return StdMessage::UniquePtr_t(new IonoParams0StdMessage(p_message, p_length));
        case EMessageId::Latency:
            return StdMessage::UniquePtr_t(new LatencyStdMessage(p_message, p_length));
        case EMessageId::LoggingHistory:
            return StdMessage::UniquePtr_t(new LoggingHistoryStdMessage(p_message, p_length));
        case EMessageId::MsgFmt:
            return StdMessage::UniquePtr_t(new MsgFmtStdMessage(p_message, p_length));
        case EMessageId::NavStatus:
            return StdMessage::UniquePtr_t(new NavStatusStdMessage(p_message, p_length));
        case EMessageId::Params:
            return StdMessage::UniquePtr_t(new ParamsStdMessage(p_message, p_length));
        case EMessageId::Pos:
            return StdMessage::UniquePtr_t(new PosStdMessage(p_message, p_length));
        case EMessageId::PosCompTime:
            return StdMessage::UniquePtr_t(new PosCompTimeStdMessage(p_message, p_length));
        case EMessageId::PosCov:
            return StdMessage::UniquePtr_t(new PosCovStdMessage(p_message, p_length));
        case EMessageId::PosStat:
            return StdMessage::UniquePtr_t(new PosStatStdMessage(p_message, p_length));
        case EMessageId::PosVel:
            return StdMessage::UniquePtr_t(new PosVelStdMessage(p_message, p_length));
        case EMessageId::PosVelVector:
            return StdMessage::UniquePtr_t(new PosVelVectorStdMessage(p_message, p_length));
        case EMessageId::PPSOffset:
            return StdMessage::UniquePtr_t(new PPSOffsetStdMessage(p_message, p_length));
        case EMessageId::PR:
            return StdMessage::UniquePtr_t(new PRStdMessage(p_message, p_length));
        case EMessageId::QAmp:
            return StdMessage::UniquePtr_t(new QAmpStdMessage(p_message, p_length));
        case EMessageId::QZSSAlm:
            return StdMessage::UniquePtr_t(new QZSSAlmStdMessage(p_message, p_length));
        case EMessageId::QZSSEphemeris:
            return StdMessage::UniquePtr_t(new QZSSEphemerisStdMessage(p_message, p_length));
        case EMessageId::QzssIonoParams:
            return StdMessage::UniquePtr_t(new QzssIonoParamsStdMessage(p_message, p_length));
        case EMessageId::QzssNavData:
            return StdMessage::UniquePtr_t(new QzssNavDataStdMessage(p_message, p_length));
        case EMessageId::QzssRawNavData:
            return StdMessage::UniquePtr_t(new QzssRawNavDataStdMessage(p_message, p_length));
        case EMessageId::QzssUtcParam:
            return StdMessage::UniquePtr_t(new QzssUtcParamStdMessage(p_message, p_length));
        case EMessageId::RawMeas:
            return StdMessage::UniquePtr_t(new RawMeasStdMessage(p_message, p_length));
        case EMessageId::RCPRc1:
            return StdMessage::UniquePtr_t(new RCPRc1StdMessage(p_message, p_length));
        case EMessageId::RCPRC0:
            return StdMessage::UniquePtr_t(new RCPRC0StdMessage(p_message, p_length));
        case EMessageId::RcvDate:
            return StdMessage::UniquePtr_t(new RcvDateStdMessage(p_message, p_length));
        case EMessageId::RcvGALTimeOffset:
            return StdMessage::UniquePtr_t(new RcvGALTimeOffsetStdMessage(p_message, p_length));
        case EMessageId::RcvGLOTimeOffset:
            return StdMessage::UniquePtr_t(new RcvGLOTimeOffsetStdMessage(p_message, p_length));
        case EMessageId::RcvGPSTimeOffset:
            return StdMessage::UniquePtr_t(new RcvGPSTimeOffsetStdMessage(p_message, p_length));
        case EMessageId::RcvOscOffs:
            return StdMessage::UniquePtr_t(new RcvOscOffsStdMessage(p_message, p_length));
        case EMessageId::RcvQZSSTimeOffset:
            return StdMessage::UniquePtr_t(new RcvQZSSTimeOffsetStdMessage(p_message, p_length));
        case EMessageId::RcvSBASTimeOffset:
            return StdMessage::UniquePtr_t(new RcvSBASTimeOffsetStdMessage(p_message, p_length));
        case EMessageId::RcvTime:
            return StdMessage::UniquePtr_t(new RcvTimeStdMessage(p_message, p_length));
        case EMessageId::RcvTimeAccuracy:
            return StdMessage::UniquePtr_t(new RcvTimeAccuracyStdMessage(p_message, p_length));
        case EMessageId::RcvTimeOffsAtPPS:
            return StdMessage::UniquePtr_t(new RcvTimeOffsAtPPSStdMessage(p_message, p_length));
        case EMessageId::RcvTimeOffset:
            return StdMessage::UniquePtr_t(new RcvTimeOffsetStdMessage(p_message, p_length));
        case EMessageId::RcvTimeOffsetDot:
            return StdMessage::UniquePtr_t(new RcvTimeOffsetDotStdMessage(p_message, p_length));
        case EMessageId::RE:
            return StdMessage::UniquePtr_t(new REStdMessage(p_message, p_length));
        case EMessageId::RefEpoch:
            return StdMessage::UniquePtr_t(new RefEpochStdMessage(p_message, p_length));
        case EMessageId::Rms:
            return StdMessage::UniquePtr_t(new RmsStdMessage(p_message, p_length));
        case EMessageId::RotationAngles:
            return StdMessage::UniquePtr_t(new RotationAnglesStdMessage(p_message, p_length));
        case EMessageId::RotationMatrix:
            return StdMessage::UniquePtr_t(new RotationMatrixStdMessage(p_message, p_length));
        case EMessageId::RotationMatrixAndVectors:
            return StdMessage::UniquePtr_t(new RotationMatrixAndVectorsStdMessage(p_message, p_length));
        case EMessageId::RPR:
            return StdMessage::UniquePtr_t(new RPRStdMessage(p_message, p_length));
        case EMessageId::SatAzimuth:
            return StdMessage::UniquePtr_t(new SatAzimuthStdMessage(p_message, p_length));
        case EMessageId::SatElevation:
            return StdMessage::UniquePtr_t(new SatElevationStdMessage(p_message, p_length));
        case EMessageId::SatIndex:
            return StdMessage::UniquePtr_t(new SatIndexStdMessage(p_message, p_length));
        case EMessageId::SatNumbers:
            return StdMessage::UniquePtr_t(new SatNumbersStdMessage(p_message, p_length));
        case EMessageId::SBASAlmanac:
            return StdMessage::UniquePtr_t(new SBASAlmanacStdMessage(p_message, p_length));
        case EMessageId::SBASEhemeris:
            return StdMessage::UniquePtr_t(new SBASEhemerisStdMessage(p_message, p_length));
        case EMessageId::SbasRawNavData:
            return StdMessage::UniquePtr_t(new SbasRawNavDataStdMessage(p_message, p_length));
        case EMessageId::SbasUtcParam:
            return StdMessage::UniquePtr_t(new SbasUtcParamStdMessage(p_message, p_length));
        case EMessageId::SC:
            return StdMessage::UniquePtr_t(new SCStdMessage(p_message, p_length));
        case EMessageId::SCP:
            return StdMessage::UniquePtr_t(new SCPStdMessage(p_message, p_length));
        case EMessageId::Security0:
            return StdMessage::UniquePtr_t(new Security0StdMessage(p_message, p_length));
        case EMessageId::Security1:
            return StdMessage::UniquePtr_t(new Security1StdMessage(p_message, p_length));
        case EMessageId::SolutionTime:
            return StdMessage::UniquePtr_t(new SolutionTimeStdMessage(p_message, p_length));
        case EMessageId::Spectrum0:
            return StdMessage::UniquePtr_t(new Spectrum0StdMessage(p_message, p_length));
        case EMessageId::Spectrum1:
            return StdMessage::UniquePtr_t(new Spectrum1StdMessage(p_message, p_length));
        case EMessageId::SPR:
            return StdMessage::UniquePtr_t(new SPRStdMessage(p_message, p_length));
        case EMessageId::SRDP:
            return StdMessage::UniquePtr_t(new SRDPStdMessage(p_message, p_length));
        case EMessageId::SRPR:
            return StdMessage::UniquePtr_t(new SRPRStdMessage(p_message, p_length));
        case EMessageId::SS:
            return StdMessage::UniquePtr_t(new SSStdMessage(p_message, p_length));
        case EMessageId::TrackingTime:
            return StdMessage::UniquePtr_t(new TrackingTimeStdMessage(p_message, p_length));
        case EMessageId::TrackingTimeCA:
            return StdMessage::UniquePtr_t(new TrackingTimeCAStdMessage(p_message, p_length));
        case EMessageId::Vel:
            return StdMessage::UniquePtr_t(new VelStdMessage(p_message, p_length));
        case EMessageId::VelCov:
            return StdMessage::UniquePtr_t(new VelCovStdMessage(p_message, p_length));
        case EMessageId::Wrapper:
            return StdMessage::UniquePtr_t(new WrapperStdMessage(p_message, p_length));
        default:
            return StdMessage::UniquePtr_t(new RawStdMessage(p_message, p_length));
        }
    }
}
