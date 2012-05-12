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
        auto baselineInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Baseline` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `time`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            11, _connection, "msg_Baseline", _inserterBatchSize);
        auto clockOffsetsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_ClockOffsets` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `reserved`, `recSize`, `Offs`, `crc16`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "msg_ClockOffsets", _inserterBatchSize);
        auto cNRInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_CNR` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnr`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_CNR", _inserterBatchSize);
        auto cNR4Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_CNR_4` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnrX4`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_CNR_4", _inserterBatchSize);
        auto compRawNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_CompRawNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_CompRawNavData", _inserterBatchSize);
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
            "INSERT INTO `msg_GALEphemeris` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `req`, `bgdE1E5a`, `bgdE1E5b`, `ai0`, `ai1`, `ai2`, `sfi`, `navType`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            13, _connection, "msg_GALEphemeris", _inserterBatchSize);
        auto galRawNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GalRawNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_GalRawNavData", _inserterBatchSize);
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
            "INSERT INTO `msg_GLOAlmanac` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dna`, `tlam`, `flags`, `tauN`, `tauSys`, `ecc`, `lambda`, `argPer`, `delT`, `delTdt`, `deli`, `n4`, `navType`, `gammaN`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            21, _connection, "msg_GLOAlmanac", _inserterBatchSize);
        auto gLOEphemerisInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GLOEphemeris` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dne`, `tk`, `tb`, `health`, `age`, `flags`, `r`, `v`, `w`, `tauSys`, `tau`, `gamma`, `fDelTauN`, `nFt`, `nN4`, `flags2`, `navType`, `beta`, `tauSysDot`, `ec`, `ee`, `fc`, `fe`, `reserv`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            31, _connection, "msg_GLOEphemeris", _inserterBatchSize);
        auto gloNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GloNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GloNavData", _inserterBatchSize);
        auto gloPhaseDelayInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GloPhaseDelay` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `fcn`, `phase`, `range`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", 
            8, _connection, "msg_GloPhaseDelay", _inserterBatchSize);
        auto gloRawNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GloRawNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `num`, `fcn`, `time`, `type`, `len`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            11, _connection, "msg_GloRawNavData", _inserterBatchSize);
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
            "INSERT INTO `msg_GPSEphemeris0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `req`, `cNavType`, `lTope`, `lTopc`, `dADot`, `fDelnDot`, `cURAoe`, `cURAoc`, `cURAoc1`, `cURAoc2`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            15, _connection, "msg_GPSEphemeris0", _inserterBatchSize);
        auto gpsNavData0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GpsNavData0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GpsNavData0", _inserterBatchSize);
        auto gpsRawNavData0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GpsRawNavData0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_GpsRawNavData0", _inserterBatchSize);
        auto gPSTimeInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GPSTime` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tow`, `wn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_GPSTime", _inserterBatchSize);
        auto gpsUtcParamInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_GpsUtcParam` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_GpsUtcParam", _inserterBatchSize);
        auto iAmpInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_IAmp` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `amp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_IAmp", _inserterBatchSize);
        auto inertialMeasurementsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_InertialMeasurements` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `accelerations`, `angularVelocities`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_InertialMeasurements", _inserterBatchSize);
        auto ionoDelayInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_IonoDelay` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `delay`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_IonoDelay", _inserterBatchSize);
        auto ionoParams0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_IonoParams0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tot`, `wn`, `alpha0`, `alpha1`, `alpha2`, `alpha3`, `beta0`, `beta1`, `beta2`, `beta3`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            15, _connection, "msg_IonoParams0", _inserterBatchSize);
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
        auto qAmpInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_QAmp` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `amp`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_QAmp", _inserterBatchSize);
        auto qZSSAlmInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_QZSSAlm` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_QZSSAlm", _inserterBatchSize);
        auto qZSSEphemerisInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_QZSSEphemeris` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_QZSSEphemeris", _inserterBatchSize);
        auto qzssIonoParamsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_QzssIonoParams` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `par`) VALUES (?, ?, ?, ?, ?)", 
            5, _connection, "msg_QzssIonoParams", _inserterBatchSize);
        auto qzssNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_QzssNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`) VALUES (?, ?, ?, ?, ?)", 
            5, _connection, "msg_QzssNavData", _inserterBatchSize);
        auto qzssRawNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_QzssRawNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`) VALUES (?, ?, ?, ?, ?)", 
            5, _connection, "msg_QzssRawNavData", _inserterBatchSize);
        auto qzssUtcParamInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_QzssUtcParam` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `cs`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "msg_QzssUtcParam", _inserterBatchSize);
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
        auto rcvQZSSTimeOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvQZSSTimeOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvQZSSTimeOffset", _inserterBatchSize);
        auto rcvSBASTimeOffsetInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_RcvSBASTimeOffset` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_RcvSBASTimeOffset", _inserterBatchSize);
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
        auto sBASAlmanacInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SBASAlmanac` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `id_sugar`, `healthS`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `tow`, `wn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            18, _connection, "msg_SBASAlmanac", _inserterBatchSize);
        auto sBASEhemerisInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SBASEhemeris` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `iod`, `acc`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `vvxg`, `vvyg`, `vvzg`, `agf0`, `agf1`, `tow`, `wn`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            23, _connection, "msg_SBASEhemeris", _inserterBatchSize);
        auto sbasRawNavDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SbasRawNavData` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `reserv`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "msg_SbasRawNavData", _inserterBatchSize);
        auto sbasUtcParamInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_SbasUtcParam` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `utcsi`, `tow`, `wn`, `flags`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_SbasUtcParam", _inserterBatchSize);
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
        auto spectrum0Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Spectrum0` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `currFrq`, `finalFrq`, `n`, `m`, `s`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_Spectrum0", _inserterBatchSize);
        auto spectrum1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Spectrum1` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `currFrq`, `finalFrq`, `n`, `m`, `s`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "msg_Spectrum1", _inserterBatchSize);
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
        auto wrapperInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `msg_Wrapper` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "msg_Wrapper", _inserterBatchSize);
        auto clkOffsInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_ClkOffs` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `word1`, `word2`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "ct_ClkOffs", _inserterBatchSize);
        auto extSpecDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_ExtSpecData` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `spec`, `agcmin`, `agcmax`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "ct_ExtSpecData", _inserterBatchSize);
        auto gPSAlm1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_GPSAlm1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `healthS`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            19, _connection, "ct_GPSAlm1", _inserterBatchSize);
        auto gPSEphemeris1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_GPSEphemeris1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `req`, `cNavType`, `lTope`, `lTopc`, `dADot`, `fDelnDot`, `cURAoe`, `cURAoc`, `cURAoc1`, `cURAoc2`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            14, _connection, "ct_GPSEphemeris1", _inserterBatchSize);
        auto gpsEphReqDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_GpsEphReqData` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `tow`, `flags`, `iodc`, `toc`, `ura`, `healthS`, `wn`, `tgd`, `af2`, `af1`, `af0`, `toe`, `iode`, `rootA`, `ecc`, `m0`, `omega0`, `inc0`, `argPer`, `deln`, `omegaDot`, `incDot`, `crc`, `crs`, `cuc`, `cus`, `cic`, `cis`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            33, _connection, "ct_GpsEphReqData", _inserterBatchSize);
        auto gpsNavData1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_GpsNavData1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `recSize`, `dat`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "ct_GpsNavData1", _inserterBatchSize);
        auto gpsRawNavData1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_GpsRawNavData1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            10, _connection, "ct_GpsRawNavData1", _inserterBatchSize);
        auto headerInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_Header` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `refrange`, `usi`, `num`) VALUES (?, ?, ?, ?, ?, ?, ?)", 
            7, _connection, "ct_Header", _inserterBatchSize);
        auto ionoParams1Inserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_IonoParams1` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `tot`, `wn`, `alpha0`, `alpha1`, `alpha2`, `alpha3`, `beta0`, `beta1`, `beta2`, `beta3`, `cs`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            15, _connection, "ct_IonoParams1", _inserterBatchSize);
        auto slotRecInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_SlotRec` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `svstOrDelrange`, `word1`, `flags`, `lock`, `word2`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            9, _connection, "ct_SlotRec", _inserterBatchSize);
        auto smoothInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_Smooth` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `value`, `interval`) VALUES (?, ?, ?, ?, ?, ?)", 
            6, _connection, "ct_Smooth", _inserterBatchSize);
        auto specDataInserter = std::make_shared<DataBatchInserter>(
            "INSERT INTO `ct_SpecData` (`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `spec`) VALUES (?, ?, ?, ?, ?)", 
            5, _connection, "ct_SpecData", _inserterBatchSize);
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

        angularVelocityInserter->AddChild(_epochInserter);
        antNameInserter->AddChild(_epochInserter);
        baseInfoInserter->AddChild(_epochInserter);
        baselineInserter->AddChild(_epochInserter);
        clockOffsetsInserter->AddChild(clkOffsInserter);
        clockOffsetsInserter->AddChild(_epochInserter);
        cNRInserter->AddChild(_epochInserter);
        cNR4Inserter->AddChild(_epochInserter);
        compRawNavDataInserter->AddChild(_epochInserter);
        cPInserter->AddChild(_epochInserter);
        dopsInserter->AddChild(_epochInserter);
        dPInserter->AddChild(_epochInserter);
        epochEndInserter->AddChild(_epochInserter);
        epochTimeInserter->AddChild(_epochInserter);
        eRInserter->AddChild(_epochInserter);
        eventInserter->AddChild(_epochInserter);
        extEventInserter->AddChild(_epochInserter);
        fileIdInserter->AddChild(_epochInserter);
        flagsInserter->AddChild(_epochInserter);
        gALAlmInserter->AddChild(gPSAlm1Inserter);
        gALAlmInserter->AddChild(_epochInserter);
        gALEphemerisInserter->AddChild(gpsEphReqDataInserter);
        gALEphemerisInserter->AddChild(_epochInserter);
        galRawNavDataInserter->AddChild(_epochInserter);
        galUtcGpsParamInserter->AddChild(utcOffsInserter);
        galUtcGpsParamInserter->AddChild(_epochInserter);
        geoPosInserter->AddChild(_epochInserter);
        geoVelInserter->AddChild(_epochInserter);
        gLOAlmanacInserter->AddChild(_epochInserter);
        gLOEphemerisInserter->AddChild(_epochInserter);
        gloNavDataInserter->AddChild(svData1Inserter);
        gloNavDataInserter->AddChild(_epochInserter);
        gloPhaseDelayInserter->AddChild(_epochInserter);
        gloRawNavDataInserter->AddChild(_epochInserter);
        gLOTimeInserter->AddChild(_epochInserter);
        gloUtcGpsParamInserter->AddChild(_epochInserter);
        gPSAlm0Inserter->AddChild(_epochInserter);
        gPSEphemeris0Inserter->AddChild(gpsEphReqDataInserter);
        gPSEphemeris0Inserter->AddChild(_epochInserter);
        gpsNavData0Inserter->AddChild(svData0Inserter);
        gpsNavData0Inserter->AddChild(_epochInserter);
        gpsRawNavData0Inserter->AddChild(_epochInserter);
        gPSTimeInserter->AddChild(_epochInserter);
        gpsUtcParamInserter->AddChild(utcOffsInserter);
        gpsUtcParamInserter->AddChild(_epochInserter);
        iAmpInserter->AddChild(_epochInserter);
        inertialMeasurementsInserter->AddChild(_epochInserter);
        ionoDelayInserter->AddChild(_epochInserter);
        ionoParams0Inserter->AddChild(_epochInserter);
        latencyInserter->AddChild(_epochInserter);
        loggingHistoryInserter->AddChild(_epochInserter);
        msgFmtInserter->AddChild(_epochInserter);
        navStatusInserter->AddChild(_epochInserter);
        paramsInserter->AddChild(_epochInserter);
        posInserter->AddChild(_epochInserter);
        posCompTimeInserter->AddChild(_epochInserter);
        posCovInserter->AddChild(_epochInserter);
        posStatInserter->AddChild(_epochInserter);
        posVelInserter->AddChild(_epochInserter);
        posVelVectorInserter->AddChild(_epochInserter);
        pPSOffsetInserter->AddChild(_epochInserter);
        pRInserter->AddChild(_epochInserter);
        qAmpInserter->AddChild(_epochInserter);
        qZSSAlmInserter->AddChild(gPSAlm1Inserter);
        qZSSAlmInserter->AddChild(_epochInserter);
        qZSSEphemerisInserter->AddChild(gPSEphemeris1Inserter);
        qZSSEphemerisInserter->AddChild(_epochInserter);
        qzssIonoParamsInserter->AddChild(ionoParams1Inserter);
        qzssIonoParamsInserter->AddChild(_epochInserter);
        qzssNavDataInserter->AddChild(gpsNavData1Inserter);
        qzssNavDataInserter->AddChild(_epochInserter);
        qzssRawNavDataInserter->AddChild(gpsRawNavData1Inserter);
        qzssRawNavDataInserter->AddChild(_epochInserter);
        qzssUtcParamInserter->AddChild(utcOffsInserter);
        qzssUtcParamInserter->AddChild(_epochInserter);
        rawMeasInserter->AddChild(svData2Inserter);
        rawMeasInserter->AddChild(_epochInserter);
        rCPRc1Inserter->AddChild(_epochInserter);
        rCPRC0Inserter->AddChild(_epochInserter);
        rcvDateInserter->AddChild(_epochInserter);
        rcvGALTimeOffsetInserter->AddChild(_epochInserter);
        rcvGLOTimeOffsetInserter->AddChild(_epochInserter);
        rcvGPSTimeOffsetInserter->AddChild(_epochInserter);
        rcvOscOffsInserter->AddChild(_epochInserter);
        rcvQZSSTimeOffsetInserter->AddChild(_epochInserter);
        rcvSBASTimeOffsetInserter->AddChild(_epochInserter);
        rcvTimeInserter->AddChild(_epochInserter);
        rcvTimeAccuracyInserter->AddChild(_epochInserter);
        rcvTimeOffsAtPPSInserter->AddChild(_epochInserter);
        rcvTimeOffsetInserter->AddChild(_epochInserter);
        rcvTimeOffsetDotInserter->AddChild(_epochInserter);
        rEInserter->AddChild(_epochInserter);
        refEpochInserter->AddChild(_epochInserter);
        rmsInserter->AddChild(_epochInserter);
        rotationAnglesInserter->AddChild(_epochInserter);
        rotationMatrixInserter->AddChild(_epochInserter);
        rotationMatrixAndVectorsInserter->AddChild(_epochInserter);
        rPRInserter->AddChild(_epochInserter);
        satAzimuthInserter->AddChild(_epochInserter);
        satElevationInserter->AddChild(_epochInserter);
        satIndexInserter->AddChild(_epochInserter);
        satNumbersInserter->AddChild(_epochInserter);
        sBASAlmanacInserter->AddChild(_epochInserter);
        sBASEhemerisInserter->AddChild(_epochInserter);
        sbasRawNavDataInserter->AddChild(_epochInserter);
        sbasUtcParamInserter->AddChild(utcOffsInserter);
        sbasUtcParamInserter->AddChild(_epochInserter);
        sCInserter->AddChild(smoothInserter);
        sCInserter->AddChild(_epochInserter);
        sCPInserter->AddChild(_epochInserter);
        security0Inserter->AddChild(_epochInserter);
        security1Inserter->AddChild(_epochInserter);
        solutionTimeInserter->AddChild(_epochInserter);
        spectrum0Inserter->AddChild(specDataInserter);
        spectrum0Inserter->AddChild(_epochInserter);
        spectrum1Inserter->AddChild(extSpecDataInserter);
        spectrum1Inserter->AddChild(_epochInserter);
        sPRInserter->AddChild(_epochInserter);
        sRDPInserter->AddChild(_epochInserter);
        sRPRInserter->AddChild(_epochInserter);
        sSInserter->AddChild(_epochInserter);
        trackingTimeInserter->AddChild(_epochInserter);
        trackingTimeCAInserter->AddChild(_epochInserter);
        velInserter->AddChild(_epochInserter);
        velCovInserter->AddChild(_epochInserter);
        wrapperInserter->AddChild(_epochInserter);
        clkOffsInserter->AddChild(_epochInserter);
        extSpecDataInserter->AddChild(_epochInserter);
        gPSAlm1Inserter->AddChild(_epochInserter);
        gPSEphemeris1Inserter->AddChild(gpsEphReqDataInserter);
        gPSEphemeris1Inserter->AddChild(_epochInserter);
        gpsEphReqDataInserter->AddChild(_epochInserter);
        gpsNavData1Inserter->AddChild(svData0Inserter);
        gpsNavData1Inserter->AddChild(_epochInserter);
        gpsRawNavData1Inserter->AddChild(_epochInserter);
        headerInserter->AddChild(_epochInserter);
        ionoParams1Inserter->AddChild(_epochInserter);
        slotRecInserter->AddChild(_epochInserter);
        smoothInserter->AddChild(_epochInserter);
        specDataInserter->AddChild(_epochInserter);
        svData0Inserter->AddChild(_epochInserter);
        svData1Inserter->AddChild(_epochInserter);
        svData2Inserter->AddChild(headerInserter);
        svData2Inserter->AddChild(slotRecInserter);
        svData2Inserter->AddChild(_epochInserter);
        utcOffsInserter->AddChild(_epochInserter);

        _msgInserters[EMessageId::AngularVelocity] = angularVelocityInserter;
        _msgInserters[EMessageId::AntName] = antNameInserter;
        _msgInserters[EMessageId::BaseInfo] = baseInfoInserter;
        _msgInserters[EMessageId::Baseline] = baselineInserter;
        _msgInserters[EMessageId::ClockOffsets] = clockOffsetsInserter;
        _msgInserters[EMessageId::CNR] = cNRInserter;
        _msgInserters[EMessageId::CNR4] = cNR4Inserter;
        _msgInserters[EMessageId::CompRawNavData] = compRawNavDataInserter;
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
        _msgInserters[EMessageId::GalRawNavData] = galRawNavDataInserter;
        _msgInserters[EMessageId::GalUtcGpsParam] = galUtcGpsParamInserter;
        _msgInserters[EMessageId::GeoPos] = geoPosInserter;
        _msgInserters[EMessageId::GeoVel] = geoVelInserter;
        _msgInserters[EMessageId::GLOAlmanac] = gLOAlmanacInserter;
        _msgInserters[EMessageId::GLOEphemeris] = gLOEphemerisInserter;
        _msgInserters[EMessageId::GloNavData] = gloNavDataInserter;
        _msgInserters[EMessageId::GloPhaseDelay] = gloPhaseDelayInserter;
        _msgInserters[EMessageId::GloRawNavData] = gloRawNavDataInserter;
        _msgInserters[EMessageId::GLOTime] = gLOTimeInserter;
        _msgInserters[EMessageId::GloUtcGpsParam] = gloUtcGpsParamInserter;
        _msgInserters[EMessageId::GPSAlm0] = gPSAlm0Inserter;
        _msgInserters[EMessageId::GPSEphemeris0] = gPSEphemeris0Inserter;
        _msgInserters[EMessageId::GpsNavData0] = gpsNavData0Inserter;
        _msgInserters[EMessageId::GpsRawNavData0] = gpsRawNavData0Inserter;
        _msgInserters[EMessageId::GPSTime] = gPSTimeInserter;
        _msgInserters[EMessageId::GpsUtcParam] = gpsUtcParamInserter;
        _msgInserters[EMessageId::IAmp] = iAmpInserter;
        _msgInserters[EMessageId::InertialMeasurements] = inertialMeasurementsInserter;
        _msgInserters[EMessageId::IonoDelay] = ionoDelayInserter;
        _msgInserters[EMessageId::IonoParams0] = ionoParams0Inserter;
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
        _msgInserters[EMessageId::QAmp] = qAmpInserter;
        _msgInserters[EMessageId::QZSSAlm] = qZSSAlmInserter;
        _msgInserters[EMessageId::QZSSEphemeris] = qZSSEphemerisInserter;
        _msgInserters[EMessageId::QzssIonoParams] = qzssIonoParamsInserter;
        _msgInserters[EMessageId::QzssNavData] = qzssNavDataInserter;
        _msgInserters[EMessageId::QzssRawNavData] = qzssRawNavDataInserter;
        _msgInserters[EMessageId::QzssUtcParam] = qzssUtcParamInserter;
        _msgInserters[EMessageId::RawMeas] = rawMeasInserter;
        _msgInserters[EMessageId::RCPRc1] = rCPRc1Inserter;
        _msgInserters[EMessageId::RCPRC0] = rCPRC0Inserter;
        _msgInserters[EMessageId::RcvDate] = rcvDateInserter;
        _msgInserters[EMessageId::RcvGALTimeOffset] = rcvGALTimeOffsetInserter;
        _msgInserters[EMessageId::RcvGLOTimeOffset] = rcvGLOTimeOffsetInserter;
        _msgInserters[EMessageId::RcvGPSTimeOffset] = rcvGPSTimeOffsetInserter;
        _msgInserters[EMessageId::RcvOscOffs] = rcvOscOffsInserter;
        _msgInserters[EMessageId::RcvQZSSTimeOffset] = rcvQZSSTimeOffsetInserter;
        _msgInserters[EMessageId::RcvSBASTimeOffset] = rcvSBASTimeOffsetInserter;
        _msgInserters[EMessageId::RcvTime] = rcvTimeInserter;
        _msgInserters[EMessageId::RcvTimeAccuracy] = rcvTimeAccuracyInserter;
        _msgInserters[EMessageId::RcvTimeOffsAtPPS] = rcvTimeOffsAtPPSInserter;
        _msgInserters[EMessageId::RcvTimeOffset] = rcvTimeOffsetInserter;
        _msgInserters[EMessageId::RcvTimeOffsetDot] = rcvTimeOffsetDotInserter;
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
        _msgInserters[EMessageId::SBASAlmanac] = sBASAlmanacInserter;
        _msgInserters[EMessageId::SBASEhemeris] = sBASEhemerisInserter;
        _msgInserters[EMessageId::SbasRawNavData] = sbasRawNavDataInserter;
        _msgInserters[EMessageId::SbasUtcParam] = sbasUtcParamInserter;
        _msgInserters[EMessageId::SC] = sCInserter;
        _msgInserters[EMessageId::SCP] = sCPInserter;
        _msgInserters[EMessageId::Security0] = security0Inserter;
        _msgInserters[EMessageId::Security1] = security1Inserter;
        _msgInserters[EMessageId::SolutionTime] = solutionTimeInserter;
        _msgInserters[EMessageId::Spectrum0] = spectrum0Inserter;
        _msgInserters[EMessageId::Spectrum1] = spectrum1Inserter;
        _msgInserters[EMessageId::SPR] = sPRInserter;
        _msgInserters[EMessageId::SRDP] = sRDPInserter;
        _msgInserters[EMessageId::SRPR] = sRPRInserter;
        _msgInserters[EMessageId::SS] = sSInserter;
        _msgInserters[EMessageId::TrackingTime] = trackingTimeInserter;
        _msgInserters[EMessageId::TrackingTimeCA] = trackingTimeCAInserter;
        _msgInserters[EMessageId::Vel] = velInserter;
        _msgInserters[EMessageId::VelCov] = velCovInserter;
        _msgInserters[EMessageId::Wrapper] = wrapperInserter;
        _ctInserters[ECustomTypeId::ClkOffs] = clkOffsInserter;
        _ctInserters[ECustomTypeId::ExtSpecData] = extSpecDataInserter;
        _ctInserters[ECustomTypeId::GPSAlm1] = gPSAlm1Inserter;
        _ctInserters[ECustomTypeId::GPSEphemeris1] = gPSEphemeris1Inserter;
        _ctInserters[ECustomTypeId::GpsEphReqData] = gpsEphReqDataInserter;
        _ctInserters[ECustomTypeId::GpsNavData1] = gpsNavData1Inserter;
        _ctInserters[ECustomTypeId::GpsRawNavData1] = gpsRawNavData1Inserter;
        _ctInserters[ECustomTypeId::Header] = headerInserter;
        _ctInserters[ECustomTypeId::IonoParams1] = ionoParams1Inserter;
        _ctInserters[ECustomTypeId::SlotRec] = slotRecInserter;
        _ctInserters[ECustomTypeId::Smooth] = smoothInserter;
        _ctInserters[ECustomTypeId::SpecData] = specDataInserter;
        _ctInserters[ECustomTypeId::SvData0] = svData0Inserter;
        _ctInserters[ECustomTypeId::SvData1] = svData1Inserter;
        _ctInserters[ECustomTypeId::SvData2] = svData2Inserter;
        _ctInserters[ECustomTypeId::UtcOffs] = utcOffsInserter;

        int maxIdForClkOffs = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_ClkOffs`").toInt();
        _ctCurrentMaxId[ECustomTypeId::ClkOffs] = maxIdForClkOffs;
        int maxIdForExtSpecData = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_ExtSpecData`").toInt();
        _ctCurrentMaxId[ECustomTypeId::ExtSpecData] = maxIdForExtSpecData;
        int maxIdForGPSAlm1 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_GPSAlm1`").toInt();
        _ctCurrentMaxId[ECustomTypeId::GPSAlm1] = maxIdForGPSAlm1;
        int maxIdForGPSEphemeris1 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_GPSEphemeris1`").toInt();
        _ctCurrentMaxId[ECustomTypeId::GPSEphemeris1] = maxIdForGPSEphemeris1;
        int maxIdForGpsEphReqData = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_GpsEphReqData`").toInt();
        _ctCurrentMaxId[ECustomTypeId::GpsEphReqData] = maxIdForGpsEphReqData;
        int maxIdForGpsNavData1 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_GpsNavData1`").toInt();
        _ctCurrentMaxId[ECustomTypeId::GpsNavData1] = maxIdForGpsNavData1;
        int maxIdForGpsRawNavData1 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_GpsRawNavData1`").toInt();
        _ctCurrentMaxId[ECustomTypeId::GpsRawNavData1] = maxIdForGpsRawNavData1;
        int maxIdForHeader = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_Header`").toInt();
        _ctCurrentMaxId[ECustomTypeId::Header] = maxIdForHeader;
        int maxIdForIonoParams1 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_IonoParams1`").toInt();
        _ctCurrentMaxId[ECustomTypeId::IonoParams1] = maxIdForIonoParams1;
        int maxIdForSlotRec = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_SlotRec`").toInt();
        _ctCurrentMaxId[ECustomTypeId::SlotRec] = maxIdForSlotRec;
        int maxIdForSmooth = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_Smooth`").toInt();
        _ctCurrentMaxId[ECustomTypeId::Smooth] = maxIdForSmooth;
        int maxIdForSpecData = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_SpecData`").toInt();
        _ctCurrentMaxId[ECustomTypeId::SpecData] = maxIdForSpecData;
        int maxIdForSvData0 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_SvData0`").toInt();
        _ctCurrentMaxId[ECustomTypeId::SvData0] = maxIdForSvData0;
        int maxIdForSvData1 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_SvData1`").toInt();
        _ctCurrentMaxId[ECustomTypeId::SvData1] = maxIdForSvData1;
        int maxIdForSvData2 = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_SvData2`").toInt();
        _ctCurrentMaxId[ECustomTypeId::SvData2] = maxIdForSvData2;
        int maxIdForUtcOffs = _dbHelper->ExecuteSingleValueQuery("SELECT MAX(`id`) FROM `ct_UtcOffs`").toInt();
        _ctCurrentMaxId[ECustomTypeId::UtcOffs] = maxIdForUtcOffs;
    }

    void MySqlSink::serializeMessage( StdMessage* msg, QVariantList& out )
    {
        switch (msg->IdNumber())
        {
        case EMessageId::AngularVelocity:
            {
                auto c = dynamic_cast<AngularVelocityStdMessage*>(msg);
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->X());
                out << _serializer.Serialize(c->Y());
                out << _serializer.Serialize(c->Z());
                out << _serializer.Serialize(c->Rms());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::AntName:
            {
                auto c = dynamic_cast<AntNameStdMessage*>(msg);
                out << _serializer.Serialize(c->Name());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::BaseInfo:
            {
                auto c = dynamic_cast<BaseInfoStdMessage*>(msg);
                out << _serializer.Serialize(c->X());
                out << _serializer.Serialize(c->Y());
                out << _serializer.Serialize(c->Z());
                out << _serializer.Serialize(c->IdField());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Baseline:
            {
                auto c = dynamic_cast<BaselineStdMessage*>(msg);
                out << _serializer.Serialize(c->X());
                out << _serializer.Serialize(c->Y());
                out << _serializer.Serialize(c->Z());
                out << _serializer.Serialize(c->Sigma());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::ClockOffsets:
            {
                auto c = dynamic_cast<ClockOffsetsStdMessage*>(msg);
                out << _serializer.Serialize(c->Sample());
                out << _serializer.Serialize(c->Reserved());
                out << _serializer.Serialize(c->RecSize());
                out << addCustomTypesAndSerialize(c->Offs());
                out << _serializer.Serialize(c->Crc16());
            }
            break;
        case EMessageId::CNR:
            {
                auto c = dynamic_cast<CNRStdMessage*>(msg);
                out << _serializer.Serialize(c->Cnr());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::CNR4:
            {
                auto c = dynamic_cast<CNR4StdMessage*>(msg);
                out << _serializer.Serialize(c->CnrX4());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::CompRawNavData:
            {
                auto c = dynamic_cast<CompRawNavDataStdMessage*>(msg);
                out << _serializer.Serialize(c->Prn());
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Type());
                out << _serializer.Serialize(c->Len());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::CP:
            {
                auto c = dynamic_cast<CPStdMessage*>(msg);
                out << _serializer.Serialize(c->Cp());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Dops:
            {
                auto c = dynamic_cast<DopsStdMessage*>(msg);
                out << _serializer.Serialize(c->Hdop());
                out << _serializer.Serialize(c->Vdop());
                out << _serializer.Serialize(c->Tdop());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::DP:
            {
                auto c = dynamic_cast<DPStdMessage*>(msg);
                out << _serializer.Serialize(c->Dp());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::EpochEnd:
            {
                auto c = dynamic_cast<EpochEndStdMessage*>(msg);
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::EpochTime:
            {
                auto c = dynamic_cast<EpochTimeStdMessage*>(msg);
                out << _serializer.Serialize(c->Tod());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::ER:
            {
                auto c = dynamic_cast<ERStdMessage*>(msg);
                out << _serializer.Serialize(c->Error());
            }
            break;
        case EMessageId::Event:
            {
                auto c = dynamic_cast<EventStdMessage*>(msg);
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Type());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::ExtEvent:
            {
                auto c = dynamic_cast<ExtEventStdMessage*>(msg);
                out << _serializer.Serialize(c->Ms());
                out << _serializer.Serialize(c->Ns());
                out << _serializer.Serialize(c->TimeScale());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::FileId:
            {
                auto c = dynamic_cast<FileIdStdMessage*>(msg);
                out << _serializer.Serialize(c->IdField());
                out << _serializer.Serialize(c->Description());
            }
            break;
        case EMessageId::Flags:
            {
                auto c = dynamic_cast<FlagsStdMessage*>(msg);
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GALAlm:
            {
                auto c = dynamic_cast<GALAlmStdMessage*>(msg);
                out << addCustomType(c->Gps().get());
                out << _serializer.Serialize(c->Iod());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GALEphemeris:
            {
                auto c = dynamic_cast<GALEphemerisStdMessage*>(msg);
                out << addCustomType(c->Req().get());
                out << _serializer.Serialize(c->BgdE1E5a());
                out << _serializer.Serialize(c->BgdE1E5b());
                out << _serializer.Serialize(c->Ai0());
                out << _serializer.Serialize(c->Ai1());
                out << _serializer.Serialize(c->Ai2());
                out << _serializer.Serialize(c->Sfi());
                out << _serializer.Serialize(c->NavType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GalRawNavData:
            {
                auto c = dynamic_cast<GalRawNavDataStdMessage*>(msg);
                out << _serializer.Serialize(c->Prn());
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Type());
                out << _serializer.Serialize(c->Len());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GalUtcGpsParam:
            {
                auto c = dynamic_cast<GalUtcGpsParamStdMessage*>(msg);
                out << addCustomType(c->Utc().get());
                out << _serializer.Serialize(c->A0g());
                out << _serializer.Serialize(c->A1g());
                out << _serializer.Serialize(c->T0g());
                out << _serializer.Serialize(c->Wn0g());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GeoPos:
            {
                auto c = dynamic_cast<GeoPosStdMessage*>(msg);
                out << _serializer.Serialize(c->Lat());
                out << _serializer.Serialize(c->Lon());
                out << _serializer.Serialize(c->Alt());
                out << _serializer.Serialize(c->PSigma());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GeoVel:
            {
                auto c = dynamic_cast<GeoVelStdMessage*>(msg);
                out << _serializer.Serialize(c->Lat());
                out << _serializer.Serialize(c->Lon());
                out << _serializer.Serialize(c->Alt());
                out << _serializer.Serialize(c->PSigma());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GLOAlmanac:
            {
                auto c = dynamic_cast<GLOAlmanacStdMessage*>(msg);
                out << _serializer.Serialize(c->Sv());
                out << _serializer.Serialize(c->FrqNum());
                out << _serializer.Serialize(c->Dna());
                out << _serializer.Serialize(c->Tlam());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->TauN());
                out << _serializer.Serialize(c->TauSys());
                out << _serializer.Serialize(c->Ecc());
                out << _serializer.Serialize(c->Lambda());
                out << _serializer.Serialize(c->ArgPer());
                out << _serializer.Serialize(c->DelT());
                out << _serializer.Serialize(c->DelTdt());
                out << _serializer.Serialize(c->Deli());
                out << _serializer.Serialize(c->N4());
                if (c->BodySize() == 52)
                {
                    // Optional Data Block
                    out << _serializer.Serialize(c->NavType());
                    out << _serializer.Serialize(c->GammaN());
                } else {
                    out << QVariant(QVariant::UInt);
                    out << QVariant(QVariant::Double);
                }
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GLOEphemeris:
            {
                auto c = dynamic_cast<GLOEphemerisStdMessage*>(msg);
                out << _serializer.Serialize(c->Sv());
                out << _serializer.Serialize(c->FrqNum());
                out << _serializer.Serialize(c->Dne());
                out << _serializer.Serialize(c->Tk());
                out << _serializer.Serialize(c->Tb());
                out << _serializer.Serialize(c->Health());
                out << _serializer.Serialize(c->Age());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->R());
                out << _serializer.Serialize(c->V());
                out << _serializer.Serialize(c->W());
                out << _serializer.Serialize(c->TauSys());
                out << _serializer.Serialize(c->Tau());
                out << _serializer.Serialize(c->Gamma());
                out << _serializer.Serialize(c->FDelTauN());
                out << _serializer.Serialize(c->NFt());
                out << _serializer.Serialize(c->NN4());
                out << _serializer.Serialize(c->Flags2());
                if (c->BodySize() == 103)
                {
                    // Optional Data Block
                    out << _serializer.Serialize(c->NavType());
                    out << _serializer.Serialize(c->Beta());
                    out << _serializer.Serialize(c->TauSysDot());
                    out << _serializer.Serialize(c->Ec());
                    out << _serializer.Serialize(c->Ee());
                    out << _serializer.Serialize(c->Fc());
                    out << _serializer.Serialize(c->Fe());
                    out << _serializer.Serialize(c->Reserv());
                } else {
                    out << QVariant(QVariant::UInt);
                    out << QVariant(QVariant::Double);
                    out << QVariant(QVariant::Double);
                    out << QVariant(QVariant::UInt);
                    out << QVariant(QVariant::UInt);
                    out << QVariant(QVariant::Int);
                    out << QVariant(QVariant::Int);
                    out << QVariant(QVariant::UInt);
                }
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GloNavData:
            {
                auto c = dynamic_cast<GloNavDataStdMessage*>(msg);
                out << _serializer.Serialize(c->RecSize());
                out << addCustomTypesAndSerialize(c->Dat());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GloPhaseDelay:
            {
                auto c = dynamic_cast<GloPhaseDelayStdMessage*>(msg);
                out << _serializer.Serialize(c->Fcn());
                out << _serializer.Serialize(c->Phase());
                out << _serializer.Serialize(c->Range());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GloRawNavData:
            {
                auto c = dynamic_cast<GloRawNavDataStdMessage*>(msg);
                out << _serializer.Serialize(c->Num());
                out << _serializer.Serialize(c->Fcn());
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Type());
                out << _serializer.Serialize(c->Len());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GLOTime:
            {
                auto c = dynamic_cast<GLOTimeStdMessage*>(msg);
                out << _serializer.Serialize(c->Tod());
                out << _serializer.Serialize(c->Dn());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GloUtcGpsParam:
            {
                auto c = dynamic_cast<GloUtcGpsParamStdMessage*>(msg);
                out << _serializer.Serialize(c->TauSys());
                out << _serializer.Serialize(c->TauGps());
                out << _serializer.Serialize(c->B1());
                out << _serializer.Serialize(c->B2());
                out << _serializer.Serialize(c->KP());
                out << _serializer.Serialize(c->N4());
                out << _serializer.Serialize(c->Dn());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GPSAlm0:
            {
                auto c = dynamic_cast<GPSAlm0StdMessage*>(msg);
                out << _serializer.Serialize(c->Sv());
                out << _serializer.Serialize(c->Wna());
                out << _serializer.Serialize(c->Toa());
                out << _serializer.Serialize(c->HealthA());
                out << _serializer.Serialize(c->HealthS());
                out << _serializer.Serialize(c->Config());
                out << _serializer.Serialize(c->Af1());
                out << _serializer.Serialize(c->Af0());
                out << _serializer.Serialize(c->RootA());
                out << _serializer.Serialize(c->Ecc());
                out << _serializer.Serialize(c->M0());
                out << _serializer.Serialize(c->Omega0());
                out << _serializer.Serialize(c->ArgPer());
                out << _serializer.Serialize(c->Deli());
                out << _serializer.Serialize(c->OmegaDot());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GPSEphemeris0:
            {
                auto c = dynamic_cast<GPSEphemeris0StdMessage*>(msg);
                out << addCustomType(c->Req().get());
                if (c->BodySize() == 148)
                {
                    // Optional Data Block
                    out << _serializer.Serialize(c->CNavType());
                    out << _serializer.Serialize(c->LTope());
                    out << _serializer.Serialize(c->LTopc());
                    out << _serializer.Serialize(c->DADot());
                    out << _serializer.Serialize(c->FDelnDot());
                    out << _serializer.Serialize(c->CURAoe());
                    out << _serializer.Serialize(c->CURAoc());
                    out << _serializer.Serialize(c->CURAoc1());
                    out << _serializer.Serialize(c->CURAoc2());
                } else {
                    out << QVariant(QVariant::UInt);
                    out << QVariant(QVariant::Int);
                    out << QVariant(QVariant::Int);
                    out << QVariant(QVariant::Double);
                    out << QVariant(QVariant::Double);
                    out << QVariant(QVariant::Int);
                    out << QVariant(QVariant::Int);
                    out << QVariant(QVariant::Int);
                    out << QVariant(QVariant::Int);
                }
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GpsNavData0:
            {
                auto c = dynamic_cast<GpsNavData0StdMessage*>(msg);
                out << _serializer.Serialize(c->RecSize());
                out << addCustomTypesAndSerialize(c->Dat());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GpsRawNavData0:
            {
                auto c = dynamic_cast<GpsRawNavData0StdMessage*>(msg);
                out << _serializer.Serialize(c->Prn());
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Type());
                out << _serializer.Serialize(c->Len());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GPSTime:
            {
                auto c = dynamic_cast<GPSTimeStdMessage*>(msg);
                out << _serializer.Serialize(c->Tow());
                out << _serializer.Serialize(c->Wn());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::GpsUtcParam:
            {
                auto c = dynamic_cast<GpsUtcParamStdMessage*>(msg);
                out << addCustomType(c->Utc().get());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::IAmp:
            {
                auto c = dynamic_cast<IAmpStdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::InertialMeasurements:
            {
                auto c = dynamic_cast<InertialMeasurementsStdMessage*>(msg);
                out << _serializer.Serialize(c->Accelerations());
                out << _serializer.Serialize(c->AngularVelocities());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::IonoDelay:
            {
                auto c = dynamic_cast<IonoDelayStdMessage*>(msg);
                out << _serializer.Serialize(c->Delay());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::IonoParams0:
            {
                auto c = dynamic_cast<IonoParams0StdMessage*>(msg);
                out << _serializer.Serialize(c->Tot());
                out << _serializer.Serialize(c->Wn());
                out << _serializer.Serialize(c->Alpha0());
                out << _serializer.Serialize(c->Alpha1());
                out << _serializer.Serialize(c->Alpha2());
                out << _serializer.Serialize(c->Alpha3());
                out << _serializer.Serialize(c->Beta0());
                out << _serializer.Serialize(c->Beta1());
                out << _serializer.Serialize(c->Beta2());
                out << _serializer.Serialize(c->Beta3());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Latency:
            {
                auto c = dynamic_cast<LatencyStdMessage*>(msg);
                out << _serializer.Serialize(c->Lt());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::LoggingHistory:
            {
                auto c = dynamic_cast<LoggingHistoryStdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::MsgFmt:
            {
                auto c = dynamic_cast<MsgFmtStdMessage*>(msg);
                out << _serializer.Serialize(c->IdField());
                out << _serializer.Serialize(c->MajorVer());
                out << _serializer.Serialize(c->MinorVer());
                out << _serializer.SerializeChar(c->Order());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::NavStatus:
            {
                auto c = dynamic_cast<NavStatusStdMessage*>(msg);
                out << _serializer.Serialize(c->Ns());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Params:
            {
                auto c = dynamic_cast<ParamsStdMessage*>(msg);
                out << _serializer.Serialize(c->Params());
                out << _serializer.Serialize(c->Delim());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Pos:
            {
                auto c = dynamic_cast<PosStdMessage*>(msg);
                out << _serializer.Serialize(c->X());
                out << _serializer.Serialize(c->Y());
                out << _serializer.Serialize(c->Z());
                out << _serializer.Serialize(c->Sigma());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::PosCompTime:
            {
                auto c = dynamic_cast<PosCompTimeStdMessage*>(msg);
                out << _serializer.Serialize(c->Pt());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::PosCov:
            {
                auto c = dynamic_cast<PosCovStdMessage*>(msg);
                out << _serializer.Serialize(c->Xx());
                out << _serializer.Serialize(c->Yy());
                out << _serializer.Serialize(c->Zz());
                out << _serializer.Serialize(c->Tt());
                out << _serializer.Serialize(c->Xy());
                out << _serializer.Serialize(c->Xz());
                out << _serializer.Serialize(c->Xt());
                out << _serializer.Serialize(c->Yz());
                out << _serializer.Serialize(c->Yt());
                out << _serializer.Serialize(c->Zt());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::PosStat:
            {
                auto c = dynamic_cast<PosStatStdMessage*>(msg);
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->GpsLocked());
                out << _serializer.Serialize(c->GloLocked());
                out << _serializer.Serialize(c->GpsAvail());
                out << _serializer.Serialize(c->GloAvail());
                out << _serializer.Serialize(c->GpsUsed());
                out << _serializer.Serialize(c->GloUsed());
                out << _serializer.Serialize(c->FixProg());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::PosVel:
            {
                auto c = dynamic_cast<PosVelStdMessage*>(msg);
                out << _serializer.Serialize(c->X());
                out << _serializer.Serialize(c->Y());
                out << _serializer.Serialize(c->Z());
                out << _serializer.Serialize(c->PSigma());
                out << _serializer.Serialize(c->Vx());
                out << _serializer.Serialize(c->Vy());
                out << _serializer.Serialize(c->Vz());
                out << _serializer.Serialize(c->VSigma());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::PosVelVector:
            {
                auto c = dynamic_cast<PosVelVectorStdMessage*>(msg);
                out << _serializer.Serialize(c->Sample());
                out << _serializer.Serialize(c->Delta());
                out << _serializer.Serialize(c->Word1());
                out << _serializer.Serialize(c->Word2());
                out << _serializer.Serialize(c->Word3());
                out << _serializer.Serialize(c->Word4());
                out << _serializer.Serialize(c->Word5());
                out << _serializer.Serialize(c->Word6());
                out << _serializer.Serialize(c->Word7());
                out << _serializer.Serialize(c->Word8());
                out << _serializer.Serialize(c->Word9());
                out << _serializer.Serialize(c->Crc16());
            }
            break;
        case EMessageId::PPSOffset:
            {
                auto c = dynamic_cast<PPSOffsetStdMessage*>(msg);
                out << _serializer.Serialize(c->Offs());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::PR:
            {
                auto c = dynamic_cast<PRStdMessage*>(msg);
                out << _serializer.Serialize(c->Pr());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::QAmp:
            {
                auto c = dynamic_cast<QAmpStdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::QZSSAlm:
            {
                auto c = dynamic_cast<QZSSAlmStdMessage*>(msg);
                out << addCustomType(c->Gps().get());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::QZSSEphemeris:
            {
                auto c = dynamic_cast<QZSSEphemerisStdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::QzssIonoParams:
            {
                auto c = dynamic_cast<QzssIonoParamsStdMessage*>(msg);
                out << addCustomType(c->Par().get());
            }
            break;
        case EMessageId::QzssNavData:
            {
                auto c = dynamic_cast<QzssNavDataStdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::QzssRawNavData:
            {
                auto c = dynamic_cast<QzssRawNavDataStdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::QzssUtcParam:
            {
                auto c = dynamic_cast<QzssUtcParamStdMessage*>(msg);
                out << addCustomType(c->Utc().get());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RawMeas:
            {
                auto c = dynamic_cast<RawMeasStdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::RCPRc1:
            {
                auto c = dynamic_cast<RCPRc1StdMessage*>(msg);
                out << _serializer.Serialize(c->Rcp());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RCPRC0:
            {
                auto c = dynamic_cast<RCPRC0StdMessage*>(msg);
                out << _serializer.Serialize(c->Rcp());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvDate:
            {
                auto c = dynamic_cast<RcvDateStdMessage*>(msg);
                out << _serializer.Serialize(c->Year());
                out << _serializer.Serialize(c->Month());
                out << _serializer.Serialize(c->Day());
                out << _serializer.Serialize(c->Base());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvGALTimeOffset:
            {
                auto c = dynamic_cast<RcvGALTimeOffsetStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Sval());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvGLOTimeOffset:
            {
                auto c = dynamic_cast<RcvGLOTimeOffsetStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Sval());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvGPSTimeOffset:
            {
                auto c = dynamic_cast<RcvGPSTimeOffsetStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Sval());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvOscOffs:
            {
                auto c = dynamic_cast<RcvOscOffsStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvQZSSTimeOffset:
            {
                auto c = dynamic_cast<RcvQZSSTimeOffsetStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Sval());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvSBASTimeOffset:
            {
                auto c = dynamic_cast<RcvSBASTimeOffsetStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Sval());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvTime:
            {
                auto c = dynamic_cast<RcvTimeStdMessage*>(msg);
                out << _serializer.Serialize(c->Tod());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvTimeAccuracy:
            {
                auto c = dynamic_cast<RcvTimeAccuracyStdMessage*>(msg);
                out << _serializer.Serialize(c->Acc());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvTimeOffsAtPPS:
            {
                auto c = dynamic_cast<RcvTimeOffsAtPPSStdMessage*>(msg);
                out << _serializer.Serialize(c->Offs());
                out << _serializer.Serialize(c->TimeScale());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvTimeOffset:
            {
                auto c = dynamic_cast<RcvTimeOffsetStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Sval());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RcvTimeOffsetDot:
            {
                auto c = dynamic_cast<RcvTimeOffsetDotStdMessage*>(msg);
                out << _serializer.Serialize(c->Val());
                out << _serializer.Serialize(c->Sval());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RE:
            {
                auto c = dynamic_cast<REStdMessage*>(msg);
                out << _serializer.Serialize(c->Reply());
            }
            break;
        case EMessageId::RefEpoch:
            {
                auto c = dynamic_cast<RefEpochStdMessage*>(msg);
                out << _serializer.Serialize(c->Sample());
                out << _serializer.Serialize(c->Scale());
                out << _serializer.Serialize(c->Reftime());
                out << _serializer.Serialize(c->Crc16());
            }
            break;
        case EMessageId::Rms:
            {
                auto c = dynamic_cast<RmsStdMessage*>(msg);
                out << _serializer.Serialize(c->Hpos());
                out << _serializer.Serialize(c->Vpos());
                out << _serializer.Serialize(c->Hvel());
                out << _serializer.Serialize(c->Vvel());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RotationAngles:
            {
                auto c = dynamic_cast<RotationAnglesStdMessage*>(msg);
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Pitch());
                out << _serializer.Serialize(c->Roll());
                out << _serializer.Serialize(c->Heading());
                out << _serializer.Serialize(c->PitchRms());
                out << _serializer.Serialize(c->RollRms());
                out << _serializer.Serialize(c->HeadingRms());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RotationMatrix:
            {
                auto c = dynamic_cast<RotationMatrixStdMessage*>(msg);
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Q00());
                out << _serializer.Serialize(c->Q01());
                out << _serializer.Serialize(c->Q02());
                out << _serializer.Serialize(c->Q12());
                out << _serializer.Serialize(c->Rms());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Flag());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RotationMatrixAndVectors:
            {
                auto c = dynamic_cast<RotationMatrixAndVectorsStdMessage*>(msg);
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Q00());
                out << _serializer.Serialize(c->Q01());
                out << _serializer.Serialize(c->Q02());
                out << _serializer.Serialize(c->Q12());
                out << _serializer.Serialize(c->Rms());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Flag());
                out << _serializer.Serialize(c->Bl0());
                out << _serializer.Serialize(c->Bl1());
                out << _serializer.Serialize(c->Bl2());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::RPR:
            {
                auto c = dynamic_cast<RPRStdMessage*>(msg);
                out << _serializer.Serialize(c->Rpr());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SatAzimuth:
            {
                auto c = dynamic_cast<SatAzimuthStdMessage*>(msg);
                out << _serializer.Serialize(c->Azim());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SatElevation:
            {
                auto c = dynamic_cast<SatElevationStdMessage*>(msg);
                out << _serializer.Serialize(c->Elev());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SatIndex:
            {
                auto c = dynamic_cast<SatIndexStdMessage*>(msg);
                out << _serializer.Serialize(c->Usi());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SatNumbers:
            {
                auto c = dynamic_cast<SatNumbersStdMessage*>(msg);
                out << _serializer.Serialize(c->Osn());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SBASAlmanac:
            {
                auto c = dynamic_cast<SBASAlmanacStdMessage*>(msg);
                out << _serializer.Serialize(c->WaasPrn());
                out << _serializer.Serialize(c->GpsPrn());
                out << _serializer.Serialize(c->IdField());
                out << _serializer.Serialize(c->HealthS());
                out << _serializer.Serialize(c->Tod());
                out << _serializer.Serialize(c->Xg());
                out << _serializer.Serialize(c->Yg());
                out << _serializer.Serialize(c->Zg());
                out << _serializer.Serialize(c->Vxg());
                out << _serializer.Serialize(c->Vyg());
                out << _serializer.Serialize(c->Vzg());
                out << _serializer.Serialize(c->Tow());
                out << _serializer.Serialize(c->Wn());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SBASEhemeris:
            {
                auto c = dynamic_cast<SBASEhemerisStdMessage*>(msg);
                out << _serializer.Serialize(c->WaasPrn());
                out << _serializer.Serialize(c->GpsPrn());
                out << _serializer.Serialize(c->Iod());
                out << _serializer.Serialize(c->Acc());
                out << _serializer.Serialize(c->Tod());
                out << _serializer.Serialize(c->Xg());
                out << _serializer.Serialize(c->Yg());
                out << _serializer.Serialize(c->Zg());
                out << _serializer.Serialize(c->Vxg());
                out << _serializer.Serialize(c->Vyg());
                out << _serializer.Serialize(c->Vzg());
                out << _serializer.Serialize(c->Vvxg());
                out << _serializer.Serialize(c->Vvyg());
                out << _serializer.Serialize(c->Vvzg());
                out << _serializer.Serialize(c->Agf0());
                out << _serializer.Serialize(c->Agf1());
                out << _serializer.Serialize(c->Tow());
                out << _serializer.Serialize(c->Wn());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SbasRawNavData:
            {
                auto c = dynamic_cast<SbasRawNavDataStdMessage*>(msg);
                out << _serializer.Serialize(c->Prn());
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Reserv());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SbasUtcParam:
            {
                auto c = dynamic_cast<SbasUtcParamStdMessage*>(msg);
                out << addCustomType(c->Utc().get());
                out << _serializer.Serialize(c->Utcsi());
                out << _serializer.Serialize(c->Tow());
                out << _serializer.Serialize(c->Wn());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SC:
            {
                auto c = dynamic_cast<SCStdMessage*>(msg);
                out << addCustomTypesAndSerialize(c->Smooth());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SCP:
            {
                auto c = dynamic_cast<SCPStdMessage*>(msg);
                out << _serializer.Serialize(c->Scp());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Security0:
            {
                auto c = dynamic_cast<Security0StdMessage*>(msg);
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Security1:
            {
                auto c = dynamic_cast<Security1StdMessage*>(msg);
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Crc16());
            }
            break;
        case EMessageId::SolutionTime:
            {
                auto c = dynamic_cast<SolutionTimeStdMessage*>(msg);
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Spectrum0:
            {
                auto c = dynamic_cast<Spectrum0StdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::Spectrum1:
            {
                auto c = dynamic_cast<Spectrum1StdMessage*>(msg);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case EMessageId::SPR:
            {
                auto c = dynamic_cast<SPRStdMessage*>(msg);
                out << _serializer.Serialize(c->Spr());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SRDP:
            {
                auto c = dynamic_cast<SRDPStdMessage*>(msg);
                out << _serializer.Serialize(c->Srdp());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SRPR:
            {
                auto c = dynamic_cast<SRPRStdMessage*>(msg);
                out << _serializer.Serialize(c->Srpr());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::SS:
            {
                auto c = dynamic_cast<SSStdMessage*>(msg);
                out << _serializer.Serialize(c->Smooth());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::TrackingTime:
            {
                auto c = dynamic_cast<TrackingTimeStdMessage*>(msg);
                out << _serializer.Serialize(c->Tt());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::TrackingTimeCA:
            {
                auto c = dynamic_cast<TrackingTimeCAStdMessage*>(msg);
                out << _serializer.Serialize(c->Tt());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Vel:
            {
                auto c = dynamic_cast<VelStdMessage*>(msg);
                out << _serializer.Serialize(c->X());
                out << _serializer.Serialize(c->Y());
                out << _serializer.Serialize(c->Z());
                out << _serializer.Serialize(c->Sigma());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::VelCov:
            {
                auto c = dynamic_cast<VelCovStdMessage*>(msg);
                out << _serializer.Serialize(c->Xx());
                out << _serializer.Serialize(c->Yy());
                out << _serializer.Serialize(c->Zz());
                out << _serializer.Serialize(c->Tt());
                out << _serializer.Serialize(c->Xy());
                out << _serializer.Serialize(c->Xz());
                out << _serializer.Serialize(c->Xt());
                out << _serializer.Serialize(c->Yz());
                out << _serializer.Serialize(c->Yt());
                out << _serializer.Serialize(c->Zt());
                out << _serializer.Serialize(c->SolType());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case EMessageId::Wrapper:
            {
                auto c = dynamic_cast<WrapperStdMessage*>(msg);
                out << _serializer.Serialize(c->IdField());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        default:
            throw InvalidOperationException();
        }
    }

    void MySqlSink::serializeCustomType( CustomType* ct, QVariantList& out )
    {
        switch (ct->IdNumber())
        {
        case ECustomTypeId::ClkOffs:
            {
                auto c = dynamic_cast<ClkOffsCustomType*>(ct);
                out << _serializer.Serialize(c->Word1());
                out << _serializer.Serialize(c->Word2());
            }
            break;
        case ECustomTypeId::ExtSpecData:
            {
                auto c = dynamic_cast<ExtSpecDataCustomType*>(ct);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case ECustomTypeId::GPSAlm1:
            {
                auto c = dynamic_cast<GPSAlm1CustomType*>(ct);
                out << _serializer.Serialize(c->Sv());
                out << _serializer.Serialize(c->Wna());
                out << _serializer.Serialize(c->Toa());
                out << _serializer.Serialize(c->HealthA());
                out << _serializer.Serialize(c->HealthS());
                out << _serializer.Serialize(c->Config());
                out << _serializer.Serialize(c->Af1());
                out << _serializer.Serialize(c->Af0());
                out << _serializer.Serialize(c->RootA());
                out << _serializer.Serialize(c->Ecc());
                out << _serializer.Serialize(c->M0());
                out << _serializer.Serialize(c->Omega0());
                out << _serializer.Serialize(c->ArgPer());
                out << _serializer.Serialize(c->Deli());
                out << _serializer.Serialize(c->OmegaDot());
            }
            break;
        case ECustomTypeId::GPSEphemeris1:
            {
                auto c = dynamic_cast<GPSEphemeris1CustomType*>(ct);
                out << addCustomType(c->Req().get());
                out << _serializer.Serialize(c->CNavType());
                out << _serializer.Serialize(c->LTope());
                out << _serializer.Serialize(c->LTopc());
                out << _serializer.Serialize(c->DADot());
                out << _serializer.Serialize(c->FDelnDot());
                out << _serializer.Serialize(c->CURAoe());
                out << _serializer.Serialize(c->CURAoc());
                out << _serializer.Serialize(c->CURAoc1());
                out << _serializer.Serialize(c->CURAoc2());
            }
            break;
        case ECustomTypeId::GpsEphReqData:
            {
                auto c = dynamic_cast<GpsEphReqDataCustomType*>(ct);
                out << _serializer.Serialize(c->Sv());
                out << _serializer.Serialize(c->Tow());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->Iodc());
                out << _serializer.Serialize(c->Toc());
                out << _serializer.Serialize(c->Ura());
                out << _serializer.Serialize(c->HealthS());
                out << _serializer.Serialize(c->Wn());
                out << _serializer.Serialize(c->Tgd());
                out << _serializer.Serialize(c->Af2());
                out << _serializer.Serialize(c->Af1());
                out << _serializer.Serialize(c->Af0());
                out << _serializer.Serialize(c->Toe());
                out << _serializer.Serialize(c->Iode());
                out << _serializer.Serialize(c->RootA());
                out << _serializer.Serialize(c->Ecc());
                out << _serializer.Serialize(c->M0());
                out << _serializer.Serialize(c->Omega0());
                out << _serializer.Serialize(c->Inc0());
                out << _serializer.Serialize(c->ArgPer());
                out << _serializer.Serialize(c->Deln());
                out << _serializer.Serialize(c->OmegaDot());
                out << _serializer.Serialize(c->IncDot());
                out << _serializer.Serialize(c->Crc());
                out << _serializer.Serialize(c->Crs());
                out << _serializer.Serialize(c->Cuc());
                out << _serializer.Serialize(c->Cus());
                out << _serializer.Serialize(c->Cic());
                out << _serializer.Serialize(c->Cis());
            }
            break;
        case ECustomTypeId::GpsNavData1:
            {
                auto c = dynamic_cast<GpsNavData1CustomType*>(ct);
                out << _serializer.Serialize(c->RecSize());
                out << addCustomTypesAndSerialize(c->Dat());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case ECustomTypeId::GpsRawNavData1:
            {
                auto c = dynamic_cast<GpsRawNavData1CustomType*>(ct);
                out << _serializer.Serialize(c->Prn());
                out << _serializer.Serialize(c->Time());
                out << _serializer.Serialize(c->Type());
                out << _serializer.Serialize(c->Len());
                out << _serializer.Serialize(c->Data());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case ECustomTypeId::Header:
            {
                auto c = dynamic_cast<HeaderCustomType*>(ct);
                out << _serializer.Serialize(c->Refrange());
                out << _serializer.Serialize(c->Usi());
                out << _serializer.Serialize(c->Num());
            }
            break;
        case ECustomTypeId::IonoParams1:
            {
                auto c = dynamic_cast<IonoParams1CustomType*>(ct);
                out << _serializer.Serialize(c->Tot());
                out << _serializer.Serialize(c->Wn());
                out << _serializer.Serialize(c->Alpha0());
                out << _serializer.Serialize(c->Alpha1());
                out << _serializer.Serialize(c->Alpha2());
                out << _serializer.Serialize(c->Alpha3());
                out << _serializer.Serialize(c->Beta0());
                out << _serializer.Serialize(c->Beta1());
                out << _serializer.Serialize(c->Beta2());
                out << _serializer.Serialize(c->Beta3());
                out << _serializer.Serialize(c->Cs());
            }
            break;
        case ECustomTypeId::SlotRec:
            {
                auto c = dynamic_cast<SlotRecCustomType*>(ct);
                out << _serializer.Serialize(c->SvstOrDelrange());
                out << _serializer.Serialize(c->Word1());
                out << _serializer.Serialize(c->Flags());
                out << _serializer.Serialize(c->Lock());
                out << _serializer.Serialize(c->Word2());
            }
            break;
        case ECustomTypeId::Smooth:
            {
                auto c = dynamic_cast<SmoothCustomType*>(ct);
                out << _serializer.Serialize(c->Value());
                out << _serializer.Serialize(c->Interval());
            }
            break;
        case ECustomTypeId::SpecData:
            {
                auto c = dynamic_cast<SpecDataCustomType*>(ct);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case ECustomTypeId::SvData0:
            {
                auto c = dynamic_cast<SvData0CustomType*>(ct);
                out << _serializer.Serialize(c->Prn());
                out << _serializer.Serialize(c->Cnt());
                out << _serializer.Serialize(c->Data());
            }
            break;
        case ECustomTypeId::SvData1:
            {
                auto c = dynamic_cast<SvData1CustomType*>(ct);
                out << _serializer.Serialize(c->Fcn1());
                out << _serializer.Serialize(c->Cnt());
                out << _serializer.Serialize(c->Data());
            }
            break;
        case ECustomTypeId::SvData2:
            {
                auto c = dynamic_cast<SvData2CustomType*>(ct);
                
                throw ProjectBase::NotImplementedException();
            }
            break;
        case ECustomTypeId::UtcOffs:
            {
                auto c = dynamic_cast<UtcOffsCustomType*>(ct);
                out << _serializer.Serialize(c->A0());
                out << _serializer.Serialize(c->A1());
                out << _serializer.Serialize(c->Tot());
                out << _serializer.Serialize(c->Wnt());
                out << _serializer.Serialize(c->Dtls());
                out << _serializer.Serialize(c->Dn());
                out << _serializer.Serialize(c->Wnlsf());
                out << _serializer.Serialize(c->Dtlsf());
            }
            break;
        default:
            throw InvalidOperationException();
        }
    }
}
