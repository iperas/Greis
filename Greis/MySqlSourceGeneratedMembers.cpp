#include "MySqlSource.h"
#include <vector>
#include "ProjectBase\SmartPtr.h"
#include "ProjectBase\Connection.h"
#include "ECustomTypeId.h"
#include "JpsFile.h"
#include "AllStdMessages.h"
#include "AllCustomTypes.h"

using namespace ProjectBase;

namespace Greis
{
    void MySqlSource::constructCtQueriesAndHandlers()
    {
        GreisMysqlSerializer& serializer = _serializer;
        
        auto queryUtcOffsCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `a0`, `a1`, `tot`, `wnt`, `dtls`, `dn`, `wnlsf`, `dtlsf` FROM `ct_UtcOffs` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerUtcOffsCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new UtcOffsCustomType(size);
                auto c = dynamic_cast<UtcOffsCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->A0());
                serializer.Deserialize(q.value(5), c->A1());
                serializer.Deserialize(q.value(6), c->Tot());
                serializer.Deserialize(q.value(7), c->Wnt());
                serializer.Deserialize(q.value(8), c->Dtls());
                serializer.Deserialize(q.value(9), c->Dn());
                serializer.Deserialize(q.value(10), c->Wnlsf());
                serializer.Deserialize(q.value(11), c->Dtlsf());
            };
        
        auto querySmoothCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `value`, `interval` FROM `ct_Smooth` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerSmoothCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SmoothCustomType(size);
                auto c = dynamic_cast<SmoothCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Value());
                serializer.Deserialize(q.value(5), c->Interval());
            };
        
        auto querySvData0CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `prn`, `cnt`, `data` FROM `ct_SvData0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerSvData0CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SvData0CustomType(size);
                auto c = dynamic_cast<SvData0CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Prn());
                serializer.Deserialize(q.value(5), c->Cnt());
                serializer.Deserialize(q.value(6), c->Data());
            };
        
        auto querySvData1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `fcn1`, `cnt`, `data` FROM `ct_SvData1` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerSvData1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SvData1CustomType(size);
                auto c = dynamic_cast<SvData1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Fcn1());
                serializer.Deserialize(q.value(5), c->Cnt());
                serializer.Deserialize(q.value(6), c->Data());
            };
        
        auto querySvData2CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `header`, `slot` FROM `ct_SvData2` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerSvData2CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SvData2CustomType(size);
                auto c = dynamic_cast<SvData2CustomType*>(ct);
                
                throw ProjectBase::NotImplementedException();
            };
        
        auto queryHeaderCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `refrange`, `usi`, `num` FROM `ct_Header` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerHeaderCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new HeaderCustomType(size);
                auto c = dynamic_cast<HeaderCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Refrange());
                serializer.Deserialize(q.value(5), c->Usi());
                serializer.Deserialize(q.value(6), c->Num());
            };
        
        auto querySlotRecCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `svstOrDelrange`, `word1`, `flags`, `lock`, `word2` FROM `ct_SlotRec` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerSlotRecCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SlotRecCustomType(size);
                auto c = dynamic_cast<SlotRecCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->SvstOrDelrange());
                serializer.Deserialize(q.value(5), c->Word1());
                serializer.Deserialize(q.value(6), c->Flags());
                serializer.Deserialize(q.value(7), c->Lock());
                serializer.Deserialize(q.value(8), c->Word2());
            };
        
        auto queryClkOffsCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `word1`, `word2` FROM `ct_ClkOffs` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerClkOffsCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new ClkOffsCustomType(size);
                auto c = dynamic_cast<ClkOffsCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Word1());
                serializer.Deserialize(q.value(5), c->Word2());
            };
        
        auto queryGPSAlm1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `healthS`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot` FROM `ct_GPSAlm1` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerGPSAlm1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GPSAlm1CustomType(size);
                auto c = dynamic_cast<GPSAlm1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Sv());
                serializer.Deserialize(q.value(5), c->Wna());
                serializer.Deserialize(q.value(6), c->Toa());
                serializer.Deserialize(q.value(7), c->HealthA());
                serializer.Deserialize(q.value(8), c->HealthS());
                serializer.Deserialize(q.value(9), c->Config());
                serializer.Deserialize(q.value(10), c->Af1());
                serializer.Deserialize(q.value(11), c->Af0());
                serializer.Deserialize(q.value(12), c->RootA());
                serializer.Deserialize(q.value(13), c->Ecc());
                serializer.Deserialize(q.value(14), c->M0());
                serializer.Deserialize(q.value(15), c->Omega0());
                serializer.Deserialize(q.value(16), c->ArgPer());
                serializer.Deserialize(q.value(17), c->Deli());
                serializer.Deserialize(q.value(18), c->OmegaDot());
            };
        
        auto queryGPSEphemeris1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `tow`, `flags`, `iodc`, `toc`, `ura`, `healthS`, `wn`, `tgd`, `af2`, `af1`, `af0`, `toe`, `iode`, `rootA`, `ecc`, `m0`, `omega0`, `inc0`, `argPer`, `deln`, `omegaDot`, `incDot`, `crc`, `crs`, `cuc`, `cus`, `cic`, `cis` FROM `ct_GPSEphemeris1` WHERE `unixTimeEpoch` BETWEEN %1 AND %2");
        auto handlerGPSEphemeris1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GPSEphemeris1CustomType(size);
                auto c = dynamic_cast<GPSEphemeris1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Sv());
                serializer.Deserialize(q.value(5), c->Tow());
                serializer.Deserialize(q.value(6), c->Flags());
                serializer.Deserialize(q.value(7), c->Iodc());
                serializer.Deserialize(q.value(8), c->Toc());
                serializer.Deserialize(q.value(9), c->Ura());
                serializer.Deserialize(q.value(10), c->HealthS());
                serializer.Deserialize(q.value(11), c->Wn());
                serializer.Deserialize(q.value(12), c->Tgd());
                serializer.Deserialize(q.value(13), c->Af2());
                serializer.Deserialize(q.value(14), c->Af1());
                serializer.Deserialize(q.value(15), c->Af0());
                serializer.Deserialize(q.value(16), c->Toe());
                serializer.Deserialize(q.value(17), c->Iode());
                serializer.Deserialize(q.value(18), c->RootA());
                serializer.Deserialize(q.value(19), c->Ecc());
                serializer.Deserialize(q.value(20), c->M0());
                serializer.Deserialize(q.value(21), c->Omega0());
                serializer.Deserialize(q.value(22), c->Inc0());
                serializer.Deserialize(q.value(23), c->ArgPer());
                serializer.Deserialize(q.value(24), c->Deln());
                serializer.Deserialize(q.value(25), c->OmegaDot());
                serializer.Deserialize(q.value(26), c->IncDot());
                serializer.Deserialize(q.value(27), c->Crc());
                serializer.Deserialize(q.value(28), c->Crs());
                serializer.Deserialize(q.value(29), c->Cuc());
                serializer.Deserialize(q.value(30), c->Cus());
                serializer.Deserialize(q.value(31), c->Cic());
                serializer.Deserialize(q.value(32), c->Cis());
            };
        
        _ctQueries.insert(ECustomTypeId::UtcOffs, queryUtcOffsCustomType);
        _ctHandlers.insert(ECustomTypeId::UtcOffs, handlerUtcOffsCustomType);
        _ctQueries.insert(ECustomTypeId::Smooth, querySmoothCustomType);
        _ctHandlers.insert(ECustomTypeId::Smooth, handlerSmoothCustomType);
        _ctQueries.insert(ECustomTypeId::SvData0, querySvData0CustomType);
        _ctHandlers.insert(ECustomTypeId::SvData0, handlerSvData0CustomType);
        _ctQueries.insert(ECustomTypeId::SvData1, querySvData1CustomType);
        _ctHandlers.insert(ECustomTypeId::SvData1, handlerSvData1CustomType);
        _ctQueries.insert(ECustomTypeId::SvData2, querySvData2CustomType);
        _ctHandlers.insert(ECustomTypeId::SvData2, handlerSvData2CustomType);
        _ctQueries.insert(ECustomTypeId::Header, queryHeaderCustomType);
        _ctHandlers.insert(ECustomTypeId::Header, handlerHeaderCustomType);
        _ctQueries.insert(ECustomTypeId::SlotRec, querySlotRecCustomType);
        _ctHandlers.insert(ECustomTypeId::SlotRec, handlerSlotRecCustomType);
        _ctQueries.insert(ECustomTypeId::ClkOffs, queryClkOffsCustomType);
        _ctHandlers.insert(ECustomTypeId::ClkOffs, handlerClkOffsCustomType);
        _ctQueries.insert(ECustomTypeId::GPSAlm1, queryGPSAlm1CustomType);
        _ctHandlers.insert(ECustomTypeId::GPSAlm1, handlerGPSAlm1CustomType);
        _ctQueries.insert(ECustomTypeId::GPSEphemeris1, queryGPSEphemeris1CustomType);
        _ctHandlers.insert(ECustomTypeId::GPSEphemeris1, handlerGPSEphemeris1CustomType);
    }
    
    JpsFile::UniquePtr_t MySqlSource::ReadRange( const QDateTime& from, const QDateTime& to )
    {
        _ctBuffer.clear();

        _from = from;
        _to = to;

        auto jpsFile = make_unique<JpsFile>();
        fillStandardJpsHeader(jpsFile.get());
        
        QMap<qulonglong, Epoch*> epochsByDateTime;

        GreisMysqlSerializer& serializer = _serializer;
        
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `description` FROM `msg_FileId` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<FileIdStdMessage>(id, bodySize);
                auto c = dynamic_cast<FileIdStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->IdField());
                serializer.Deserialize(q.value(6), c->Description());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `majorVer`, `minorVer`, `order`, `cs` FROM `msg_MsgFmt` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<MsgFmtStdMessage>(id, bodySize);
                auto c = dynamic_cast<MsgFmtStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->IdField());
                serializer.Deserialize(q.value(6), c->MajorVer());
                serializer.Deserialize(q.value(7), c->MinorVer());
                serializer.DeserializeChar(q.value(8), c->Order());
                serializer.Deserialize(q.value(9), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs` FROM `msg_RcvTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvTimeStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvTimeStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Tod());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs` FROM `msg_EpochTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<EpochTimeStdMessage>(id, bodySize);
                auto c = dynamic_cast<EpochTimeStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Tod());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `year`, `month`, `day`, `base`, `cs` FROM `msg_RcvDate` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvDateStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvDateStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Year());
                serializer.Deserialize(q.value(6), c->Month());
                serializer.Deserialize(q.value(7), c->Day());
                serializer.Deserialize(q.value(8), c->Base());
                serializer.Deserialize(q.value(9), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvTimeOffsetStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvTimeOffsetStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Val());
                serializer.Deserialize(q.value(6), c->Sval());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvTimeOffsetDot` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvTimeOffsetDotStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvTimeOffsetDotStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Val());
                serializer.Deserialize(q.value(6), c->Sval());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `acc`, `cs` FROM `msg_RcvTimeAccuracy` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvTimeAccuracyStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvTimeAccuracyStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Acc());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tow`, `wn`, `cs` FROM `msg_GPSTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GPSTimeStdMessage>(id, bodySize);
                auto c = dynamic_cast<GPSTimeStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Tow());
                serializer.Deserialize(q.value(6), c->Wn());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGPSTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvGPSTimeOffsetStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvGPSTimeOffsetStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Val());
                serializer.Deserialize(q.value(6), c->Sval());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `dn`, `cs` FROM `msg_GLOTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GLOTimeStdMessage>(id, bodySize);
                auto c = dynamic_cast<GLOTimeStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Tod());
                serializer.Deserialize(q.value(6), c->Dn());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGLOTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvGLOTimeOffsetStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvGLOTimeOffsetStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Val());
                serializer.Deserialize(q.value(6), c->Sval());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGALTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvGALTimeOffsetStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvGALTimeOffsetStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Val());
                serializer.Deserialize(q.value(6), c->Sval());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvWAASTimeOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvWAASTimeOffsetStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvWAASTimeOffsetStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Val());
                serializer.Deserialize(q.value(6), c->Sval());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `cs` FROM `msg_GpsUtcParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GpsUtcParamStdMessage>(id, bodySize);
                auto c = dynamic_cast<GpsUtcParamStdMessage*>(msg.get());
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(5).toInt());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `utcsi`, `tow`, `wn`, `flags`, `cs` FROM `msg_WaasUtcParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<WaasUtcParamStdMessage>(id, bodySize);
                auto c = dynamic_cast<WaasUtcParamStdMessage*>(msg.get());
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(5).toInt());
                serializer.Deserialize(q.value(6), c->Utcsi());
                serializer.Deserialize(q.value(7), c->Tow());
                serializer.Deserialize(q.value(8), c->Wn());
                serializer.Deserialize(q.value(9), c->Flags());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `a0g`, `a1g`, `t0g`, `wn0g`, `flags`, `cs` FROM `msg_GalUtcGpsParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GalUtcGpsParamStdMessage>(id, bodySize);
                auto c = dynamic_cast<GalUtcGpsParamStdMessage*>(msg.get());
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(5).toInt());
                serializer.Deserialize(q.value(6), c->A0g());
                serializer.Deserialize(q.value(7), c->A1g());
                serializer.Deserialize(q.value(8), c->T0g());
                serializer.Deserialize(q.value(9), c->Wn0g());
                serializer.Deserialize(q.value(10), c->Flags());
                serializer.Deserialize(q.value(11), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tauSys`, `tauGps`, `B1`, `B2`, `KP`, `N4`, `Dn`, `cs` FROM `msg_GloUtcGpsParam` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GloUtcGpsParamStdMessage>(id, bodySize);
                auto c = dynamic_cast<GloUtcGpsParamStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->TauSys());
                serializer.Deserialize(q.value(6), c->TauGps());
                serializer.Deserialize(q.value(7), c->B1());
                serializer.Deserialize(q.value(8), c->B2());
                serializer.Deserialize(q.value(9), c->KP());
                serializer.Deserialize(q.value(10), c->N4());
                serializer.Deserialize(q.value(11), c->Dn());
                serializer.Deserialize(q.value(12), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `solType`, `cs` FROM `msg_SolutionTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SolutionTimeStdMessage>(id, bodySize);
                auto c = dynamic_cast<SolutionTimeStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Time());
                serializer.Deserialize(q.value(6), c->SolType());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `cs` FROM `msg_Pos` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PosStdMessage>(id, bodySize);
                auto c = dynamic_cast<PosStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->X());
                serializer.Deserialize(q.value(6), c->Y());
                serializer.Deserialize(q.value(7), c->Z());
                serializer.Deserialize(q.value(8), c->Sigma());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `cs` FROM `msg_Vel` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<VelStdMessage>(id, bodySize);
                auto c = dynamic_cast<VelStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->X());
                serializer.Deserialize(q.value(6), c->Y());
                serializer.Deserialize(q.value(7), c->Z());
                serializer.Deserialize(q.value(8), c->Sigma());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `pSigma`, `vx`, `vy`, `vz`, `vSigma`, `solType`, `cs` FROM `msg_PosVel` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PosVelStdMessage>(id, bodySize);
                auto c = dynamic_cast<PosVelStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->X());
                serializer.Deserialize(q.value(6), c->Y());
                serializer.Deserialize(q.value(7), c->Z());
                serializer.Deserialize(q.value(8), c->PSigma());
                serializer.Deserialize(q.value(9), c->Vx());
                serializer.Deserialize(q.value(10), c->Vy());
                serializer.Deserialize(q.value(11), c->Vz());
                serializer.Deserialize(q.value(12), c->VSigma());
                serializer.Deserialize(q.value(13), c->SolType());
                serializer.Deserialize(q.value(14), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `cs` FROM `msg_GeoPos` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GeoPosStdMessage>(id, bodySize);
                auto c = dynamic_cast<GeoPosStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Lat());
                serializer.Deserialize(q.value(6), c->Lon());
                serializer.Deserialize(q.value(7), c->Alt());
                serializer.Deserialize(q.value(8), c->PSigma());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `cs` FROM `msg_GeoVel` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GeoVelStdMessage>(id, bodySize);
                auto c = dynamic_cast<GeoVelStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Lat());
                serializer.Deserialize(q.value(6), c->Lon());
                serializer.Deserialize(q.value(7), c->Alt());
                serializer.Deserialize(q.value(8), c->PSigma());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hpos`, `vpos`, `hvel`, `vvel`, `solType`, `cs` FROM `msg_Rms` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RmsStdMessage>(id, bodySize);
                auto c = dynamic_cast<RmsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Hpos());
                serializer.Deserialize(q.value(6), c->Vpos());
                serializer.Deserialize(q.value(7), c->Hvel());
                serializer.Deserialize(q.value(8), c->Vvel());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hdop`, `vdop`, `tdop`, `solType`, `cs` FROM `msg_Dops` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<DopsStdMessage>(id, bodySize);
                auto c = dynamic_cast<DopsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Hdop());
                serializer.Deserialize(q.value(6), c->Vdop());
                serializer.Deserialize(q.value(7), c->Tdop());
                serializer.Deserialize(q.value(8), c->SolType());
                serializer.Deserialize(q.value(9), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs` FROM `msg_PosCov` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PosCovStdMessage>(id, bodySize);
                auto c = dynamic_cast<PosCovStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Xx());
                serializer.Deserialize(q.value(6), c->Yy());
                serializer.Deserialize(q.value(7), c->Zz());
                serializer.Deserialize(q.value(8), c->Tt());
                serializer.Deserialize(q.value(9), c->Xy());
                serializer.Deserialize(q.value(10), c->Xz());
                serializer.Deserialize(q.value(11), c->Xt());
                serializer.Deserialize(q.value(12), c->Yz());
                serializer.Deserialize(q.value(13), c->Yt());
                serializer.Deserialize(q.value(14), c->Zt());
                serializer.Deserialize(q.value(15), c->SolType());
                serializer.Deserialize(q.value(16), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs` FROM `msg_VelCov` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<VelCovStdMessage>(id, bodySize);
                auto c = dynamic_cast<VelCovStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Xx());
                serializer.Deserialize(q.value(6), c->Yy());
                serializer.Deserialize(q.value(7), c->Zz());
                serializer.Deserialize(q.value(8), c->Tt());
                serializer.Deserialize(q.value(9), c->Xy());
                serializer.Deserialize(q.value(10), c->Xz());
                serializer.Deserialize(q.value(11), c->Xt());
                serializer.Deserialize(q.value(12), c->Yz());
                serializer.Deserialize(q.value(13), c->Yt());
                serializer.Deserialize(q.value(14), c->Zt());
                serializer.Deserialize(q.value(15), c->SolType());
                serializer.Deserialize(q.value(16), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `time`, `cs` FROM `msg_BaseLine` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<BaseLineStdMessage>(id, bodySize);
                auto c = dynamic_cast<BaseLineStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->X());
                serializer.Deserialize(q.value(6), c->Y());
                serializer.Deserialize(q.value(7), c->Z());
                serializer.Deserialize(q.value(8), c->Sigma());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Time());
                serializer.Deserialize(q.value(11), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `solType`, `gpsLocked`, `gloLocked`, `gpsAvail`, `gloAvail`, `gpsUsed`, `gloUsed`, `fixProg`, `cs` FROM `msg_PosStat` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PosStatStdMessage>(id, bodySize);
                auto c = dynamic_cast<PosStatStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->SolType());
                serializer.Deserialize(q.value(6), c->GpsLocked());
                serializer.Deserialize(q.value(7), c->GloLocked());
                serializer.Deserialize(q.value(8), c->GpsAvail());
                serializer.Deserialize(q.value(9), c->GloAvail());
                serializer.Deserialize(q.value(10), c->GpsUsed());
                serializer.Deserialize(q.value(11), c->GloUsed());
                serializer.Deserialize(q.value(12), c->FixProg());
                serializer.Deserialize(q.value(13), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pt`, `cs` FROM `msg_PosCompTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PosCompTimeStdMessage>(id, bodySize);
                auto c = dynamic_cast<PosCompTimeStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Pt());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `usi`, `cs` FROM `msg_SatIndex` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SatIndexStdMessage>(id, bodySize);
                auto c = dynamic_cast<SatIndexStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Usi());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `name`, `cs` FROM `msg_AntName` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<AntNameStdMessage>(id, bodySize);
                auto c = dynamic_cast<AntNameStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Name());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `osn`, `cs` FROM `msg_SatNumbers` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SatNumbersStdMessage>(id, bodySize);
                auto c = dynamic_cast<SatNumbersStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Osn());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `elev`, `cs` FROM `msg_SatElevation` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SatElevationStdMessage>(id, bodySize);
                auto c = dynamic_cast<SatElevationStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Elev());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `azim`, `cs` FROM `msg_SatAzimuth` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SatAzimuthStdMessage>(id, bodySize);
                auto c = dynamic_cast<SatAzimuthStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Azim());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pr`, `cs` FROM `msg_PR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PRStdMessage>(id, bodySize);
                auto c = dynamic_cast<PRStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Pr());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `spr`, `cs` FROM `msg_SPR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SPRStdMessage>(id, bodySize);
                auto c = dynamic_cast<SPRStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Spr());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rpr`, `cs` FROM `msg_RPR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RPRStdMessage>(id, bodySize);
                auto c = dynamic_cast<RPRStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Rpr());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srpr`, `cs` FROM `msg_SRPR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SRPRStdMessage>(id, bodySize);
                auto c = dynamic_cast<SRPRStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Srpr());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs` FROM `msg_SC` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SCStdMessage>(id, bodySize);
                auto c = dynamic_cast<SCStdMessage*>(msg.get());
                c->Smooth() = this->deserializeAndGetCustomTypes<SmoothCustomType>(ECustomTypeId::Smooth, q.value(5));
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs` FROM `msg_SS` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SSStdMessage>(id, bodySize);
                auto c = dynamic_cast<SSStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Smooth());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cp`, `cs` FROM `msg_CP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<CPStdMessage>(id, bodySize);
                auto c = dynamic_cast<CPStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Cp());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `scp`, `cs` FROM `msg_SCP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SCPStdMessage>(id, bodySize);
                auto c = dynamic_cast<SCPStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Scp());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs` FROM `msg_RCP_RC0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RCPRC0StdMessage>(id, bodySize);
                auto c = dynamic_cast<RCPRC0StdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Rcp());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs` FROM `msg_RCP_rc1` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RCPRc1StdMessage>(id, bodySize);
                auto c = dynamic_cast<RCPRc1StdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Rcp());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `dp`, `cs` FROM `msg_DP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<DPStdMessage>(id, bodySize);
                auto c = dynamic_cast<DPStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Dp());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srdp`, `cs` FROM `msg_SRDP` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<SRDPStdMessage>(id, bodySize);
                auto c = dynamic_cast<SRDPStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Srdp());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnr`, `cs` FROM `msg_CNR` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<CNRStdMessage>(id, bodySize);
                auto c = dynamic_cast<CNRStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Cnr());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnrX4`, `cs` FROM `msg_CNR_4` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<CNR4StdMessage>(id, bodySize);
                auto c = dynamic_cast<CNR4StdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->CnrX4());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `flags`, `cs` FROM `msg_Flags` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<FlagsStdMessage>(id, bodySize);
                auto c = dynamic_cast<FlagsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Flags());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs` FROM `msg_TrackingTimeCA` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<TrackingTimeCAStdMessage>(id, bodySize);
                auto c = dynamic_cast<TrackingTimeCAStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Tt());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ns`, `solType`, `cs` FROM `msg_NavStatus` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<NavStatusStdMessage>(id, bodySize);
                auto c = dynamic_cast<NavStatusStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Ns());
                serializer.Deserialize(q.value(6), c->SolType());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `delay`, `cs` FROM `msg_IonoDelay` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<IonoDelayStdMessage>(id, bodySize);
                auto c = dynamic_cast<IonoDelayStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Delay());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `healthS`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot`, `cs` FROM `msg_GPSAlm0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GPSAlm0StdMessage>(id, bodySize);
                auto c = dynamic_cast<GPSAlm0StdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Sv());
                serializer.Deserialize(q.value(6), c->Wna());
                serializer.Deserialize(q.value(7), c->Toa());
                serializer.Deserialize(q.value(8), c->HealthA());
                serializer.Deserialize(q.value(9), c->HealthS());
                serializer.Deserialize(q.value(10), c->Config());
                serializer.Deserialize(q.value(11), c->Af1());
                serializer.Deserialize(q.value(12), c->Af0());
                serializer.Deserialize(q.value(13), c->RootA());
                serializer.Deserialize(q.value(14), c->Ecc());
                serializer.Deserialize(q.value(15), c->M0());
                serializer.Deserialize(q.value(16), c->Omega0());
                serializer.Deserialize(q.value(17), c->ArgPer());
                serializer.Deserialize(q.value(18), c->Deli());
                serializer.Deserialize(q.value(19), c->OmegaDot());
                serializer.Deserialize(q.value(20), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `iod`, `cs` FROM `msg_GALAlm` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GALAlmStdMessage>(id, bodySize);
                auto c = dynamic_cast<GALAlmStdMessage*>(msg.get());
                c->Gps() = this->extractCustomType<GPSAlm1CustomType>(ECustomTypeId::GPSAlm1, q.value(5).toInt());
                serializer.Deserialize(q.value(6), c->Iod());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dna`, `tlam`, `flags`, `tauN`, `tauSys`, `ecc`, `lambda`, `argPer`, `delT`, `delTdt`, `deli`, `cs` FROM `msg_GLOAlmanac` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GLOAlmanacStdMessage>(id, bodySize);
                auto c = dynamic_cast<GLOAlmanacStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Sv());
                serializer.Deserialize(q.value(6), c->FrqNum());
                serializer.Deserialize(q.value(7), c->Dna());
                serializer.Deserialize(q.value(8), c->Tlam());
                serializer.Deserialize(q.value(9), c->Flags());
                serializer.Deserialize(q.value(10), c->TauN());
                serializer.Deserialize(q.value(11), c->TauSys());
                serializer.Deserialize(q.value(12), c->Ecc());
                serializer.Deserialize(q.value(13), c->Lambda());
                serializer.Deserialize(q.value(14), c->ArgPer());
                serializer.Deserialize(q.value(15), c->DelT());
                serializer.Deserialize(q.value(16), c->DelTdt());
                serializer.Deserialize(q.value(17), c->Deli());
                serializer.Deserialize(q.value(18), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `id_sugar`, `healthS`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `tow`, `wn`, `cs` FROM `msg_WAASAlmanac` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<WAASAlmanacStdMessage>(id, bodySize);
                auto c = dynamic_cast<WAASAlmanacStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->WaasPrn());
                serializer.Deserialize(q.value(6), c->GpsPrn());
                serializer.Deserialize(q.value(7), c->IdField());
                serializer.Deserialize(q.value(8), c->HealthS());
                serializer.Deserialize(q.value(9), c->Tod());
                serializer.Deserialize(q.value(10), c->Xg());
                serializer.Deserialize(q.value(11), c->Yg());
                serializer.Deserialize(q.value(12), c->Zg());
                serializer.Deserialize(q.value(13), c->Vxg());
                serializer.Deserialize(q.value(14), c->Vyg());
                serializer.Deserialize(q.value(15), c->Vzg());
                serializer.Deserialize(q.value(16), c->Tow());
                serializer.Deserialize(q.value(17), c->Wn());
                serializer.Deserialize(q.value(18), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `tow`, `flags`, `iodc`, `toc`, `ura`, `healthS`, `wn`, `tgd`, `af2`, `af1`, `af0`, `toe`, `iode`, `rootA`, `ecc`, `m0`, `omega0`, `inc0`, `argPer`, `deln`, `omegaDot`, `incDot`, `crc`, `crs`, `cuc`, `cus`, `cic`, `cis`, `cs` FROM `msg_GPSEphemeris0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GPSEphemeris0StdMessage>(id, bodySize);
                auto c = dynamic_cast<GPSEphemeris0StdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Sv());
                serializer.Deserialize(q.value(6), c->Tow());
                serializer.Deserialize(q.value(7), c->Flags());
                serializer.Deserialize(q.value(8), c->Iodc());
                serializer.Deserialize(q.value(9), c->Toc());
                serializer.Deserialize(q.value(10), c->Ura());
                serializer.Deserialize(q.value(11), c->HealthS());
                serializer.Deserialize(q.value(12), c->Wn());
                serializer.Deserialize(q.value(13), c->Tgd());
                serializer.Deserialize(q.value(14), c->Af2());
                serializer.Deserialize(q.value(15), c->Af1());
                serializer.Deserialize(q.value(16), c->Af0());
                serializer.Deserialize(q.value(17), c->Toe());
                serializer.Deserialize(q.value(18), c->Iode());
                serializer.Deserialize(q.value(19), c->RootA());
                serializer.Deserialize(q.value(20), c->Ecc());
                serializer.Deserialize(q.value(21), c->M0());
                serializer.Deserialize(q.value(22), c->Omega0());
                serializer.Deserialize(q.value(23), c->Inc0());
                serializer.Deserialize(q.value(24), c->ArgPer());
                serializer.Deserialize(q.value(25), c->Deln());
                serializer.Deserialize(q.value(26), c->OmegaDot());
                serializer.Deserialize(q.value(27), c->IncDot());
                serializer.Deserialize(q.value(28), c->Crc());
                serializer.Deserialize(q.value(29), c->Crs());
                serializer.Deserialize(q.value(30), c->Cuc());
                serializer.Deserialize(q.value(31), c->Cus());
                serializer.Deserialize(q.value(32), c->Cic());
                serializer.Deserialize(q.value(33), c->Cis());
                serializer.Deserialize(q.value(34), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dne`, `tk`, `tb`, `health`, `age`, `flags`, `r`, `v`, `w`, `tauSys`, `tau`, `gamma`, `fDelTauN`, `nFt`, `nN4`, `flags2`, `cs` FROM `msg_GLOEphemeris` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GLOEphemerisStdMessage>(id, bodySize);
                auto c = dynamic_cast<GLOEphemerisStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Sv());
                serializer.Deserialize(q.value(6), c->FrqNum());
                serializer.Deserialize(q.value(7), c->Dne());
                serializer.Deserialize(q.value(8), c->Tk());
                serializer.Deserialize(q.value(9), c->Tb());
                serializer.Deserialize(q.value(10), c->Health());
                serializer.Deserialize(q.value(11), c->Age());
                serializer.Deserialize(q.value(12), c->Flags());
                serializer.Deserialize(q.value(13), c->R());
                serializer.Deserialize(q.value(14), c->V());
                serializer.Deserialize(q.value(15), c->W());
                serializer.Deserialize(q.value(16), c->TauSys());
                serializer.Deserialize(q.value(17), c->Tau());
                serializer.Deserialize(q.value(18), c->Gamma());
                serializer.Deserialize(q.value(19), c->FDelTauN());
                serializer.Deserialize(q.value(20), c->NFt());
                serializer.Deserialize(q.value(21), c->NN4());
                serializer.Deserialize(q.value(22), c->Flags2());
                serializer.Deserialize(q.value(23), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `iod`, `acc`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `vvxg`, `vvyg`, `vvzg`, `agf0`, `agf1`, `tow`, `wn`, `cs` FROM `msg_WAASEhemeris` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<WAASEhemerisStdMessage>(id, bodySize);
                auto c = dynamic_cast<WAASEhemerisStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->WaasPrn());
                serializer.Deserialize(q.value(6), c->GpsPrn());
                serializer.Deserialize(q.value(7), c->Iod());
                serializer.Deserialize(q.value(8), c->Acc());
                serializer.Deserialize(q.value(9), c->Tod());
                serializer.Deserialize(q.value(10), c->Xg());
                serializer.Deserialize(q.value(11), c->Yg());
                serializer.Deserialize(q.value(12), c->Zg());
                serializer.Deserialize(q.value(13), c->Vxg());
                serializer.Deserialize(q.value(14), c->Vyg());
                serializer.Deserialize(q.value(15), c->Vzg());
                serializer.Deserialize(q.value(16), c->Vvxg());
                serializer.Deserialize(q.value(17), c->Vvyg());
                serializer.Deserialize(q.value(18), c->Vvzg());
                serializer.Deserialize(q.value(19), c->Agf0());
                serializer.Deserialize(q.value(20), c->Agf1());
                serializer.Deserialize(q.value(21), c->Tow());
                serializer.Deserialize(q.value(22), c->Wn());
                serializer.Deserialize(q.value(23), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `bgdE1E5a`, `bgdE1E5b`, `ai0`, `ai1`, `ai2`, `sfi`, `navType`, `cs` FROM `msg_GALEphemeris` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GALEphemerisStdMessage>(id, bodySize);
                auto c = dynamic_cast<GALEphemerisStdMessage*>(msg.get());
                c->Gps() = this->extractCustomType<GPSEphemeris1CustomType>(ECustomTypeId::GPSEphemeris1, q.value(5).toInt());
                serializer.Deserialize(q.value(6), c->BgdE1E5a());
                serializer.Deserialize(q.value(7), c->BgdE1E5b());
                serializer.Deserialize(q.value(8), c->Ai0());
                serializer.Deserialize(q.value(9), c->Ai1());
                serializer.Deserialize(q.value(10), c->Ai2());
                serializer.Deserialize(q.value(11), c->Sfi());
                serializer.Deserialize(q.value(12), c->NavType());
                serializer.Deserialize(q.value(13), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs` FROM `msg_GpsNavData` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GpsNavDataStdMessage>(id, bodySize);
                auto c = dynamic_cast<GpsNavDataStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->RecSize());
                c->Dat() = this->deserializeAndGetCustomTypes<SvData0CustomType>(ECustomTypeId::SvData0, q.value(6));
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs` FROM `msg_GloNavData` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GloNavDataStdMessage>(id, bodySize);
                auto c = dynamic_cast<GloNavDataStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->RecSize());
                c->Dat() = this->deserializeAndGetCustomTypes<SvData1CustomType>(ECustomTypeId::SvData1, q.value(6));
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `reserv`, `data`, `cs` FROM `msg_WAASRawMessage` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<WAASRawMessageStdMessage>(id, bodySize);
                auto c = dynamic_cast<WAASRawMessageStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Prn());
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->Reserv());
                serializer.Deserialize(q.value(8), c->Data());
                serializer.Deserialize(q.value(9), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `cs` FROM `msg_GALRawMessage` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GALRawMessageStdMessage>(id, bodySize);
                auto c = dynamic_cast<GALRawMessageStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Prn());
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->Type());
                serializer.Deserialize(q.value(8), c->Len());
                serializer.Deserialize(q.value(9), c->Data());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `fcn`, `phase`, `range`, `cs` FROM `msg_GloPhaseDelay` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<GloPhaseDelayStdMessage>(id, bodySize);
                auto c = dynamic_cast<GloPhaseDelayStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Fcn());
                serializer.Deserialize(q.value(6), c->Phase());
                serializer.Deserialize(q.value(7), c->Range());
                serializer.Deserialize(q.value(8), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `cs` FROM `msg_RotationMatrix` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RotationMatrixStdMessage>(id, bodySize);
                auto c = dynamic_cast<RotationMatrixStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Time());
                serializer.Deserialize(q.value(6), c->Q00());
                serializer.Deserialize(q.value(7), c->Q01());
                serializer.Deserialize(q.value(8), c->Q02());
                serializer.Deserialize(q.value(9), c->Q12());
                serializer.Deserialize(q.value(10), c->Rms());
                serializer.Deserialize(q.value(11), c->SolType());
                serializer.Deserialize(q.value(12), c->Flag());
                serializer.Deserialize(q.value(13), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `bl0`, `bl1`, `bl2`, `cs` FROM `msg_RotationMatrixAndVectors` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RotationMatrixAndVectorsStdMessage>(id, bodySize);
                auto c = dynamic_cast<RotationMatrixAndVectorsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Time());
                serializer.Deserialize(q.value(6), c->Q00());
                serializer.Deserialize(q.value(7), c->Q01());
                serializer.Deserialize(q.value(8), c->Q02());
                serializer.Deserialize(q.value(9), c->Q12());
                serializer.Deserialize(q.value(10), c->Rms());
                serializer.Deserialize(q.value(11), c->SolType());
                serializer.Deserialize(q.value(12), c->Flag());
                serializer.Deserialize(q.value(13), c->Bl0());
                serializer.Deserialize(q.value(14), c->Bl1());
                serializer.Deserialize(q.value(15), c->Bl2());
                serializer.Deserialize(q.value(16), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `pitch`, `roll`, `heading`, `pitchRms`, `rollRms`, `headingRms`, `flags`, `cs` FROM `msg_RotationAngles` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RotationAnglesStdMessage>(id, bodySize);
                auto c = dynamic_cast<RotationAnglesStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Time());
                serializer.Deserialize(q.value(6), c->Pitch());
                serializer.Deserialize(q.value(7), c->Roll());
                serializer.Deserialize(q.value(8), c->Heading());
                serializer.Deserialize(q.value(9), c->PitchRms());
                serializer.Deserialize(q.value(10), c->RollRms());
                serializer.Deserialize(q.value(11), c->HeadingRms());
                serializer.Deserialize(q.value(12), c->Flags());
                serializer.Deserialize(q.value(13), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `x`, `y`, `z`, `rms`, `flags`, `cs` FROM `msg_AngularVelocity` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<AngularVelocityStdMessage>(id, bodySize);
                auto c = dynamic_cast<AngularVelocityStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Time());
                serializer.Deserialize(q.value(6), c->X());
                serializer.Deserialize(q.value(7), c->Y());
                serializer.Deserialize(q.value(8), c->Z());
                serializer.Deserialize(q.value(9), c->Rms());
                serializer.Deserialize(q.value(10), c->Flags());
                serializer.Deserialize(q.value(11), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `accelerations`, `angularVelocities`, `cs` FROM `msg_InertialMeasurements` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<InertialMeasurementsStdMessage>(id, bodySize);
                auto c = dynamic_cast<InertialMeasurementsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Accelerations());
                serializer.Deserialize(q.value(6), c->AngularVelocities());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ms`, `ns`, `timeScale`, `cs` FROM `msg_ExtEvent` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<ExtEventStdMessage>(id, bodySize);
                auto c = dynamic_cast<ExtEventStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Ms());
                serializer.Deserialize(q.value(6), c->Ns());
                serializer.Deserialize(q.value(7), c->TimeScale());
                serializer.Deserialize(q.value(8), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `cs` FROM `msg_PPSOffset` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PPSOffsetStdMessage>(id, bodySize);
                auto c = dynamic_cast<PPSOffsetStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Offs());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `timeScale`, `cs` FROM `msg_RcvTimeOffsAtPPS` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvTimeOffsAtPPSStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvTimeOffsAtPPSStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Offs());
                serializer.Deserialize(q.value(6), c->TimeScale());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `crc16` FROM `msg_RefEpoch` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RefEpochStdMessage>(id, bodySize);
                auto c = dynamic_cast<RefEpochStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Sample());
                serializer.Deserialize(q.value(6), c->Scale());
                serializer.Deserialize(q.value(7), c->Reftime());
                serializer.Deserialize(q.value(8), c->Crc16());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `clock`, `flags`, `svd`, `crc16` FROM `msg_RawMeas` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RawMeasStdMessage>(id, bodySize);
                auto c = dynamic_cast<RawMeasStdMessage*>(msg.get());
                
                throw ProjectBase::NotImplementedException();
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `delta`, `word1`, `word2`, `word3`, `word4`, `word5`, `word6`, `word7`, `word8`, `word9`, `crc16` FROM `msg_PosVelVector` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<PosVelVectorStdMessage>(id, bodySize);
                auto c = dynamic_cast<PosVelVectorStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Sample());
                serializer.Deserialize(q.value(6), c->Delta());
                serializer.Deserialize(q.value(7), c->Word1());
                serializer.Deserialize(q.value(8), c->Word2());
                serializer.Deserialize(q.value(9), c->Word3());
                serializer.Deserialize(q.value(10), c->Word4());
                serializer.Deserialize(q.value(11), c->Word5());
                serializer.Deserialize(q.value(12), c->Word6());
                serializer.Deserialize(q.value(13), c->Word7());
                serializer.Deserialize(q.value(14), c->Word8());
                serializer.Deserialize(q.value(15), c->Word9());
                serializer.Deserialize(q.value(16), c->Crc16());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `reserved`, `recSize`, `Offs`, `crc16` FROM `msg_ClockOffsets` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<ClockOffsetsStdMessage>(id, bodySize);
                auto c = dynamic_cast<ClockOffsetsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Sample());
                serializer.Deserialize(q.value(6), c->Reserved());
                serializer.Deserialize(q.value(7), c->RecSize());
                c->Offs() = this->deserializeAndGetCustomTypes<ClkOffsCustomType>(ECustomTypeId::ClkOffs, q.value(8));
                serializer.Deserialize(q.value(9), c->Crc16());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `reply` FROM `msg_RE` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<REStdMessage>(id, bodySize);
                auto c = dynamic_cast<REStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Reply());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `error` FROM `msg_ER` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<ERStdMessage>(id, bodySize);
                auto c = dynamic_cast<ERStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Error());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tot`, `wn`, `alpha0`, `alpha1`, `alpha2`, `alpha3`, `beta0`, `beta1`, `beta2`, `beta3`, `cs` FROM `msg_IonoParams` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<IonoParamsStdMessage>(id, bodySize);
                auto c = dynamic_cast<IonoParamsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Tot());
                serializer.Deserialize(q.value(6), c->Wn());
                serializer.Deserialize(q.value(7), c->Alpha0());
                serializer.Deserialize(q.value(8), c->Alpha1());
                serializer.Deserialize(q.value(9), c->Alpha2());
                serializer.Deserialize(q.value(10), c->Alpha3());
                serializer.Deserialize(q.value(11), c->Beta0());
                serializer.Deserialize(q.value(12), c->Beta1());
                serializer.Deserialize(q.value(13), c->Beta2());
                serializer.Deserialize(q.value(14), c->Beta3());
                serializer.Deserialize(q.value(15), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `type`, `data`, `cs` FROM `msg_Event` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<EventStdMessage>(id, bodySize);
                auto c = dynamic_cast<EventStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Time());
                serializer.Deserialize(q.value(6), c->Type());
                serializer.Deserialize(q.value(7), c->Data());
                serializer.Deserialize(q.value(8), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lt`, `cs` FROM `msg_Latency` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<LatencyStdMessage>(id, bodySize);
                auto c = dynamic_cast<LatencyStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Lt());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `data`, `cs` FROM `msg_Wrapper` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<WrapperStdMessage>(id, bodySize);
                auto c = dynamic_cast<WrapperStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->IdField());
                serializer.Deserialize(q.value(6), c->Data());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `params`, `delim`, `cs` FROM `msg_Params` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<ParamsStdMessage>(id, bodySize);
                auto c = dynamic_cast<ParamsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Params());
                serializer.Deserialize(q.value(6), c->Delim());
                serializer.Deserialize(q.value(7), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `svsCount`, `targetStream`, `issue`, `bitsCount`, `lastBitTime`, `uids`, `pad`, `hist` FROM `msg_LoggingHistory` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<LoggingHistoryStdMessage>(id, bodySize);
                auto c = dynamic_cast<LoggingHistoryStdMessage*>(msg.get());
                
                throw ProjectBase::NotImplementedException();
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `id_sugar`, `solType`, `cs` FROM `msg_BaseInfo` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<BaseInfoStdMessage>(id, bodySize);
                auto c = dynamic_cast<BaseInfoStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->X());
                serializer.Deserialize(q.value(6), c->Y());
                serializer.Deserialize(q.value(7), c->Z());
                serializer.Deserialize(q.value(8), c->IdField());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `cs` FROM `msg_Security0` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<Security0StdMessage>(id, bodySize);
                auto c = dynamic_cast<Security0StdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Data());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `crc16` FROM `msg_Security1` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<Security1StdMessage>(id, bodySize);
                auto c = dynamic_cast<Security1StdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Data());
                serializer.Deserialize(q.value(6), c->Crc16());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs` FROM `msg_TrackingTime` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<TrackingTimeStdMessage>(id, bodySize);
                auto c = dynamic_cast<TrackingTimeStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Tt());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `cs` FROM `msg_RcvOscOffs` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<RcvOscOffsStdMessage>(id, bodySize);
                auto c = dynamic_cast<RcvOscOffsStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Val());
                serializer.Deserialize(q.value(6), c->Cs());
            }, 
            epochsByDateTime);
        handleMessage(QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cs` FROM `msg_EpochEnd` WHERE `unixTimeEpoch` BETWEEN %1 AND %2")
            .arg(_from.toMSecsSinceEpoch())
            .arg(_to.toMSecsSinceEpoch()), 
            [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q, Message::UniquePtr_t& msg)
            {
                msg = make_unique<EpochEndStdMessage>(id, bodySize);
                auto c = dynamic_cast<EpochEndStdMessage*>(msg.get());
                serializer.Deserialize(q.value(5), c->Cs());
            }, 
            epochsByDateTime);

        for (auto it = epochsByDateTime.begin(); it != epochsByDateTime.end(); ++it)
        {
            jpsFile->Body().push_back(Epoch::UniquePtr_t(it.value()));
        }
        return jpsFile;
    }
}
