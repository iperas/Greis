#include "MySqlSink.h"
#include "ProjectBase\Connection.h"
#include "AllStdMessages.h"

using namespace ProjectBase;

namespace Greis
{
    MySqlSink::MySqlSink(Connection* connection, int inserterBatchSize)
    {
        _connection = connection;
        _dbHelper = _connection->DbHelper();
        _inserterBatchSize = inserterBatchSize;
        
        construct();

        auto angularVelocityInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_AngularVelocity` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `x`, `y`, `z`, `rms`, `flags`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            11, _connection, "msg_AngularVelocity", _inserterBatchSize);
        auto antNameInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_AntName` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `name`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_AntName", _inserterBatchSize);
        auto baseInfoInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_BaseInfo` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `id_sugar`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_BaseInfo", _inserterBatchSize);
        auto baseLineInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_BaseLine` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `time`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            11, _connection, "msg_BaseLine", _inserterBatchSize);
        auto clockOffsetsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_ClockOffsets` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `reserved`, `recSize`, `Offs`, `crc16`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "msg_ClockOffsets", _inserterBatchSize);
        auto cNRInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_CNR` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnr`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_CNR", _inserterBatchSize);
        auto cNR4Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_CNR_4` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnrX4`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_CNR_4", _inserterBatchSize);
        auto cPInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_CP` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_CP", _inserterBatchSize);
        auto dopsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Dops` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hdop`, `vdop`, `tdop`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "msg_Dops", _inserterBatchSize);
        auto dPInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_DP` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `dp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_DP", _inserterBatchSize);
        auto epochEndInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_EpochEnd` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cs`) VALUES (?, ?, ?, ?, ?)", 
            5, _connection, "msg_EpochEnd", _inserterBatchSize);
        auto epochTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_EpochTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_EpochTime", _inserterBatchSize);
        auto eRInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_ER` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `error`) VALUES (?, ?, ?, ?, ?)", 
            5, _connection, "msg_ER", _inserterBatchSize);
        auto eventInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Event` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `type`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", 
            8, _connection, "msg_Event", _inserterBatchSize);
        auto extEventInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_ExtEvent` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ms`, `ns`, `timeScale`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", 
            8, _connection, "msg_ExtEvent", _inserterBatchSize);
        auto fileIdInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_FileId` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `description`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_FileId", _inserterBatchSize);
        auto flagsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Flags` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `flags`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_Flags", _inserterBatchSize);
        auto gALAlmInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GALAlm` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `iod`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GALAlm", _inserterBatchSize);
        auto gALEphemerisInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GALEphemeris` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `bgdE1E5a`, `bgdE1E5b`, `ai0`, `ai1`, `ai2`, `sfi`, `navType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            13, _connection, "msg_GALEphemeris", _inserterBatchSize);
        auto gALRawMessageInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GALRawMessage` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_GALRawMessage", _inserterBatchSize);
        auto galUtcGpsParamInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GalUtcGpsParam` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `a0g`, `a1g`, `t0g`, `wn0g`, `flags`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            11, _connection, "msg_GalUtcGpsParam", _inserterBatchSize);
        auto geoPosInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GeoPos` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_GeoPos", _inserterBatchSize);
        auto geoVelInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GeoVel` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_GeoVel", _inserterBatchSize);
        auto gLOAlmanacInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GLOAlmanac` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dna`, `tlam`, `flags`, `tauN`, `tauSys`, `ecc`, `lambda`, `argPer`, `delT`, `delTdt`, `deli`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            18, _connection, "msg_GLOAlmanac", _inserterBatchSize);
        auto gLOEphemerisInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GLOEphemeris` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dne`, `tk`, `tb`, `health`, `age`, `flags`, `r`, `v`, `w`, `tauSys`, `tau`, `gamma`, `fDelTauN`, `nFt`, `nN4`, `flags2`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            23, _connection, "msg_GLOEphemeris", _inserterBatchSize);
        auto gloNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GloNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GloNavData", _inserterBatchSize);
        auto gloPhaseDelayInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GloPhaseDelay` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `fcn`, `phase`, `range`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", 
            8, _connection, "msg_GloPhaseDelay", _inserterBatchSize);
        auto gLOTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GLOTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `dn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GLOTime", _inserterBatchSize);
        auto gloUtcGpsParamInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GloUtcGpsParam` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tauSys`, `tauGps`, `B1`, `B2`, `KP`, `N4`, `Dn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            12, _connection, "msg_GloUtcGpsParam", _inserterBatchSize);
        auto gPSAlm0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GPSAlm0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `healthS`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            20, _connection, "msg_GPSAlm0", _inserterBatchSize);
        auto gPSEphemeris0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GPSEphemeris0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `tow`, `flags`, `iodc`, `toc`, `ura`, `healthS`, `wn`, `tgd`, `af2`, `af1`, `af0`, `toe`, `iode`, `rootA`, `ecc`, `m0`, `omega0`, `inc0`, `argPer`, `deln`, `omegaDot`, `incDot`, `crc`, `crs`, `cuc`, `cus`, `cic`, `cis`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            34, _connection, "msg_GPSEphemeris0", _inserterBatchSize);
        auto gpsNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GpsNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GpsNavData", _inserterBatchSize);
        auto gPSTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GPSTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tow`, `wn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GPSTime", _inserterBatchSize);
        auto gpsUtcParamInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GpsUtcParam` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_GpsUtcParam", _inserterBatchSize);
        auto inertialMeasurementsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_InertialMeasurements` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `accelerations`, `angularVelocities`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_InertialMeasurements", _inserterBatchSize);
        auto ionoDelayInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_IonoDelay` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `delay`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_IonoDelay", _inserterBatchSize);
        auto ionoParamsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_IonoParams` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tot`, `wn`, `alpha0`, `alpha1`, `alpha2`, `alpha3`, `beta0`, `beta1`, `beta2`, `beta3`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            15, _connection, "msg_IonoParams", _inserterBatchSize);
        auto latencyInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Latency` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lt`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_Latency", _inserterBatchSize);
        auto loggingHistoryInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_LoggingHistory` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `svsCount`, `targetStream`, `issue`, `bitsCount`, `lastBitTime`, `uids`, `pad`, `hist`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            12, _connection, "msg_LoggingHistory", _inserterBatchSize);
        auto msgFmtInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_MsgFmt` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `majorVer`, `minorVer`, `order`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "msg_MsgFmt", _inserterBatchSize);
        auto navStatusInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_NavStatus` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ns`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_NavStatus", _inserterBatchSize);
        auto paramsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Params` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `params`, `delim`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_Params", _inserterBatchSize);
        auto posInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Pos` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_Pos", _inserterBatchSize);
        auto posCompTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_PosCompTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pt`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_PosCompTime", _inserterBatchSize);
        auto posCovInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_PosCov` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            16, _connection, "msg_PosCov", _inserterBatchSize);
        auto posStatInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_PosStat` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `solType`, `gpsLocked`, `gloLocked`, `gpsAvail`, `gloAvail`, `gpsUsed`, `gloUsed`, `fixProg`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            13, _connection, "msg_PosStat", _inserterBatchSize);
        auto posVelInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_PosVel` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `pSigma`, `vx`, `vy`, `vz`, `vSigma`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            14, _connection, "msg_PosVel", _inserterBatchSize);
        auto posVelVectorInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_PosVelVector` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `delta`, `word1`, `word2`, `word3`, `word4`, `word5`, `word6`, `word7`, `word8`, `word9`, `crc16`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            16, _connection, "msg_PosVelVector", _inserterBatchSize);
        auto pPSOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_PPSOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_PPSOffset", _inserterBatchSize);
        auto pRInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_PR` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pr`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_PR", _inserterBatchSize);
        auto rawMeasInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RawMeas` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `clock`, `flags`, `svd`, `crc16`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            11, _connection, "msg_RawMeas", _inserterBatchSize);
        auto rCPRc1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RCP_rc1` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_RCP_rc1", _inserterBatchSize);
        auto rCPRC0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RCP_RC0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_RCP_RC0", _inserterBatchSize);
        auto rcvDateInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvDate` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `year`, `month`, `day`, `base`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "msg_RcvDate", _inserterBatchSize);
        auto rcvGALTimeOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvGALTimeOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvGALTimeOffset", _inserterBatchSize);
        auto rcvGLOTimeOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvGLOTimeOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvGLOTimeOffset", _inserterBatchSize);
        auto rcvGPSTimeOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvGPSTimeOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvGPSTimeOffset", _inserterBatchSize);
        auto rcvOscOffsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvOscOffs` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_RcvOscOffs", _inserterBatchSize);
        auto rcvTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_RcvTime", _inserterBatchSize);
        auto rcvTimeAccuracyInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvTimeAccuracy` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `acc`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_RcvTimeAccuracy", _inserterBatchSize);
        auto rcvTimeOffsAtPPSInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvTimeOffsAtPPS` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `timeScale`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvTimeOffsAtPPS", _inserterBatchSize);
        auto rcvTimeOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvTimeOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvTimeOffset", _inserterBatchSize);
        auto rcvTimeOffsetDotInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvTimeOffsetDot` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvTimeOffsetDot", _inserterBatchSize);
        auto rcvWAASTimeOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvWAASTimeOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvWAASTimeOffset", _inserterBatchSize);
        auto rEInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RE` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `reply`) VALUES (?, ?, ?, ?, ?)", 
            5, _connection, "msg_RE", _inserterBatchSize);
        auto refEpochInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RefEpoch` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `crc16`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", 
            8, _connection, "msg_RefEpoch", _inserterBatchSize);
        auto rmsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Rms` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hpos`, `vpos`, `hvel`, `vvel`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_Rms", _inserterBatchSize);
        auto rotationAnglesInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RotationAngles` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `pitch`, `roll`, `heading`, `pitchRms`, `rollRms`, `headingRms`, `flags`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            13, _connection, "msg_RotationAngles", _inserterBatchSize);
        auto rotationMatrixInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RotationMatrix` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            13, _connection, "msg_RotationMatrix", _inserterBatchSize);
        auto rotationMatrixAndVectorsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RotationMatrixAndVectors` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `bl0`, `bl1`, `bl2`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            16, _connection, "msg_RotationMatrixAndVectors", _inserterBatchSize);
        auto rPRInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RPR` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rpr`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_RPR", _inserterBatchSize);
        auto satAzimuthInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SatAzimuth` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `azim`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SatAzimuth", _inserterBatchSize);
        auto satElevationInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SatElevation` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `elev`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SatElevation", _inserterBatchSize);
        auto satIndexInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SatIndex` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `usi`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SatIndex", _inserterBatchSize);
        auto satNumbersInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SatNumbers` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `osn`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SatNumbers", _inserterBatchSize);
        auto sCInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SC` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SC", _inserterBatchSize);
        auto sCPInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SCP` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `scp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SCP", _inserterBatchSize);
        auto security0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Security0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_Security0", _inserterBatchSize);
        auto security1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Security1` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `crc16`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_Security1", _inserterBatchSize);
        auto solutionTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SolutionTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_SolutionTime", _inserterBatchSize);
        auto sPRInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SPR` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `spr`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SPR", _inserterBatchSize);
        auto sRDPInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SRDP` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srdp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SRDP", _inserterBatchSize);
        auto sRPRInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SRPR` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srpr`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SRPR", _inserterBatchSize);
        auto sSInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SS` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_SS", _inserterBatchSize);
        auto trackingTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_TrackingTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_TrackingTime", _inserterBatchSize);
        auto trackingTimeCAInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_TrackingTimeCA` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_TrackingTimeCA", _inserterBatchSize);
        auto velInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Vel` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_Vel", _inserterBatchSize);
        auto velCovInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_VelCov` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            16, _connection, "msg_VelCov", _inserterBatchSize);
        auto wAASAlmanacInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_WAASAlmanac` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `id_sugar`, `healthS`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `tow`, `wn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            18, _connection, "msg_WAASAlmanac", _inserterBatchSize);
        auto wAASEhemerisInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_WAASEhemeris` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `iod`, `acc`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `vvxg`, `vvyg`, `vvzg`, `agf0`, `agf1`, `tow`, `wn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            23, _connection, "msg_WAASEhemeris", _inserterBatchSize);
        auto wAASRawMessageInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_WAASRawMessage` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `reserv`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "msg_WAASRawMessage", _inserterBatchSize);
        auto waasUtcParamInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_WaasUtcParam` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `utcsi`, `tow`, `wn`, `flags`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_WaasUtcParam", _inserterBatchSize);
        auto wrapperInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Wrapper` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_Wrapper", _inserterBatchSize);
        auto clkOffsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_ClkOffs` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `word1`, `word2`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "ct_ClkOffs", _inserterBatchSize);
        auto gPSAlm1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_GPSAlm1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `healthS`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            19, _connection, "ct_GPSAlm1", _inserterBatchSize);
        auto gPSEphemeris1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_GPSEphemeris1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `tow`, `flags`, `iodc`, `toc`, `ura`, `healthS`, `wn`, `tgd`, `af2`, `af1`, `af0`, `toe`, `iode`, `rootA`, `ecc`, `m0`, `omega0`, `inc0`, `argPer`, `deln`, `omegaDot`, `incDot`, `crc`, `crs`, `cuc`, `cus`, `cic`, `cis`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            33, _connection, "ct_GPSEphemeris1", _inserterBatchSize);
        auto headerInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_Header` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `refrange`, `usi`, `num`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "ct_Header", _inserterBatchSize);
        auto slotRecInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_SlotRec` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `svstOrDelrange`, `word1`, `flags`, `lock`, `word2`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "ct_SlotRec", _inserterBatchSize);
        auto smoothInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_Smooth` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `value`, `interval`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "ct_Smooth", _inserterBatchSize);
        auto svData0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_SvData0` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `prn`, `cnt`, `data`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "ct_SvData0", _inserterBatchSize);
        auto svData1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_SvData1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `fcn1`, `cnt`, `data`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "ct_SvData1", _inserterBatchSize);
        auto svData2Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_SvData2` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `header`, `slot`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "ct_SvData2", _inserterBatchSize);
        auto utcOffsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_UtcOffs` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `a0`, `a1`, `tot`, `wnt`, `dtls`, `dn`, `wnlsf`, `dtlsf`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            12, _connection, "ct_UtcOffs", _inserterBatchSize);

        clockOffsetsInserter->AddChild(clkOffsInserter);
        gALAlmInserter->AddChild(gPSAlm1Inserter);
        gALEphemerisInserter->AddChild(gPSEphemeris1Inserter);
        galUtcGpsParamInserter->AddChild(utcOffsInserter);
        gloNavDataInserter->AddChild(svData1Inserter);
        gpsNavDataInserter->AddChild(svData0Inserter);
        gpsUtcParamInserter->AddChild(utcOffsInserter);
        rawMeasInserter->AddChild(svData2Inserter);
        sCInserter->AddChild(smoothInserter);
        waasUtcParamInserter->AddChild(utcOffsInserter);
        svData2Inserter->AddChild(headerInserter);
        svData2Inserter->AddChild(slotRecInserter);

        _msgInserters[EMessageId::AngularVelocity] = angularVelocityInserter;
        _msgInserters[EMessageId::AntName] = antNameInserter;
        _msgInserters[EMessageId::BaseInfo] = baseInfoInserter;
        _msgInserters[EMessageId::BaseLine] = baseLineInserter;
        _msgInserters[EMessageId::ClockOffsets] = clockOffsetsInserter;
        _msgInserters[EMessageId::CNR] = cNRInserter;
        _msgInserters[EMessageId::CNR4] = cNR4Inserter;
        _msgInserters[EMessageId::CP] = cPInserter;
        _msgInserters[EMessageId::Dops] = dopsInserter;
        _msgInserters[EMessageId::DP] = dPInserter;
        _msgInserters[EMessageId::EpochEnd] = epochEndInserter;
        _msgInserters[EMessageId::EpochTime] = epochTimeInserter;
        _msgInserters[EMessageId::ER] = eRInserter;
        _msgInserters[EMessageId::Event] = eventInserter;
        _msgInserters[EMessageId::ExtEvent] = extEventInserter;
        _msgInserters[EMessageId::FileId] = fileIdInserter;
        _msgInserters[EMessageId::Flags] = flagsInserter;
        _msgInserters[EMessageId::GALAlm] = gALAlmInserter;
        _msgInserters[EMessageId::GALEphemeris] = gALEphemerisInserter;
        _msgInserters[EMessageId::GALRawMessage] = gALRawMessageInserter;
        _msgInserters[EMessageId::GalUtcGpsParam] = galUtcGpsParamInserter;
        _msgInserters[EMessageId::GeoPos] = geoPosInserter;
        _msgInserters[EMessageId::GeoVel] = geoVelInserter;
        _msgInserters[EMessageId::GLOAlmanac] = gLOAlmanacInserter;
        _msgInserters[EMessageId::GLOEphemeris] = gLOEphemerisInserter;
        _msgInserters[EMessageId::GloNavData] = gloNavDataInserter;
        _msgInserters[EMessageId::GloPhaseDelay] = gloPhaseDelayInserter;
        _msgInserters[EMessageId::GLOTime] = gLOTimeInserter;
        _msgInserters[EMessageId::GloUtcGpsParam] = gloUtcGpsParamInserter;
        _msgInserters[EMessageId::GPSAlm0] = gPSAlm0Inserter;
        _msgInserters[EMessageId::GPSEphemeris0] = gPSEphemeris0Inserter;
        _msgInserters[EMessageId::GpsNavData] = gpsNavDataInserter;
        _msgInserters[EMessageId::GPSTime] = gPSTimeInserter;
        _msgInserters[EMessageId::GpsUtcParam] = gpsUtcParamInserter;
        _msgInserters[EMessageId::InertialMeasurements] = inertialMeasurementsInserter;
        _msgInserters[EMessageId::IonoDelay] = ionoDelayInserter;
        _msgInserters[EMessageId::IonoParams] = ionoParamsInserter;
        _msgInserters[EMessageId::Latency] = latencyInserter;
        _msgInserters[EMessageId::LoggingHistory] = loggingHistoryInserter;
        _msgInserters[EMessageId::MsgFmt] = msgFmtInserter;
        _msgInserters[EMessageId::NavStatus] = navStatusInserter;
        _msgInserters[EMessageId::Params] = paramsInserter;
        _msgInserters[EMessageId::Pos] = posInserter;
        _msgInserters[EMessageId::PosCompTime] = posCompTimeInserter;
        _msgInserters[EMessageId::PosCov] = posCovInserter;
        _msgInserters[EMessageId::PosStat] = posStatInserter;
        _msgInserters[EMessageId::PosVel] = posVelInserter;
        _msgInserters[EMessageId::PosVelVector] = posVelVectorInserter;
        _msgInserters[EMessageId::PPSOffset] = pPSOffsetInserter;
        _msgInserters[EMessageId::PR] = pRInserter;
        _msgInserters[EMessageId::RawMeas] = rawMeasInserter;
        _msgInserters[EMessageId::RCPRc1] = rCPRc1Inserter;
        _msgInserters[EMessageId::RCPRC0] = rCPRC0Inserter;
        _msgInserters[EMessageId::RcvDate] = rcvDateInserter;
        _msgInserters[EMessageId::RcvGALTimeOffset] = rcvGALTimeOffsetInserter;
        _msgInserters[EMessageId::RcvGLOTimeOffset] = rcvGLOTimeOffsetInserter;
        _msgInserters[EMessageId::RcvGPSTimeOffset] = rcvGPSTimeOffsetInserter;
        _msgInserters[EMessageId::RcvOscOffs] = rcvOscOffsInserter;
        _msgInserters[EMessageId::RcvTime] = rcvTimeInserter;
        _msgInserters[EMessageId::RcvTimeAccuracy] = rcvTimeAccuracyInserter;
        _msgInserters[EMessageId::RcvTimeOffsAtPPS] = rcvTimeOffsAtPPSInserter;
        _msgInserters[EMessageId::RcvTimeOffset] = rcvTimeOffsetInserter;
        _msgInserters[EMessageId::RcvTimeOffsetDot] = rcvTimeOffsetDotInserter;
        _msgInserters[EMessageId::RcvWAASTimeOffset] = rcvWAASTimeOffsetInserter;
        _msgInserters[EMessageId::RE] = rEInserter;
        _msgInserters[EMessageId::RefEpoch] = refEpochInserter;
        _msgInserters[EMessageId::Rms] = rmsInserter;
        _msgInserters[EMessageId::RotationAngles] = rotationAnglesInserter;
        _msgInserters[EMessageId::RotationMatrix] = rotationMatrixInserter;
        _msgInserters[EMessageId::RotationMatrixAndVectors] = rotationMatrixAndVectorsInserter;
        _msgInserters[EMessageId::RPR] = rPRInserter;
        _msgInserters[EMessageId::SatAzimuth] = satAzimuthInserter;
        _msgInserters[EMessageId::SatElevation] = satElevationInserter;
        _msgInserters[EMessageId::SatIndex] = satIndexInserter;
        _msgInserters[EMessageId::SatNumbers] = satNumbersInserter;
        _msgInserters[EMessageId::SC] = sCInserter;
        _msgInserters[EMessageId::SCP] = sCPInserter;
        _msgInserters[EMessageId::Security0] = security0Inserter;
        _msgInserters[EMessageId::Security1] = security1Inserter;
        _msgInserters[EMessageId::SolutionTime] = solutionTimeInserter;
        _msgInserters[EMessageId::SPR] = sPRInserter;
        _msgInserters[EMessageId::SRDP] = sRDPInserter;
        _msgInserters[EMessageId::SRPR] = sRPRInserter;
        _msgInserters[EMessageId::SS] = sSInserter;
        _msgInserters[EMessageId::TrackingTime] = trackingTimeInserter;
        _msgInserters[EMessageId::TrackingTimeCA] = trackingTimeCAInserter;
        _msgInserters[EMessageId::Vel] = velInserter;
        _msgInserters[EMessageId::VelCov] = velCovInserter;
        _msgInserters[EMessageId::WAASAlmanac] = wAASAlmanacInserter;
        _msgInserters[EMessageId::WAASEhemeris] = wAASEhemerisInserter;
        _msgInserters[EMessageId::WAASRawMessage] = wAASRawMessageInserter;
        _msgInserters[EMessageId::WaasUtcParam] = waasUtcParamInserter;
        _msgInserters[EMessageId::Wrapper] = wrapperInserter;
        _ctInserters[ECustomTypeId::ClkOffs] = clkOffsInserter;
        _ctInserters[ECustomTypeId::GPSAlm1] = gPSAlm1Inserter;
        _ctInserters[ECustomTypeId::GPSEphemeris1] = gPSEphemeris1Inserter;
        _ctInserters[ECustomTypeId::Header] = headerInserter;
        _ctInserters[ECustomTypeId::SlotRec] = slotRecInserter;
        _ctInserters[ECustomTypeId::Smooth] = smoothInserter;
        _ctInserters[ECustomTypeId::SvData0] = svData0Inserter;
        _ctInserters[ECustomTypeId::SvData1] = svData1Inserter;
        _ctInserters[ECustomTypeId::SvData2] = svData2Inserter;
        _ctInserters[ECustomTypeId::UtcOffs] = utcOffsInserter;
    }
    
    void MySqlSink::AddMessage( Message* msg )
    {
        if (msg->Kind() != EMessageKind::StdMessage)
        {
            return;
        }

        auto stdMsg = dynamic_cast<StdMessage*>(msg);

        QVariantList fields;
        switch (stdMsg->IdNumber())
        {
        case EMessageId::AngularVelocity:
            {
                auto cmsg = dynamic_cast<AngularVelocityStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_x);
                fields << _serializer.Serialize(_y);
                fields << _serializer.Serialize(_z);
                fields << _serializer.Serialize(_rms);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::AntName:
            {
                auto cmsg = dynamic_cast<AntNameStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_name);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::BaseInfo:
            {
                auto cmsg = dynamic_cast<BaseInfoStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_x);
                fields << _serializer.Serialize(_y);
                fields << _serializer.Serialize(_z);
                fields << _serializer.Serialize(_idField);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::BaseLine:
            {
                auto cmsg = dynamic_cast<BaseLineStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_x);
                fields << _serializer.Serialize(_y);
                fields << _serializer.Serialize(_z);
                fields << _serializer.Serialize(_sigma);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::ClockOffsets:
            {
                auto cmsg = dynamic_cast<ClockOffsetsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_sample);
                fields << _serializer.Serialize(_reserved);
                fields << _serializer.Serialize(_recSize);
                // TODO
                fields << _serializer.Serialize(_crc16);
            }
            break;
        case EMessageId::CNR:
            {
                auto cmsg = dynamic_cast<CNRStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_cnr);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::CNR4:
            {
                auto cmsg = dynamic_cast<CNR4StdMessage*>(stdMsg);
                fields << _serializer.Serialize(_cnrX4);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::CP:
            {
                auto cmsg = dynamic_cast<CPStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_cp);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Dops:
            {
                auto cmsg = dynamic_cast<DopsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_hdop);
                fields << _serializer.Serialize(_vdop);
                fields << _serializer.Serialize(_tdop);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::DP:
            {
                auto cmsg = dynamic_cast<DPStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_dp);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::EpochEnd:
            {
                auto cmsg = dynamic_cast<EpochEndStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::EpochTime:
            {
                auto cmsg = dynamic_cast<EpochTimeStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tod);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::ER:
            {
                auto cmsg = dynamic_cast<ERStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_error);
            }
            break;
        case EMessageId::Event:
            {
                auto cmsg = dynamic_cast<EventStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_type);
                fields << _serializer.Serialize(_data);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::ExtEvent:
            {
                auto cmsg = dynamic_cast<ExtEventStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_ms);
                fields << _serializer.Serialize(_ns);
                fields << _serializer.Serialize(_timeScale);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::FileId:
            {
                auto cmsg = dynamic_cast<FileIdStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_idField);
                fields << _serializer.Serialize(_description);
            }
            break;
        case EMessageId::Flags:
            {
                auto cmsg = dynamic_cast<FlagsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GALAlm:
            {
                auto cmsg = dynamic_cast<GALAlmStdMessage*>(stdMsg);
                // TODO
                fields << _serializer.Serialize(_iod);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GALEphemeris:
            {
                auto cmsg = dynamic_cast<GALEphemerisStdMessage*>(stdMsg);
                // TODO
                fields << _serializer.Serialize(_bgdE1E5a);
                fields << _serializer.Serialize(_bgdE1E5b);
                fields << _serializer.Serialize(_ai0);
                fields << _serializer.Serialize(_ai1);
                fields << _serializer.Serialize(_ai2);
                fields << _serializer.Serialize(_sfi);
                fields << _serializer.Serialize(_navType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GALRawMessage:
            {
                auto cmsg = dynamic_cast<GALRawMessageStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_prn);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_type);
                fields << _serializer.Serialize(_len);
                fields << _serializer.Serialize(_data);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GalUtcGpsParam:
            {
                auto cmsg = dynamic_cast<GalUtcGpsParamStdMessage*>(stdMsg);
                // TODO
                fields << _serializer.Serialize(_a0g);
                fields << _serializer.Serialize(_a1g);
                fields << _serializer.Serialize(_t0g);
                fields << _serializer.Serialize(_wn0g);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GeoPos:
            {
                auto cmsg = dynamic_cast<GeoPosStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_lat);
                fields << _serializer.Serialize(_lon);
                fields << _serializer.Serialize(_alt);
                fields << _serializer.Serialize(_pSigma);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GeoVel:
            {
                auto cmsg = dynamic_cast<GeoVelStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_lat);
                fields << _serializer.Serialize(_lon);
                fields << _serializer.Serialize(_alt);
                fields << _serializer.Serialize(_pSigma);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GLOAlmanac:
            {
                auto cmsg = dynamic_cast<GLOAlmanacStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_sv);
                fields << _serializer.Serialize(_frqNum);
                fields << _serializer.Serialize(_dna);
                fields << _serializer.Serialize(_tlam);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_tauN);
                fields << _serializer.Serialize(_tauSys);
                fields << _serializer.Serialize(_ecc);
                fields << _serializer.Serialize(_lambda);
                fields << _serializer.Serialize(_argPer);
                fields << _serializer.Serialize(_delT);
                fields << _serializer.Serialize(_delTdt);
                fields << _serializer.Serialize(_deli);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GLOEphemeris:
            {
                auto cmsg = dynamic_cast<GLOEphemerisStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_sv);
                fields << _serializer.Serialize(_frqNum);
                fields << _serializer.Serialize(_dne);
                fields << _serializer.Serialize(_tk);
                fields << _serializer.Serialize(_tb);
                fields << _serializer.Serialize(_health);
                fields << _serializer.Serialize(_age);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_r);
                fields << _serializer.Serialize(_v);
                fields << _serializer.Serialize(_w);
                fields << _serializer.Serialize(_tauSys);
                fields << _serializer.Serialize(_tau);
                fields << _serializer.Serialize(_gamma);
                fields << _serializer.Serialize(_fDelTauN);
                fields << _serializer.Serialize(_nFt);
                fields << _serializer.Serialize(_nN4);
                fields << _serializer.Serialize(_flags2);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GloNavData:
            {
                auto cmsg = dynamic_cast<GloNavDataStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_recSize);
                // TODO
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GloPhaseDelay:
            {
                auto cmsg = dynamic_cast<GloPhaseDelayStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_fcn);
                fields << _serializer.Serialize(_phase);
                fields << _serializer.Serialize(_range);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GLOTime:
            {
                auto cmsg = dynamic_cast<GLOTimeStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tod);
                fields << _serializer.Serialize(_dn);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GloUtcGpsParam:
            {
                auto cmsg = dynamic_cast<GloUtcGpsParamStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tauSys);
                fields << _serializer.Serialize(_tauGps);
                fields << _serializer.Serialize(_B1);
                fields << _serializer.Serialize(_B2);
                fields << _serializer.Serialize(_KP);
                fields << _serializer.Serialize(_N4);
                fields << _serializer.Serialize(_Dn);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GPSAlm0:
            {
                auto cmsg = dynamic_cast<GPSAlm0StdMessage*>(stdMsg);
                fields << _serializer.Serialize(_sv);
                fields << _serializer.Serialize(_wna);
                fields << _serializer.Serialize(_toa);
                fields << _serializer.Serialize(_healthA);
                fields << _serializer.Serialize(_healthS);
                fields << _serializer.Serialize(_config);
                fields << _serializer.Serialize(_af1);
                fields << _serializer.Serialize(_af0);
                fields << _serializer.Serialize(_rootA);
                fields << _serializer.Serialize(_ecc);
                fields << _serializer.Serialize(_m0);
                fields << _serializer.Serialize(_omega0);
                fields << _serializer.Serialize(_argPer);
                fields << _serializer.Serialize(_deli);
                fields << _serializer.Serialize(_omegaDot);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GPSEphemeris0:
            {
                auto cmsg = dynamic_cast<GPSEphemeris0StdMessage*>(stdMsg);
                fields << _serializer.Serialize(_sv);
                fields << _serializer.Serialize(_tow);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_iodc);
                fields << _serializer.Serialize(_toc);
                fields << _serializer.Serialize(_ura);
                fields << _serializer.Serialize(_healthS);
                fields << _serializer.Serialize(_wn);
                fields << _serializer.Serialize(_tgd);
                fields << _serializer.Serialize(_af2);
                fields << _serializer.Serialize(_af1);
                fields << _serializer.Serialize(_af0);
                fields << _serializer.Serialize(_toe);
                fields << _serializer.Serialize(_iode);
                fields << _serializer.Serialize(_rootA);
                fields << _serializer.Serialize(_ecc);
                fields << _serializer.Serialize(_m0);
                fields << _serializer.Serialize(_omega0);
                fields << _serializer.Serialize(_inc0);
                fields << _serializer.Serialize(_argPer);
                fields << _serializer.Serialize(_deln);
                fields << _serializer.Serialize(_omegaDot);
                fields << _serializer.Serialize(_incDot);
                fields << _serializer.Serialize(_crc);
                fields << _serializer.Serialize(_crs);
                fields << _serializer.Serialize(_cuc);
                fields << _serializer.Serialize(_cus);
                fields << _serializer.Serialize(_cic);
                fields << _serializer.Serialize(_cis);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GpsNavData:
            {
                auto cmsg = dynamic_cast<GpsNavDataStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_recSize);
                // TODO
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GPSTime:
            {
                auto cmsg = dynamic_cast<GPSTimeStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tow);
                fields << _serializer.Serialize(_wn);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::GpsUtcParam:
            {
                auto cmsg = dynamic_cast<GpsUtcParamStdMessage*>(stdMsg);
                // TODO
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::InertialMeasurements:
            {
                auto cmsg = dynamic_cast<InertialMeasurementsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_accelerations);
                fields << _serializer.Serialize(_angularVelocities);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::IonoDelay:
            {
                auto cmsg = dynamic_cast<IonoDelayStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_delay);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::IonoParams:
            {
                auto cmsg = dynamic_cast<IonoParamsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tot);
                fields << _serializer.Serialize(_wn);
                fields << _serializer.Serialize(_alpha0);
                fields << _serializer.Serialize(_alpha1);
                fields << _serializer.Serialize(_alpha2);
                fields << _serializer.Serialize(_alpha3);
                fields << _serializer.Serialize(_beta0);
                fields << _serializer.Serialize(_beta1);
                fields << _serializer.Serialize(_beta2);
                fields << _serializer.Serialize(_beta3);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Latency:
            {
                auto cmsg = dynamic_cast<LatencyStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_lt);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::LoggingHistory:
            {
                auto cmsg = dynamic_cast<LoggingHistoryStdMessage*>(stdMsg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::MsgFmt:
            {
                auto cmsg = dynamic_cast<MsgFmtStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_idField);
                fields << _serializer.Serialize(_majorVer);
                fields << _serializer.Serialize(_minorVer);
                fields << _serializer.SerializeChar(_order);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::NavStatus:
            {
                auto cmsg = dynamic_cast<NavStatusStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_ns);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Params:
            {
                auto cmsg = dynamic_cast<ParamsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_params);
                fields << _serializer.Serialize(_delim);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Pos:
            {
                auto cmsg = dynamic_cast<PosStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_x);
                fields << _serializer.Serialize(_y);
                fields << _serializer.Serialize(_z);
                fields << _serializer.Serialize(_sigma);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::PosCompTime:
            {
                auto cmsg = dynamic_cast<PosCompTimeStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_pt);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::PosCov:
            {
                auto cmsg = dynamic_cast<PosCovStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_xx);
                fields << _serializer.Serialize(_yy);
                fields << _serializer.Serialize(_zz);
                fields << _serializer.Serialize(_tt);
                fields << _serializer.Serialize(_xy);
                fields << _serializer.Serialize(_xz);
                fields << _serializer.Serialize(_xt);
                fields << _serializer.Serialize(_yz);
                fields << _serializer.Serialize(_yt);
                fields << _serializer.Serialize(_zt);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::PosStat:
            {
                auto cmsg = dynamic_cast<PosStatStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_gpsLocked);
                fields << _serializer.Serialize(_gloLocked);
                fields << _serializer.Serialize(_gpsAvail);
                fields << _serializer.Serialize(_gloAvail);
                fields << _serializer.Serialize(_gpsUsed);
                fields << _serializer.Serialize(_gloUsed);
                fields << _serializer.Serialize(_fixProg);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::PosVel:
            {
                auto cmsg = dynamic_cast<PosVelStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_x);
                fields << _serializer.Serialize(_y);
                fields << _serializer.Serialize(_z);
                fields << _serializer.Serialize(_pSigma);
                fields << _serializer.Serialize(_vx);
                fields << _serializer.Serialize(_vy);
                fields << _serializer.Serialize(_vz);
                fields << _serializer.Serialize(_vSigma);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::PosVelVector:
            {
                auto cmsg = dynamic_cast<PosVelVectorStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_sample);
                fields << _serializer.Serialize(_delta);
                fields << _serializer.Serialize(_word1);
                fields << _serializer.Serialize(_word2);
                fields << _serializer.Serialize(_word3);
                fields << _serializer.Serialize(_word4);
                fields << _serializer.Serialize(_word5);
                fields << _serializer.Serialize(_word6);
                fields << _serializer.Serialize(_word7);
                fields << _serializer.Serialize(_word8);
                fields << _serializer.Serialize(_word9);
                fields << _serializer.Serialize(_crc16);
            }
            break;
        case EMessageId::PPSOffset:
            {
                auto cmsg = dynamic_cast<PPSOffsetStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_offs);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::PR:
            {
                auto cmsg = dynamic_cast<PRStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_pr);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RawMeas:
            {
                auto cmsg = dynamic_cast<RawMeasStdMessage*>(stdMsg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::RCPRc1:
            {
                auto cmsg = dynamic_cast<RCPRc1StdMessage*>(stdMsg);
                fields << _serializer.Serialize(_rcp);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RCPRC0:
            {
                auto cmsg = dynamic_cast<RCPRC0StdMessage*>(stdMsg);
                fields << _serializer.Serialize(_rcp);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvDate:
            {
                auto cmsg = dynamic_cast<RcvDateStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_year);
                fields << _serializer.Serialize(_month);
                fields << _serializer.Serialize(_day);
                fields << _serializer.Serialize(_base);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvGALTimeOffset:
            {
                auto cmsg = dynamic_cast<RcvGALTimeOffsetStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_val);
                fields << _serializer.Serialize(_sval);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvGLOTimeOffset:
            {
                auto cmsg = dynamic_cast<RcvGLOTimeOffsetStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_val);
                fields << _serializer.Serialize(_sval);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvGPSTimeOffset:
            {
                auto cmsg = dynamic_cast<RcvGPSTimeOffsetStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_val);
                fields << _serializer.Serialize(_sval);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvOscOffs:
            {
                auto cmsg = dynamic_cast<RcvOscOffsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_val);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvTime:
            {
                auto cmsg = dynamic_cast<RcvTimeStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tod);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvTimeAccuracy:
            {
                auto cmsg = dynamic_cast<RcvTimeAccuracyStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_acc);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvTimeOffsAtPPS:
            {
                auto cmsg = dynamic_cast<RcvTimeOffsAtPPSStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_offs);
                fields << _serializer.Serialize(_timeScale);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvTimeOffset:
            {
                auto cmsg = dynamic_cast<RcvTimeOffsetStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_val);
                fields << _serializer.Serialize(_sval);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvTimeOffsetDot:
            {
                auto cmsg = dynamic_cast<RcvTimeOffsetDotStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_val);
                fields << _serializer.Serialize(_sval);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RcvWAASTimeOffset:
            {
                auto cmsg = dynamic_cast<RcvWAASTimeOffsetStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_val);
                fields << _serializer.Serialize(_sval);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RE:
            {
                auto cmsg = dynamic_cast<REStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_reply);
            }
            break;
        case EMessageId::RefEpoch:
            {
                auto cmsg = dynamic_cast<RefEpochStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_sample);
                fields << _serializer.Serialize(_scale);
                fields << _serializer.Serialize(_reftime);
                fields << _serializer.Serialize(_crc16);
            }
            break;
        case EMessageId::Rms:
            {
                auto cmsg = dynamic_cast<RmsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_hpos);
                fields << _serializer.Serialize(_vpos);
                fields << _serializer.Serialize(_hvel);
                fields << _serializer.Serialize(_vvel);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RotationAngles:
            {
                auto cmsg = dynamic_cast<RotationAnglesStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_pitch);
                fields << _serializer.Serialize(_roll);
                fields << _serializer.Serialize(_heading);
                fields << _serializer.Serialize(_pitchRms);
                fields << _serializer.Serialize(_rollRms);
                fields << _serializer.Serialize(_headingRms);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RotationMatrix:
            {
                auto cmsg = dynamic_cast<RotationMatrixStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_q00);
                fields << _serializer.Serialize(_q01);
                fields << _serializer.Serialize(_q02);
                fields << _serializer.Serialize(_q12);
                fields << _serializer.Serialize(_rms);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_flag);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RotationMatrixAndVectors:
            {
                auto cmsg = dynamic_cast<RotationMatrixAndVectorsStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_q00);
                fields << _serializer.Serialize(_q01);
                fields << _serializer.Serialize(_q02);
                fields << _serializer.Serialize(_q12);
                fields << _serializer.Serialize(_rms);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_flag);
                fields << _serializer.Serialize(_bl0);
                fields << _serializer.Serialize(_bl1);
                fields << _serializer.Serialize(_bl2);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::RPR:
            {
                auto cmsg = dynamic_cast<RPRStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_rpr);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SatAzimuth:
            {
                auto cmsg = dynamic_cast<SatAzimuthStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_azim);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SatElevation:
            {
                auto cmsg = dynamic_cast<SatElevationStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_elev);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SatIndex:
            {
                auto cmsg = dynamic_cast<SatIndexStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_usi);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SatNumbers:
            {
                auto cmsg = dynamic_cast<SatNumbersStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_osn);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SC:
            {
                auto cmsg = dynamic_cast<SCStdMessage*>(stdMsg);
                // TODO
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SCP:
            {
                auto cmsg = dynamic_cast<SCPStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_scp);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Security0:
            {
                auto cmsg = dynamic_cast<Security0StdMessage*>(stdMsg);
                fields << _serializer.Serialize(_data);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Security1:
            {
                auto cmsg = dynamic_cast<Security1StdMessage*>(stdMsg);
                fields << _serializer.Serialize(_data);
                fields << _serializer.Serialize(_crc16);
            }
            break;
        case EMessageId::SolutionTime:
            {
                auto cmsg = dynamic_cast<SolutionTimeStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SPR:
            {
                auto cmsg = dynamic_cast<SPRStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_spr);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SRDP:
            {
                auto cmsg = dynamic_cast<SRDPStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_srdp);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SRPR:
            {
                auto cmsg = dynamic_cast<SRPRStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_srpr);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::SS:
            {
                auto cmsg = dynamic_cast<SSStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_smooth);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::TrackingTime:
            {
                auto cmsg = dynamic_cast<TrackingTimeStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tt);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::TrackingTimeCA:
            {
                auto cmsg = dynamic_cast<TrackingTimeCAStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_tt);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Vel:
            {
                auto cmsg = dynamic_cast<VelStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_x);
                fields << _serializer.Serialize(_y);
                fields << _serializer.Serialize(_z);
                fields << _serializer.Serialize(_sigma);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::VelCov:
            {
                auto cmsg = dynamic_cast<VelCovStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_xx);
                fields << _serializer.Serialize(_yy);
                fields << _serializer.Serialize(_zz);
                fields << _serializer.Serialize(_tt);
                fields << _serializer.Serialize(_xy);
                fields << _serializer.Serialize(_xz);
                fields << _serializer.Serialize(_xt);
                fields << _serializer.Serialize(_yz);
                fields << _serializer.Serialize(_yt);
                fields << _serializer.Serialize(_zt);
                fields << _serializer.Serialize(_solType);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::WAASAlmanac:
            {
                auto cmsg = dynamic_cast<WAASAlmanacStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_waasPrn);
                fields << _serializer.Serialize(_gpsPrn);
                fields << _serializer.Serialize(_idField);
                fields << _serializer.Serialize(_healthS);
                fields << _serializer.Serialize(_tod);
                fields << _serializer.Serialize(_xg);
                fields << _serializer.Serialize(_yg);
                fields << _serializer.Serialize(_zg);
                fields << _serializer.Serialize(_vxg);
                fields << _serializer.Serialize(_vyg);
                fields << _serializer.Serialize(_vzg);
                fields << _serializer.Serialize(_tow);
                fields << _serializer.Serialize(_wn);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::WAASEhemeris:
            {
                auto cmsg = dynamic_cast<WAASEhemerisStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_waasPrn);
                fields << _serializer.Serialize(_gpsPrn);
                fields << _serializer.Serialize(_iod);
                fields << _serializer.Serialize(_acc);
                fields << _serializer.Serialize(_tod);
                fields << _serializer.Serialize(_xg);
                fields << _serializer.Serialize(_yg);
                fields << _serializer.Serialize(_zg);
                fields << _serializer.Serialize(_vxg);
                fields << _serializer.Serialize(_vyg);
                fields << _serializer.Serialize(_vzg);
                fields << _serializer.Serialize(_vvxg);
                fields << _serializer.Serialize(_vvyg);
                fields << _serializer.Serialize(_vvzg);
                fields << _serializer.Serialize(_agf0);
                fields << _serializer.Serialize(_agf1);
                fields << _serializer.Serialize(_tow);
                fields << _serializer.Serialize(_wn);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::WAASRawMessage:
            {
                auto cmsg = dynamic_cast<WAASRawMessageStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_prn);
                fields << _serializer.Serialize(_time);
                fields << _serializer.Serialize(_reserv);
                fields << _serializer.Serialize(_data);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::WaasUtcParam:
            {
                auto cmsg = dynamic_cast<WaasUtcParamStdMessage*>(stdMsg);
                // TODO
                fields << _serializer.Serialize(_utcsi);
                fields << _serializer.Serialize(_tow);
                fields << _serializer.Serialize(_wn);
                fields << _serializer.Serialize(_flags);
                fields << _serializer.Serialize(_cs);
            }
            break;
        case EMessageId::Wrapper:
            {
                auto cmsg = dynamic_cast<WrapperStdMessage*>(stdMsg);
                fields << _serializer.Serialize(_idField);
                fields << _serializer.Serialize(_data);
                fields << _serializer.Serialize(_cs);
            }
            break;
        default:
            throw InvalidOperationException();
        }
    }
}
