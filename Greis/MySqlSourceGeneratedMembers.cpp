#include "MySqlSource.h"
#include <vector>
#include "ProjectBase\SmartPtr.h"
#include "ProjectBase\Connection.h"
#include "ECustomTypeId.h"
#include "JpsFile.h"
#include "AllStdMessages.h"

using namespace ProjectBase;

namespace Greis
{
    JpsFile::UniquePtr_t MySqlSource::ReadRange( const QDateTime& from, const QDateTime& to )
    {
        _ctBuffer.clear();

        _from = from;
        _to = to;

        auto jpsFile = make_unique<JpsFile>();
        QMap<qulonglong, Epoch*> epochsByDateTime;
        GreisMysqlSerializer& serializer = _serializer;

        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `description` FROM `msg_FileId` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [&serializer] (const QSqlQuery& q, Message* msg) {
                auto c = dynamic_cast<FileIdStdMessage*>(msg);
                serializer.Deserialize(q.value(5), c->IdField());
        }, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `majorVer`, `minorVer`, `order`, `cs` FROM `msg_MsgFmt` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs` FROM `msg_RcvTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs` FROM `msg_EpochTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `year`, `month`, `day`, `base`, `cs` FROM `msg_RcvDate` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvTimeOffsetDot` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `acc`, `cs` FROM `msg_RcvTimeAccuracy` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tow`, `wn`, `cs` FROM `msg_GPSTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGPSTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `dn`, `cs` FROM `msg_GLOTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGLOTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGALTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvWAASTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `cs` FROM `msg_GpsUtcParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `utcsi`, `tow`, `wn`, `flags`, `cs` FROM `msg_WaasUtcParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `a0g`, `a1g`, `t0g`, `wn0g`, `flags`, `cs` FROM `msg_GalUtcGpsParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tauSys`, `tauGps`, `B1`, `B2`, `KP`, `N4`, `Dn`, `cs` FROM `msg_GloUtcGpsParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `solType`, `cs` FROM `msg_SolutionTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `cs` FROM `msg_Pos` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `cs` FROM `msg_Vel` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `pSigma`, `vx`, `vy`, `vz`, `vSigma`, `solType`, `cs` FROM `msg_PosVel` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `cs` FROM `msg_GeoPos` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `cs` FROM `msg_GeoVel` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hpos`, `vpos`, `hvel`, `vvel`, `solType`, `cs` FROM `msg_Rms` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hdop`, `vdop`, `tdop`, `solType`, `cs` FROM `msg_Dops` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs` FROM `msg_PosCov` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs` FROM `msg_VelCov` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `time`, `cs` FROM `msg_BaseLine` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `solType`, `gpsLocked`, `gloLocked`, `gpsAvail`, `gloAvail`, `gpsUsed`, `gloUsed`, `fixProg`, `cs` FROM `msg_PosStat` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pt`, `cs` FROM `msg_PosCompTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `usi`, `cs` FROM `msg_SatIndex` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `name`, `cs` FROM `msg_AntName` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `osn`, `cs` FROM `msg_SatNumbers` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `elev`, `cs` FROM `msg_SatElevation` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `azim`, `cs` FROM `msg_SatAzimuth` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pr`, `cs` FROM `msg_PR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `spr`, `cs` FROM `msg_SPR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rpr`, `cs` FROM `msg_RPR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srpr`, `cs` FROM `msg_SRPR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs` FROM `msg_SC` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs` FROM `msg_SS` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cp`, `cs` FROM `msg_CP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `scp`, `cs` FROM `msg_SCP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs` FROM `msg_RCP_RC0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs` FROM `msg_RCP_rc1` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `dp`, `cs` FROM `msg_DP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srdp`, `cs` FROM `msg_SRDP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnr`, `cs` FROM `msg_CNR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnrX4`, `cs` FROM `msg_CNR_4` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `flags`, `cs` FROM `msg_Flags` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs` FROM `msg_TrackingTimeCA` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ns`, `solType`, `cs` FROM `msg_NavStatus` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `delay`, `cs` FROM `msg_IonoDelay` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `healthS`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot`, `cs` FROM `msg_GPSAlm0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `iod`, `cs` FROM `msg_GALAlm` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dna`, `tlam`, `flags`, `tauN`, `tauSys`, `ecc`, `lambda`, `argPer`, `delT`, `delTdt`, `deli`, `cs` FROM `msg_GLOAlmanac` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `id_sugar`, `healthS`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `tow`, `wn`, `cs` FROM `msg_WAASAlmanac` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `tow`, `flags`, `iodc`, `toc`, `ura`, `healthS`, `wn`, `tgd`, `af2`, `af1`, `af0`, `toe`, `iode`, `rootA`, `ecc`, `m0`, `omega0`, `inc0`, `argPer`, `deln`, `omegaDot`, `incDot`, `crc`, `crs`, `cuc`, `cus`, `cic`, `cis`, `cs` FROM `msg_GPSEphemeris0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dne`, `tk`, `tb`, `health`, `age`, `flags`, `r`, `v`, `w`, `tauSys`, `tau`, `gamma`, `fDelTauN`, `nFt`, `nN4`, `flags2`, `cs` FROM `msg_GLOEphemeris` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `iod`, `acc`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `vvxg`, `vvyg`, `vvzg`, `agf0`, `agf1`, `tow`, `wn`, `cs` FROM `msg_WAASEhemeris` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `bgdE1E5a`, `bgdE1E5b`, `ai0`, `ai1`, `ai2`, `sfi`, `navType`, `cs` FROM `msg_GALEphemeris` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs` FROM `msg_GpsNavData` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs` FROM `msg_GloNavData` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `reserv`, `data`, `cs` FROM `msg_WAASRawMessage` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `cs` FROM `msg_GALRawMessage` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `fcn`, `phase`, `range`, `cs` FROM `msg_GloPhaseDelay` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `cs` FROM `msg_RotationMatrix` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `bl0`, `bl1`, `bl2`, `cs` FROM `msg_RotationMatrixAndVectors` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `pitch`, `roll`, `heading`, `pitchRms`, `rollRms`, `headingRms`, `flags`, `cs` FROM `msg_RotationAngles` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `x`, `y`, `z`, `rms`, `flags`, `cs` FROM `msg_AngularVelocity` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `accelerations`, `angularVelocities`, `cs` FROM `msg_InertialMeasurements` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ms`, `ns`, `timeScale`, `cs` FROM `msg_ExtEvent` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `cs` FROM `msg_PPSOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `timeScale`, `cs` FROM `msg_RcvTimeOffsAtPPS` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `crc16` FROM `msg_RefEpoch` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `clock`, `flags`, `svd`, `crc16` FROM `msg_RawMeas` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `delta`, `word1`, `word2`, `word3`, `word4`, `word5`, `word6`, `word7`, `word8`, `word9`, `crc16` FROM `msg_PosVelVector` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `reserved`, `recSize`, `Offs`, `crc16` FROM `msg_ClockOffsets` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `reply` FROM `msg_RE` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `error` FROM `msg_ER` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tot`, `wn`, `alpha0`, `alpha1`, `alpha2`, `alpha3`, `beta0`, `beta1`, `beta2`, `beta3`, `cs` FROM `msg_IonoParams` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `type`, `data`, `cs` FROM `msg_Event` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lt`, `cs` FROM `msg_Latency` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `data`, `cs` FROM `msg_Wrapper` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `params`, `delim`, `cs` FROM `msg_Params` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `svsCount`, `targetStream`, `issue`, `bitsCount`, `lastBitTime`, `uids`, `pad`, `hist` FROM `msg_LoggingHistory` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `id_sugar`, `solType`, `cs` FROM `msg_BaseInfo` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `cs` FROM `msg_Security0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `crc16` FROM `msg_Security1` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs` FROM `msg_TrackingTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `cs` FROM `msg_RcvOscOffs` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cs` FROM `msg_EpochEnd` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {}, epochsByDateTime);

        for (auto it = epochsByDateTime.begin(); it != epochsByDateTime.end(); ++it)
        {
            jpsFile->Body().push_back(Epoch::UniquePtr_t(it.value()));
        }
        return jpsFile;
    }
}
