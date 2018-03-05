#include <vector>
#include "Common/SmartPtr.h"
#include "Common/Connection.h"
#include "Greis/MySqlSource.h"
#include "Greis/ECustomTypeId.h"
#include "Greis/DataChunk.h"
#include "Greis/AllStdMessages.h"
#include "Greis/AllCustomTypes.h"

using namespace Common;

namespace Greis
{
    void MySqlSource::constructCtQueriesAndHandlers()
    {
        GreisMysqlSerializer& serializer = _serializer;
        
        auto queryUtcOffsCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `a0`, `a1`, `tot`, `wnt`, `dtls`, `dn`, `wnlsf`, `dtlsf` FROM `ct_UtcOffs`");
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
        
        auto queryESICustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `ssid`, `svid` FROM `ct_ESI`");
        auto handlerESICustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new ESICustomType(size);
                auto c = dynamic_cast<ESICustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Ssid());
                serializer.Deserialize(q.value(5), c->Svid());
            };
        
        auto querySmoothCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `value`, `interval` FROM `ct_Smooth`");
        auto handlerSmoothCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SmoothCustomType(size);
                auto c = dynamic_cast<SmoothCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Value());
                serializer.Deserialize(q.value(5), c->Interval());
            };
        
        auto queryGpsEphReqDataCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `tow`, `flags`, `iodc`, `toc`, `ura`, `healthS`, `wn`, `tgd`, `af2`, `af1`, `af0`, `toe`, `iode`, `rootA`, `ecc`, `m0`, `omega0`, `inc0`, `argPer`, `deln`, `omegaDot`, `incDot`, `crc`, `crs`, `cuc`, `cus`, `cic`, `cis` FROM `ct_GpsEphReqData`");
        auto handlerGpsEphReqDataCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GpsEphReqDataCustomType(size);
                auto c = dynamic_cast<GpsEphReqDataCustomType*>(ct);
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
        
        auto queryGpsEphOptDataCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `navType`, `lTope`, `lTopc`, `dADot`, `cURAoc`, `cURAoc1`, `cURAoc2`, `fIscL1CA`, `fIscL5I5`, `fIscL1CP`, `DAf0` FROM `ct_GpsEphOptData`");
        auto handlerGpsEphOptDataCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GpsEphOptDataCustomType(size);
                auto c = dynamic_cast<GpsEphOptDataCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->NavType());
                serializer.Deserialize(q.value(5), c->LTope());
                serializer.Deserialize(q.value(6), c->LTopc());
                serializer.Deserialize(q.value(7), c->DADot());
                serializer.Deserialize(q.value(8), c->CURAoc());
                serializer.Deserialize(q.value(9), c->CURAoc1());
                serializer.Deserialize(q.value(10), c->CURAoc2());
                serializer.Deserialize(q.value(11), c->FIscL1CA());
                serializer.Deserialize(q.value(12), c->FIscL5I5());
                serializer.Deserialize(q.value(13), c->FIscL1CP());
                serializer.Deserialize(q.value(14), c->DAf0());
            };
        
        auto querySvData0CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `prn`, `cnt`, `data` FROM `ct_SvData0`");
        auto handlerSvData0CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SvData0CustomType(size);
                auto c = dynamic_cast<SvData0CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Prn());
                serializer.Deserialize(q.value(5), c->Cnt());
                serializer.Deserialize(q.value(6), c->Data());
            };
        
        auto querySvData1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `fcn1`, `cnt`, `data` FROM `ct_SvData1`");
        auto handlerSvData1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SvData1CustomType(size);
                auto c = dynamic_cast<SvData1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Fcn1());
                serializer.Deserialize(q.value(5), c->Cnt());
                serializer.Deserialize(q.value(6), c->Data());
            };
        
        auto querySpecDataCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `spec` FROM `ct_SpecData`");
        auto handlerSpecDataCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SpecDataCustomType(size);
                auto c = dynamic_cast<SpecDataCustomType*>(ct);
                
                /*throw Common::NotImplementedException();*/
            };
        
        auto queryExtSpecDataCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `spec`, `agcmin`, `agcmax` FROM `ct_ExtSpecData`");
        auto handlerExtSpecDataCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new ExtSpecDataCustomType(size);
                auto c = dynamic_cast<ExtSpecDataCustomType*>(ct);
                
                /*throw Common::NotImplementedException();*/
            };
        
        auto queryGloDelaysCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `del`, `cs` FROM `ct_GloDelays`");
        auto handlerGloDelaysCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GloDelaysCustomType(size);
                auto c = dynamic_cast<GloDelaysCustomType*>(ct);
                
                /*throw Common::NotImplementedException();*/
            };
        
        auto queryBandDelayCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `band`, `signal`, `delay` FROM `ct_BandDelay`");
        auto handlerBandDelayCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new BandDelayCustomType(size);
                auto c = dynamic_cast<BandDelayCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Band());
                serializer.Deserialize(q.value(5), c->Signal());
                serializer.Deserialize(q.value(6), c->Delay());
            };
        
        auto querySvData2CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `header`, `slot` FROM `ct_SvData2`");
        auto handlerSvData2CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new SvData2CustomType(size);
                auto c = dynamic_cast<SvData2CustomType*>(ct);
                
                /*throw Common::NotImplementedException();*/
            };
        
        auto queryHeaderCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `refrange`, `usi`, `num` FROM `ct_Header`");
        auto handlerHeaderCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new HeaderCustomType(size);
                auto c = dynamic_cast<HeaderCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Refrange());
                serializer.Deserialize(q.value(5), c->Usi());
                serializer.Deserialize(q.value(6), c->Num());
            };
        
        auto querySlotRecCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `svstOrDelrange`, `word1`, `flags`, `lock`, `word2` FROM `ct_SlotRec`");
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
        
        auto queryClkOffsCustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `word1`, `word2` FROM `ct_ClkOffs`");
        auto handlerClkOffsCustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new ClkOffsCustomType(size);
                auto c = dynamic_cast<ClkOffsCustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Word1());
                serializer.Deserialize(q.value(5), c->Word2());
            };
        
        auto queryGPSAlm1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot` FROM `ct_GPSAlm1`");
        auto handlerGPSAlm1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GPSAlm1CustomType(size);
                auto c = dynamic_cast<GPSAlm1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Sv());
                serializer.Deserialize(q.value(5), c->Wna());
                serializer.Deserialize(q.value(6), c->Toa());
                serializer.Deserialize(q.value(7), c->HealthA());
                serializer.Deserialize(q.value(8), c->Config());
                serializer.Deserialize(q.value(9), c->Af1());
                serializer.Deserialize(q.value(10), c->Af0());
                serializer.Deserialize(q.value(11), c->RootA());
                serializer.Deserialize(q.value(12), c->Ecc());
                serializer.Deserialize(q.value(13), c->M0());
                serializer.Deserialize(q.value(14), c->Omega0());
                serializer.Deserialize(q.value(15), c->ArgPer());
                serializer.Deserialize(q.value(16), c->Deli());
                serializer.Deserialize(q.value(17), c->OmegaDot());
            };
        
        auto queryGPSEphemeris1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `req`, `opt` FROM `ct_GPSEphemeris1`");
        auto handlerGPSEphemeris1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GPSEphemeris1CustomType(size);
                auto c = dynamic_cast<GPSEphemeris1CustomType*>(ct);
                c->Req() = this->extractCustomType<GpsEphReqDataCustomType>(ECustomTypeId::GpsEphReqData, q.value(4).toInt());
                c->Opt() = this->extractCustomType<GpsEphOptDataCustomType>(ECustomTypeId::GpsEphOptData, q.value(5).toInt());
            };
        
        auto queryIonoParams1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `tot`, `wn`, `alpha0`, `alpha1`, `alpha2`, `alpha3`, `beta0`, `beta1`, `beta2`, `beta3`, `cs` FROM `ct_IonoParams1`");
        auto handlerIonoParams1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new IonoParams1CustomType(size);
                auto c = dynamic_cast<IonoParams1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Tot());
                serializer.Deserialize(q.value(5), c->Wn());
                serializer.Deserialize(q.value(6), c->Alpha0());
                serializer.Deserialize(q.value(7), c->Alpha1());
                serializer.Deserialize(q.value(8), c->Alpha2());
                serializer.Deserialize(q.value(9), c->Alpha3());
                serializer.Deserialize(q.value(10), c->Beta0());
                serializer.Deserialize(q.value(11), c->Beta1());
                serializer.Deserialize(q.value(12), c->Beta2());
                serializer.Deserialize(q.value(13), c->Beta3());
                serializer.Deserialize(q.value(14), c->Cs());
            };
        
        auto queryGpsNavData1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `recSize`, `dat`, `cs` FROM `ct_GpsNavData1`");
        auto handlerGpsNavData1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GpsNavData1CustomType(size);
                auto c = dynamic_cast<GpsNavData1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->RecSize());
                c->Dat() = this->deserializeAndGetCustomTypes<SvData0CustomType>(ECustomTypeId::SvData0, q.value(5));
                serializer.Deserialize(q.value(6), c->Cs());
            };
        
        auto queryGpsRawNavData1CustomType = QString("SELECT `id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `errCorr`, `cs` FROM `ct_GpsRawNavData1`");
        auto handlerGpsRawNavData1CustomType = [&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)
            {
                ct = new GpsRawNavData1CustomType(size);
                auto c = dynamic_cast<GpsRawNavData1CustomType*>(ct);
                serializer.Deserialize(q.value(4), c->Prn());
                serializer.Deserialize(q.value(5), c->Time());
                serializer.Deserialize(q.value(6), c->Type());
                serializer.Deserialize(q.value(7), c->Len());
                serializer.Deserialize(q.value(8), c->Data());
                serializer.Deserialize(q.value(9), c->ErrCorr());
                serializer.Deserialize(q.value(10), c->Cs());
            };
        
        _ctQueries.insert(ECustomTypeId::UtcOffs, queryUtcOffsCustomType);
        _ctHandlers.insert(ECustomTypeId::UtcOffs, handlerUtcOffsCustomType);
        _ctQueries.insert(ECustomTypeId::ESI, queryESICustomType);
        _ctHandlers.insert(ECustomTypeId::ESI, handlerESICustomType);
        _ctQueries.insert(ECustomTypeId::Smooth, querySmoothCustomType);
        _ctHandlers.insert(ECustomTypeId::Smooth, handlerSmoothCustomType);
        _ctQueries.insert(ECustomTypeId::GpsEphReqData, queryGpsEphReqDataCustomType);
        _ctHandlers.insert(ECustomTypeId::GpsEphReqData, handlerGpsEphReqDataCustomType);
        _ctQueries.insert(ECustomTypeId::GpsEphOptData, queryGpsEphOptDataCustomType);
        _ctHandlers.insert(ECustomTypeId::GpsEphOptData, handlerGpsEphOptDataCustomType);
        _ctQueries.insert(ECustomTypeId::SvData0, querySvData0CustomType);
        _ctHandlers.insert(ECustomTypeId::SvData0, handlerSvData0CustomType);
        _ctQueries.insert(ECustomTypeId::SvData1, querySvData1CustomType);
        _ctHandlers.insert(ECustomTypeId::SvData1, handlerSvData1CustomType);
        _ctQueries.insert(ECustomTypeId::SpecData, querySpecDataCustomType);
        _ctHandlers.insert(ECustomTypeId::SpecData, handlerSpecDataCustomType);
        _ctQueries.insert(ECustomTypeId::ExtSpecData, queryExtSpecDataCustomType);
        _ctHandlers.insert(ECustomTypeId::ExtSpecData, handlerExtSpecDataCustomType);
        _ctQueries.insert(ECustomTypeId::GloDelays, queryGloDelaysCustomType);
        _ctHandlers.insert(ECustomTypeId::GloDelays, handlerGloDelaysCustomType);
        _ctQueries.insert(ECustomTypeId::BandDelay, queryBandDelayCustomType);
        _ctHandlers.insert(ECustomTypeId::BandDelay, handlerBandDelayCustomType);
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
        _ctQueries.insert(ECustomTypeId::IonoParams1, queryIonoParams1CustomType);
        _ctHandlers.insert(ECustomTypeId::IonoParams1, handlerIonoParams1CustomType);
        _ctQueries.insert(ECustomTypeId::GpsNavData1, queryGpsNavData1CustomType);
        _ctHandlers.insert(ECustomTypeId::GpsNavData1, handlerGpsNavData1CustomType);
        _ctQueries.insert(ECustomTypeId::GpsRawNavData1, queryGpsRawNavData1CustomType);
        _ctHandlers.insert(ECustomTypeId::GpsRawNavData1, handlerGpsRawNavData1CustomType);
    }

    void MySqlSource::constructMsgQueriesAndHandlers()
    {
        GreisMysqlSerializer& serializer = _serializer;

        auto queryFileIdStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar` FROM `msg_FileId`");
        auto handlerFileIdStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new FileIdStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->IdField());
                return (Message*)c;
            };
        
        auto queryMsgFmtStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `majorVer`, `minorVer`, `order`, `cs` FROM `msg_MsgFmt`");
        auto handlerMsgFmtStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new MsgFmtStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->IdField());
                serializer.Deserialize(q.value(7), c->MajorVer());
                serializer.Deserialize(q.value(8), c->MinorVer());
                serializer.DeserializeChar(q.value(9), c->Order());
                serializer.Deserialize(q.value(10), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvTimeStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs` FROM `msg_RcvTime`");
        auto handlerRcvTimeStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvTimeStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Tod());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryEpochTimeStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `cs` FROM `msg_EpochTime`");
        auto handlerEpochTimeStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new EpochTimeStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Tod());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvDateStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `year`, `month`, `day`, `base`, `cs` FROM `msg_RcvDate`");
        auto handlerRcvDateStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvDateStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Year());
                serializer.Deserialize(q.value(7), c->Month());
                serializer.Deserialize(q.value(8), c->Day());
                serializer.Deserialize(q.value(9), c->Base());
                serializer.Deserialize(q.value(10), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvTimeOffset`");
        auto handlerRcvTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvTimeOffsetDotStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvTimeOffsetDot`");
        auto handlerRcvTimeOffsetDotStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvTimeOffsetDotStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvTimeAccuracyStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `acc`, `cs` FROM `msg_RcvTimeAccuracy`");
        auto handlerRcvTimeAccuracyStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvTimeAccuracyStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Acc());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryGPSTimeStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tow`, `wn`, `cs` FROM `msg_GPSTime`");
        auto handlerGPSTimeStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GPSTimeStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Tow());
                serializer.Deserialize(q.value(7), c->Wn());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvGPSTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGPSTimeOffset`");
        auto handlerRcvGPSTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvGPSTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryGLOTimeStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tod`, `dn`, `cs` FROM `msg_GLOTime`");
        auto handlerGLOTimeStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GLOTimeStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Tod());
                serializer.Deserialize(q.value(7), c->Dn());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvGLOTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGLOTimeOffset`");
        auto handlerRcvGLOTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvGLOTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvGALTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvGALTimeOffset`");
        auto handlerRcvGALTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvGALTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvSBASTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvSBASTimeOffset`");
        auto handlerRcvSBASTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvSBASTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvQZSSTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvQZSSTimeOffset`");
        auto handlerRcvQZSSTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvQZSSTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvBeiDouTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvBeiDouTimeOffset`");
        auto handlerRcvBeiDouTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvBeiDouTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvIrnssTimeOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `sval`, `cs` FROM `msg_RcvIrnssTimeOffset`");
        auto handlerRcvIrnssTimeOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvIrnssTimeOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Sval());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryGpsUtcParamStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc` FROM `msg_GpsUtcParam`");
        auto handlerGpsUtcParamStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GpsUtcParamStdMessage(id, bodySize);
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto querySbasUtcParamStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `utcsi`, `tow`, `wn`, `flags`, `cs` FROM `msg_SbasUtcParam`");
        auto handlerSbasUtcParamStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SbasUtcParamStdMessage(id, bodySize);
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->Utcsi());
                serializer.Deserialize(q.value(8), c->Tow());
                serializer.Deserialize(q.value(9), c->Wn());
                serializer.Deserialize(q.value(10), c->Flags());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto queryGalUtcGpsParamStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `a1g`, `t0g`, `wn0g`, `flags`, `cs` FROM `msg_GalUtcGpsParam`");
        auto handlerGalUtcGpsParamStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GalUtcGpsParamStdMessage(id, bodySize);
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->A1g());
                serializer.Deserialize(q.value(8), c->T0g());
                serializer.Deserialize(q.value(9), c->Wn0g());
                serializer.Deserialize(q.value(10), c->Flags());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto queryQzssUtcParamStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `cs` FROM `msg_QzssUtcParam`");
        auto handlerQzssUtcParamStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new QzssUtcParamStdMessage(id, bodySize);
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryBeiDouUtcParamStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc` FROM `msg_BeiDouUtcParam`");
        auto handlerBeiDouUtcParamStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new BeiDouUtcParamStdMessage(id, bodySize);
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto queryIrnssUtcParamStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `utc`, `cs` FROM `msg_IrnssUtcParam`");
        auto handlerIrnssUtcParamStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IrnssUtcParamStdMessage(id, bodySize);
                c->Utc() = this->extractCustomType<UtcOffsCustomType>(ECustomTypeId::UtcOffs, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryGloUtcGpsParamStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tauSys`, `tauGps`, `B1`, `B2`, `KP`, `N4`, `Dn`, `Nt`, `cs` FROM `msg_GloUtcGpsParam`");
        auto handlerGloUtcGpsParamStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GloUtcGpsParamStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->TauSys());
                serializer.Deserialize(q.value(7), c->TauGps());
                serializer.Deserialize(q.value(8), c->B1());
                serializer.Deserialize(q.value(9), c->B2());
                serializer.Deserialize(q.value(10), c->KP());
                serializer.Deserialize(q.value(11), c->N4());
                serializer.Deserialize(q.value(12), c->Dn());
                serializer.Deserialize(q.value(13), c->Nt());
                serializer.Deserialize(q.value(14), c->Cs());
                return (Message*)c;
            };
        
        auto querySolutionTimeStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `solType`, `cs` FROM `msg_SolutionTime`");
        auto handlerSolutionTimeStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SolutionTimeStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->SolType());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryPosStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `pSigma`, `solType`, `cs` FROM `msg_Pos`");
        auto handlerPosStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PosStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->X());
                serializer.Deserialize(q.value(7), c->Y());
                serializer.Deserialize(q.value(8), c->Z());
                serializer.Deserialize(q.value(9), c->PSigma());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto querySpecificCrtPos0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `pSigma`, `solType`, `system`, `crsCode`, `cs` FROM `msg_SpecificCrtPos0`");
        auto handlerSpecificCrtPos0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SpecificCrtPos0StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->X());
                serializer.Deserialize(q.value(7), c->Y());
                serializer.Deserialize(q.value(8), c->Z());
                serializer.Deserialize(q.value(9), c->PSigma());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->System());
                serializer.Deserialize(q.value(12), c->CrsCode());
                serializer.Deserialize(q.value(13), c->Cs());
                return (Message*)c;
            };
        
        auto queryVelStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `vSigma`, `solType`, `cs` FROM `msg_Vel`");
        auto handlerVelStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new VelStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->X());
                serializer.Deserialize(q.value(7), c->Y());
                serializer.Deserialize(q.value(8), c->Z());
                serializer.Deserialize(q.value(9), c->VSigma());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto queryPosVelStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `pSigma`, `vx`, `vy`, `vz`, `vSigma`, `solType`, `cs` FROM `msg_PosVel`");
        auto handlerPosVelStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PosVelStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->X());
                serializer.Deserialize(q.value(7), c->Y());
                serializer.Deserialize(q.value(8), c->Z());
                serializer.Deserialize(q.value(9), c->PSigma());
                serializer.Deserialize(q.value(10), c->Vx());
                serializer.Deserialize(q.value(11), c->Vy());
                serializer.Deserialize(q.value(12), c->Vz());
                serializer.Deserialize(q.value(13), c->VSigma());
                serializer.Deserialize(q.value(14), c->SolType());
                serializer.Deserialize(q.value(15), c->Cs());
                return (Message*)c;
            };
        
        auto queryGeoPosStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `cs` FROM `msg_GeoPos`");
        auto handlerGeoPosStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GeoPosStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Lat());
                serializer.Deserialize(q.value(7), c->Lon());
                serializer.Deserialize(q.value(8), c->Alt());
                serializer.Deserialize(q.value(9), c->PSigma());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto querySpecificCrtPos1StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `pSigma`, `solType`, `system` FROM `msg_SpecificCrtPos1`");
        auto handlerSpecificCrtPos1StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SpecificCrtPos1StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Lat());
                serializer.Deserialize(q.value(7), c->Lon());
                serializer.Deserialize(q.value(8), c->Alt());
                serializer.Deserialize(q.value(9), c->PSigma());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->System());
                return (Message*)c;
            };
        
        auto queryGeoVelStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lat`, `lon`, `alt`, `vSigma`, `solType`, `cs` FROM `msg_GeoVel`");
        auto handlerGeoVelStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GeoVelStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Lat());
                serializer.Deserialize(q.value(7), c->Lon());
                serializer.Deserialize(q.value(8), c->Alt());
                serializer.Deserialize(q.value(9), c->VSigma());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto queryRmsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hpos`, `vpos`, `hvel`, `vvel`, `solType`, `cs` FROM `msg_Rms`");
        auto handlerRmsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RmsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Hpos());
                serializer.Deserialize(q.value(7), c->Vpos());
                serializer.Deserialize(q.value(8), c->Hvel());
                serializer.Deserialize(q.value(9), c->Vvel());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto queryLocalPlanePosStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `n`, `e`, `u`, `sep`, `pSigma`, `solType`, `geoid`, `prj`, `cs` FROM `msg_LocalPlanePos`");
        auto handlerLocalPlanePosStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new LocalPlanePosStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->N());
                serializer.Deserialize(q.value(7), c->E());
                serializer.Deserialize(q.value(8), c->U());
                serializer.Deserialize(q.value(9), c->Sep());
                serializer.Deserialize(q.value(10), c->PSigma());
                serializer.Deserialize(q.value(11), c->SolType());
                serializer.Deserialize(q.value(12), c->Geoid());
                serializer.Deserialize(q.value(13), c->Prj());
                serializer.Deserialize(q.value(14), c->Cs());
                return (Message*)c;
            };
        
        auto queryRSLocalPlanePosStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `n`, `e`, `u`, `sep`, `pSigma`, `solType`, `geoid`, `prj`, `cs` FROM `msg_RSLocalPlanePos`");
        auto handlerRSLocalPlanePosStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RSLocalPlanePosStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->N());
                serializer.Deserialize(q.value(7), c->E());
                serializer.Deserialize(q.value(8), c->U());
                serializer.Deserialize(q.value(9), c->Sep());
                serializer.Deserialize(q.value(10), c->PSigma());
                serializer.Deserialize(q.value(11), c->SolType());
                serializer.Deserialize(q.value(12), c->Geoid());
                serializer.Deserialize(q.value(13), c->Prj());
                serializer.Deserialize(q.value(14), c->Cs());
                return (Message*)c;
            };
        
        auto queryDopsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `hdop`, `vdop`, `tdop`, `solType`, `edop`, `cs` FROM `msg_Dops`");
        auto handlerDopsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new DopsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Hdop());
                serializer.Deserialize(q.value(7), c->Vdop());
                serializer.Deserialize(q.value(8), c->Tdop());
                serializer.Deserialize(q.value(9), c->SolType());
                serializer.Deserialize(q.value(10), c->Edop());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto queryPosCovStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs` FROM `msg_PosCov`");
        auto handlerPosCovStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PosCovStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Xx());
                serializer.Deserialize(q.value(7), c->Yy());
                serializer.Deserialize(q.value(8), c->Zz());
                serializer.Deserialize(q.value(9), c->Tt());
                serializer.Deserialize(q.value(10), c->Xy());
                serializer.Deserialize(q.value(11), c->Xz());
                serializer.Deserialize(q.value(12), c->Xt());
                serializer.Deserialize(q.value(13), c->Yz());
                serializer.Deserialize(q.value(14), c->Yt());
                serializer.Deserialize(q.value(15), c->Zt());
                serializer.Deserialize(q.value(16), c->SolType());
                serializer.Deserialize(q.value(17), c->Cs());
                return (Message*)c;
            };
        
        auto queryVelCovStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `xx`, `yy`, `zz`, `tt`, `xy`, `xz`, `xt`, `yz`, `yt`, `zt`, `solType`, `cs` FROM `msg_VelCov`");
        auto handlerVelCovStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new VelCovStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Xx());
                serializer.Deserialize(q.value(7), c->Yy());
                serializer.Deserialize(q.value(8), c->Zz());
                serializer.Deserialize(q.value(9), c->Tt());
                serializer.Deserialize(q.value(10), c->Xy());
                serializer.Deserialize(q.value(11), c->Xz());
                serializer.Deserialize(q.value(12), c->Xt());
                serializer.Deserialize(q.value(13), c->Yz());
                serializer.Deserialize(q.value(14), c->Yt());
                serializer.Deserialize(q.value(15), c->Zt());
                serializer.Deserialize(q.value(16), c->SolType());
                serializer.Deserialize(q.value(17), c->Cs());
                return (Message*)c;
            };
        
        auto queryBaselineStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `sigma`, `solType`, `time`, `cs` FROM `msg_Baseline`");
        auto handlerBaselineStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new BaselineStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->X());
                serializer.Deserialize(q.value(7), c->Y());
                serializer.Deserialize(q.value(8), c->Z());
                serializer.Deserialize(q.value(9), c->Sigma());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Time());
                serializer.Deserialize(q.value(12), c->Cs());
                return (Message*)c;
            };
        
        auto queryBaselinesStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `bl0`, `bl1`, `bl2`, `rms`, `solType`, `cs` FROM `msg_Baselines`");
        auto handlerBaselinesStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new BaselinesStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Bl0());
                serializer.Deserialize(q.value(7), c->Bl1());
                serializer.Deserialize(q.value(8), c->Bl2());
                serializer.Deserialize(q.value(9), c->Rms());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto queryFullRotationMatrixStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `q00`, `q01`, `q02`, `q10`, `q11`, `q12`, `q20`, `q21`, `q22`, `cs` FROM `msg_FullRotationMatrix`");
        auto handlerFullRotationMatrixStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new FullRotationMatrixStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Q00());
                serializer.Deserialize(q.value(7), c->Q01());
                serializer.Deserialize(q.value(8), c->Q02());
                serializer.Deserialize(q.value(9), c->Q10());
                serializer.Deserialize(q.value(10), c->Q11());
                serializer.Deserialize(q.value(11), c->Q12());
                serializer.Deserialize(q.value(12), c->Q20());
                serializer.Deserialize(q.value(13), c->Q21());
                serializer.Deserialize(q.value(14), c->Q22());
                serializer.Deserialize(q.value(15), c->Cs());
                return (Message*)c;
            };
        
        auto queryPosStatStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `solType`, `gpsLocked`, `gloLocked`, `gpsAvail`, `gloAvail`, `gpsUsed`, `gloUsed`, `fixProg`, `cs` FROM `msg_PosStat`");
        auto handlerPosStatStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PosStatStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->SolType());
                serializer.Deserialize(q.value(7), c->GpsLocked());
                serializer.Deserialize(q.value(8), c->GloLocked());
                serializer.Deserialize(q.value(9), c->GpsAvail());
                serializer.Deserialize(q.value(10), c->GloAvail());
                serializer.Deserialize(q.value(11), c->GpsUsed());
                serializer.Deserialize(q.value(12), c->GloUsed());
                serializer.Deserialize(q.value(13), c->FixProg());
                serializer.Deserialize(q.value(14), c->Cs());
                return (Message*)c;
            };
        
        auto queryPosCompTimeStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pt`, `cs` FROM `msg_PosCompTime`");
        auto handlerPosCompTimeStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PosCompTimeStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Pt());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryExtSatIndexStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `esi`, `cs` FROM `msg_ExtSatIndex`");
        auto handlerExtSatIndexStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new ExtSatIndexStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto querySatIndexStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `usi`, `cs` FROM `msg_SatIndex`");
        auto handlerSatIndexStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SatIndexStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Usi());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryAntNameStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `name`, `cs` FROM `msg_AntName`");
        auto handlerAntNameStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new AntNameStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Name());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto querySatNumbersStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `osn`, `cs` FROM `msg_SatNumbers`");
        auto handlerSatNumbersStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SatNumbersStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Osn());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto querySatElevationStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `elev`, `cs` FROM `msg_SatElevation`");
        auto handlerSatElevationStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SatElevationStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Elev());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto querySatAzimuthStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `azim`, `cs` FROM `msg_SatAzimuth`");
        auto handlerSatAzimuthStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SatAzimuthStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Azim());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryPRStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `pr`, `cs` FROM `msg_PR`");
        auto handlerPRStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PRStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto querySPRStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `spr`, `cs` FROM `msg_SPR`");
        auto handlerSPRStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SPRStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryRPRStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rpr`, `cs` FROM `msg_RPR`");
        auto handlerRPRStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RPRStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto querySRPRStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srpr`, `cs` FROM `msg_SRPR`");
        auto handlerSRPRStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SRPRStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryPrCorrStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prc`, `mode`, `cs` FROM `msg_PrCorr`");
        auto handlerPrCorrStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PrCorrStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto querySCStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs` FROM `msg_SC`");
        auto handlerSCStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SCStdMessage(id, bodySize);
                c->Smooth() = this->deserializeAndGetCustomTypes<SmoothCustomType>(ECustomTypeId::Smooth, q.value(6));
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto querySSStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `smooth`, `cs` FROM `msg_SS`");
        auto handlerSSStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SSStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Smooth());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryCPStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cp`, `cs` FROM `msg_CP`");
        auto handlerCPStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new CPStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Cp());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto querySCPStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `scp`, `cs` FROM `msg_SCP`");
        auto handlerSCPStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SCPStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Scp());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryRCPRC0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs` FROM `msg_RCP_RC0`");
        auto handlerRCPRC0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RCPRC0StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Rcp());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryRCPRc1StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `rcp`, `cs` FROM `msg_RCP_rc1`");
        auto handlerRCPRc1StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RCPRc1StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Rcp());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryPhCorrStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `phc`, `mode`, `cs` FROM `msg_PhCorr`");
        auto handlerPhCorrStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PhCorrStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryDPStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `dp`, `cs` FROM `msg_DP`");
        auto handlerDPStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new DPStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto querySRDPStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `srdp`, `cs` FROM `msg_SRDP`");
        auto handlerSRDPStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SRDPStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryCNRStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnr`, `cs` FROM `msg_CNR`");
        auto handlerCNRStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new CNRStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Cnr());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryCNR4StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnrX4`, `cs` FROM `msg_CNR_4`");
        auto handlerCNR4StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new CNR4StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->CnrX4());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryCNR2560StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnrX256`, `cs` FROM `msg_CNR_2560`");
        auto handlerCNR2560StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new CNR2560StdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryCNR2561StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `cnrX256`, `cs` FROM `msg_CNR_2561`");
        auto handlerCNR2561StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new CNR2561StdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryFlagsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `flags`, `cs` FROM `msg_Flags`");
        auto handlerFlagsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new FlagsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Flags());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryIAmpStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `amp`, `cs` FROM `msg_IAmp`");
        auto handlerIAmpStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IAmpStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryQAmpStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `amp`, `cs` FROM `msg_QAmp`");
        auto handlerQAmpStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new QAmpStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryTrackingTimeCAStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs` FROM `msg_TrackingTimeCA`");
        auto handlerTrackingTimeCAStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new TrackingTimeCAStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Tt());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryNavStatusStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ns`, `solType`, `cs` FROM `msg_NavStatus`");
        auto handlerNavStatusStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new NavStatusStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Ns());
                serializer.Deserialize(q.value(7), c->SolType());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryIonoDelayStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `delay`, `cs` FROM `msg_IonoDelay`");
        auto handlerIonoDelayStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IonoDelayStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Delay());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryRangeResidualStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `res`, `cs` FROM `msg_RangeResidual`");
        auto handlerRangeResidualStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RangeResidualStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryVelocityResidualStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `res`, `cs` FROM `msg_VelocityResidual`");
        auto handlerVelocityResidualStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new VelocityResidualStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryGPSAlm0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `wna`, `toa`, `healthA`, `config`, `af1`, `af0`, `rootA`, `ecc`, `m0`, `omega0`, `argPer`, `deli`, `omegaDot`, `cs` FROM `msg_GPSAlm0`");
        auto handlerGPSAlm0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GPSAlm0StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Sv());
                serializer.Deserialize(q.value(7), c->Wna());
                serializer.Deserialize(q.value(8), c->Toa());
                serializer.Deserialize(q.value(9), c->HealthA());
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
                return (Message*)c;
            };
        
        auto queryGALAlmStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `iod`, `cs` FROM `msg_GALAlm`");
        auto handlerGALAlmStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GALAlmStdMessage(id, bodySize);
                c->Gps() = this->extractCustomType<GPSAlm1CustomType>(ECustomTypeId::GPSAlm1, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->Iod());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryQZSSAlmStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps` FROM `msg_QZSSAlm`");
        auto handlerQZSSAlmStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new QZSSAlmStdMessage(id, bodySize);
                c->Gps() = this->extractCustomType<GPSAlm1CustomType>(ECustomTypeId::GPSAlm1, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto queryBeiDouAlmStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps` FROM `msg_BeiDouAlm`");
        auto handlerBeiDouAlmStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new BeiDouAlmStdMessage(id, bodySize);
                c->Gps() = this->extractCustomType<GPSAlm1CustomType>(ECustomTypeId::GPSAlm1, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto queryIrnssAlmStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps` FROM `msg_IrnssAlm`");
        auto handlerIrnssAlmStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IrnssAlmStdMessage(id, bodySize);
                c->Gps() = this->extractCustomType<GPSAlm1CustomType>(ECustomTypeId::GPSAlm1, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto queryGLOAlmanacStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dna`, `tlam`, `flags`, `tauN`, `tauSys`, `ecc`, `lambda`, `argPer`, `delT`, `delTdt`, `deli`, `n4`, `reserved`, `gammaN`, `cs` FROM `msg_GLOAlmanac`");
        auto handlerGLOAlmanacStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GLOAlmanacStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Sv());
                serializer.Deserialize(q.value(7), c->FrqNum());
                serializer.Deserialize(q.value(8), c->Dna());
                serializer.Deserialize(q.value(9), c->Tlam());
                serializer.Deserialize(q.value(10), c->Flags());
                serializer.Deserialize(q.value(11), c->TauN());
                serializer.Deserialize(q.value(12), c->TauSys());
                serializer.Deserialize(q.value(13), c->Ecc());
                serializer.Deserialize(q.value(14), c->Lambda());
                serializer.Deserialize(q.value(15), c->ArgPer());
                serializer.Deserialize(q.value(16), c->DelT());
                serializer.Deserialize(q.value(17), c->DelTdt());
                serializer.Deserialize(q.value(18), c->Deli());
                serializer.Deserialize(q.value(19), c->N4());
                if (bodySize == 52)
                {
                    // Optional Data Block
                    serializer.Deserialize(q.value(20), c->Reserved());
                    serializer.Deserialize(q.value(21), c->GammaN());
                }
                serializer.Deserialize(q.value(22), c->Cs());
                return (Message*)c;
            };
        
        auto querySBASAlmanacStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `id_sugar`, `healthS`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `tow`, `wn`, `cs` FROM `msg_SBASAlmanac`");
        auto handlerSBASAlmanacStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SBASAlmanacStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->WaasPrn());
                serializer.Deserialize(q.value(7), c->GpsPrn());
                serializer.Deserialize(q.value(8), c->IdField());
                serializer.Deserialize(q.value(9), c->HealthS());
                serializer.Deserialize(q.value(10), c->Tod());
                serializer.Deserialize(q.value(11), c->Xg());
                serializer.Deserialize(q.value(12), c->Yg());
                serializer.Deserialize(q.value(13), c->Zg());
                serializer.Deserialize(q.value(14), c->Vxg());
                serializer.Deserialize(q.value(15), c->Vyg());
                serializer.Deserialize(q.value(16), c->Vzg());
                serializer.Deserialize(q.value(17), c->Tow());
                serializer.Deserialize(q.value(18), c->Wn());
                serializer.Deserialize(q.value(19), c->Cs());
                return (Message*)c;
            };
        
        auto queryGPSEphemeris0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `req`, `opt`, `cs` FROM `msg_GPSEphemeris0`");
        auto handlerGPSEphemeris0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GPSEphemeris0StdMessage(id, bodySize);
                c->Req() = this->extractCustomType<GpsEphReqDataCustomType>(ECustomTypeId::GpsEphReqData, q.value(6).toInt());
                c->Opt() = this->extractCustomType<GpsEphOptDataCustomType>(ECustomTypeId::GpsEphOptData, q.value(7).toInt());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryGALEphemerisStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `req`, `bgdE1E5a`, `bgdE1E5b`, `ai0`, `ai1`, `ai2`, `sfi`, `navType`, `DAf0`, `cs` FROM `msg_GALEphemeris`");
        auto handlerGALEphemerisStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GALEphemerisStdMessage(id, bodySize);
                c->Req() = this->extractCustomType<GpsEphReqDataCustomType>(ECustomTypeId::GpsEphReqData, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->BgdE1E5a());
                serializer.Deserialize(q.value(8), c->BgdE1E5b());
                serializer.Deserialize(q.value(9), c->Ai0());
                serializer.Deserialize(q.value(10), c->Ai1());
                serializer.Deserialize(q.value(11), c->Ai2());
                serializer.Deserialize(q.value(12), c->Sfi());
                serializer.Deserialize(q.value(13), c->NavType());
                serializer.Deserialize(q.value(14), c->DAf0());
                serializer.Deserialize(q.value(15), c->Cs());
                return (Message*)c;
            };
        
        auto queryQZSSEphemerisStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `cs` FROM `msg_QZSSEphemeris`");
        auto handlerQZSSEphemerisStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new QZSSEphemerisStdMessage(id, bodySize);
                c->Gps() = this->extractCustomType<GPSEphemeris1CustomType>(ECustomTypeId::GPSEphemeris1, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryBeiDouEphemerisStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `req`, `tgd2`, `navType`, `DAf0`, `cs` FROM `msg_BeiDouEphemeris`");
        auto handlerBeiDouEphemerisStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new BeiDouEphemerisStdMessage(id, bodySize);
                c->Req() = this->extractCustomType<GpsEphReqDataCustomType>(ECustomTypeId::GpsEphReqData, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->Tgd2());
                serializer.Deserialize(q.value(8), c->NavType());
                serializer.Deserialize(q.value(9), c->DAf0());
                serializer.Deserialize(q.value(10), c->Cs());
                return (Message*)c;
            };
        
        auto queryGLOEphemerisStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sv`, `frqNum`, `dne`, `tk`, `tb`, `health`, `age`, `flags`, `r`, `v`, `w`, `tauSys`, `tau`, `gamma`, `fDelTauN`, `nFt`, `nN4`, `flags2`, `navType`, `beta`, `tauSysDot`, `ec`, `ee`, `fc`, `fe`, `reserv`, `cs` FROM `msg_GLOEphemeris`");
        auto handlerGLOEphemerisStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GLOEphemerisStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Sv());
                serializer.Deserialize(q.value(7), c->FrqNum());
                serializer.Deserialize(q.value(8), c->Dne());
                serializer.Deserialize(q.value(9), c->Tk());
                serializer.Deserialize(q.value(10), c->Tb());
                serializer.Deserialize(q.value(11), c->Health());
                serializer.Deserialize(q.value(12), c->Age());
                serializer.Deserialize(q.value(13), c->Flags());
                serializer.Deserialize(q.value(14), c->R());
                serializer.Deserialize(q.value(15), c->V());
                serializer.Deserialize(q.value(16), c->W());
                serializer.Deserialize(q.value(17), c->TauSys());
                serializer.Deserialize(q.value(18), c->Tau());
                serializer.Deserialize(q.value(19), c->Gamma());
                serializer.Deserialize(q.value(20), c->FDelTauN());
                serializer.Deserialize(q.value(21), c->NFt());
                serializer.Deserialize(q.value(22), c->NN4());
                serializer.Deserialize(q.value(23), c->Flags2());
                if (bodySize == 103)
                {
                    // Optional Data Block
                    serializer.Deserialize(q.value(24), c->NavType());
                    serializer.Deserialize(q.value(25), c->Beta());
                    serializer.Deserialize(q.value(26), c->TauSysDot());
                    serializer.Deserialize(q.value(27), c->Ec());
                    serializer.Deserialize(q.value(28), c->Ee());
                    serializer.Deserialize(q.value(29), c->Fc());
                    serializer.Deserialize(q.value(30), c->Fe());
                    serializer.Deserialize(q.value(31), c->Reserv());
                }
                serializer.Deserialize(q.value(32), c->Cs());
                return (Message*)c;
            };
        
        auto querySBASEhemerisStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `waasPrn`, `gpsPrn`, `iod`, `acc`, `tod`, `xg`, `yg`, `zg`, `vxg`, `vyg`, `vzg`, `vvxg`, `vvyg`, `vvzg`, `agf0`, `agf1`, `tow`, `wn`, `flags`, `cs` FROM `msg_SBASEhemeris`");
        auto handlerSBASEhemerisStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SBASEhemerisStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->WaasPrn());
                serializer.Deserialize(q.value(7), c->GpsPrn());
                serializer.Deserialize(q.value(8), c->Iod());
                serializer.Deserialize(q.value(9), c->Acc());
                serializer.Deserialize(q.value(10), c->Tod());
                serializer.Deserialize(q.value(11), c->Xg());
                serializer.Deserialize(q.value(12), c->Yg());
                serializer.Deserialize(q.value(13), c->Zg());
                serializer.Deserialize(q.value(14), c->Vxg());
                serializer.Deserialize(q.value(15), c->Vyg());
                serializer.Deserialize(q.value(16), c->Vzg());
                serializer.Deserialize(q.value(17), c->Vvxg());
                serializer.Deserialize(q.value(18), c->Vvyg());
                serializer.Deserialize(q.value(19), c->Vvzg());
                serializer.Deserialize(q.value(20), c->Agf0());
                serializer.Deserialize(q.value(21), c->Agf1());
                serializer.Deserialize(q.value(22), c->Tow());
                serializer.Deserialize(q.value(23), c->Wn());
                serializer.Deserialize(q.value(24), c->Flags());
                serializer.Deserialize(q.value(25), c->Cs());
                return (Message*)c;
            };
        
        auto queryIrnssEphemerisStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `gps`, `navType`, `cs` FROM `msg_IrnssEphemeris`");
        auto handlerIrnssEphemerisStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IrnssEphemerisStdMessage(id, bodySize);
                c->Gps() = this->extractCustomType<GPSEphemeris1CustomType>(ECustomTypeId::GPSEphemeris1, q.value(6).toInt());
                serializer.Deserialize(q.value(7), c->NavType());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryGpsRawNavData0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `errCorr`, `cs` FROM `msg_GpsRawNavData0`");
        auto handlerGpsRawNavData0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GpsRawNavData0StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Prn());
                serializer.Deserialize(q.value(7), c->Time());
                serializer.Deserialize(q.value(8), c->Type());
                serializer.Deserialize(q.value(9), c->Len());
                serializer.Deserialize(q.value(10), c->Data());
                serializer.Deserialize(q.value(11), c->ErrCorr());
                serializer.Deserialize(q.value(12), c->Cs());
                return (Message*)c;
            };
        
        auto queryQzssRawNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data` FROM `msg_QzssRawNavData`");
        auto handlerQzssRawNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new QzssRawNavDataStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryGloRawNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `num`, `fcn`, `time`, `type`, `len`, `data`, `errCorr`, `cs` FROM `msg_GloRawNavData`");
        auto handlerGloRawNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GloRawNavDataStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Num());
                serializer.Deserialize(q.value(7), c->Fcn());
                serializer.Deserialize(q.value(8), c->Time());
                serializer.Deserialize(q.value(9), c->Type());
                serializer.Deserialize(q.value(10), c->Len());
                serializer.Deserialize(q.value(11), c->Data());
                serializer.Deserialize(q.value(12), c->ErrCorr());
                serializer.Deserialize(q.value(13), c->Cs());
                return (Message*)c;
            };
        
        auto querySbasRawNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `errCorr`, `cs` FROM `msg_SbasRawNavData`");
        auto handlerSbasRawNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SbasRawNavDataStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Prn());
                serializer.Deserialize(q.value(7), c->Time());
                serializer.Deserialize(q.value(8), c->Type());
                serializer.Deserialize(q.value(9), c->Len());
                serializer.Deserialize(q.value(10), c->Data());
                serializer.Deserialize(q.value(11), c->ErrCorr());
                serializer.Deserialize(q.value(12), c->Cs());
                return (Message*)c;
            };
        
        auto queryGalRawNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len`, `data`, `errCorr`, `cs` FROM `msg_GalRawNavData`");
        auto handlerGalRawNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GalRawNavDataStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Prn());
                serializer.Deserialize(q.value(7), c->Time());
                serializer.Deserialize(q.value(8), c->Type());
                serializer.Deserialize(q.value(9), c->Len());
                serializer.Deserialize(q.value(10), c->Data());
                serializer.Deserialize(q.value(11), c->ErrCorr());
                serializer.Deserialize(q.value(12), c->Cs());
                return (Message*)c;
            };
        
        auto queryCompRawNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len` FROM `msg_CompRawNavData`");
        auto handlerCompRawNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new CompRawNavDataStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Prn());
                serializer.Deserialize(q.value(7), c->Time());
                serializer.Deserialize(q.value(8), c->Type());
                serializer.Deserialize(q.value(9), c->Len());
                return (Message*)c;
            };
        
        auto queryIrnssRawNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `prn`, `time`, `type`, `len` FROM `msg_IrnssRawNavData`");
        auto handlerIrnssRawNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IrnssRawNavDataStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Prn());
                serializer.Deserialize(q.value(7), c->Time());
                serializer.Deserialize(q.value(8), c->Type());
                serializer.Deserialize(q.value(9), c->Len());
                return (Message*)c;
            };
        
        auto queryGpsNavData0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs` FROM `msg_GpsNavData0`");
        auto handlerGpsNavData0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GpsNavData0StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->RecSize());
                c->Dat() = this->deserializeAndGetCustomTypes<SvData0CustomType>(ECustomTypeId::SvData0, q.value(7));
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryQzssNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data` FROM `msg_QzssNavData`");
        auto handlerQzssNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new QzssNavDataStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryGloNavDataStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `recSize`, `dat`, `cs` FROM `msg_GloNavData`");
        auto handlerGloNavDataStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new GloNavDataStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->RecSize());
                c->Dat() = this->deserializeAndGetCustomTypes<SvData1CustomType>(ECustomTypeId::SvData1, q.value(7));
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto querySpectrum0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `currFrq`, `finalFrq`, `n`, `m`, `s`, `cs` FROM `msg_Spectrum0`");
        auto handlerSpectrum0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new Spectrum0StdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto querySpectrum1StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `currFrq`, `finalFrq`, `n`, `m`, `s`, `cs` FROM `msg_Spectrum1`");
        auto handlerSpectrum1StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new Spectrum1StdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryMDMSpectrumStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `frq`, `pwr`, `cs` FROM `msg_MDM_Spectrum`");
        auto handlerMDMSpectrumStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new MDMSpectrumStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Frq());
                serializer.Deserialize(q.value(7), c->Pwr());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto querySvDelaysStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `fcn`, `phase`, `range` FROM `msg_SvDelays`");
        auto handlerSvDelaysStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new SvDelaysStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Fcn());
                serializer.Deserialize(q.value(7), c->Phase());
                serializer.Deserialize(q.value(8), c->Range());
                return (Message*)c;
            };
        
        auto queryCalBandsDelayStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `d`, `cs` FROM `msg_CalBandsDelay`");
        auto handlerCalBandsDelayStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new CalBandsDelayStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryRotationMatrixStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `cs` FROM `msg_RotationMatrix`");
        auto handlerRotationMatrixStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RotationMatrixStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->Q00());
                serializer.Deserialize(q.value(8), c->Q01());
                serializer.Deserialize(q.value(9), c->Q02());
                serializer.Deserialize(q.value(10), c->Q12());
                serializer.Deserialize(q.value(11), c->Rms());
                serializer.Deserialize(q.value(12), c->SolType());
                serializer.Deserialize(q.value(13), c->Flag());
                serializer.Deserialize(q.value(14), c->Cs());
                return (Message*)c;
            };
        
        auto queryRotationMatrixAndVectorsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `q00`, `q01`, `q02`, `q12`, `rms`, `solType`, `flag`, `bl1`, `bl2`, `cs` FROM `msg_RotationMatrixAndVectors`");
        auto handlerRotationMatrixAndVectorsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RotationMatrixAndVectorsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->Q00());
                serializer.Deserialize(q.value(8), c->Q01());
                serializer.Deserialize(q.value(9), c->Q02());
                serializer.Deserialize(q.value(10), c->Q12());
                serializer.Deserialize(q.value(11), c->Rms());
                serializer.Deserialize(q.value(12), c->SolType());
                serializer.Deserialize(q.value(13), c->Flag());
                serializer.Deserialize(q.value(14), c->Bl1());
                serializer.Deserialize(q.value(15), c->Bl2());
                serializer.Deserialize(q.value(16), c->Cs());
                return (Message*)c;
            };
        
        auto queryRotationAnglesStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `p`, `r`, `h`, `sp`, `sr`, `sh`, `solType`, `flags`, `cs` FROM `msg_RotationAngles`");
        auto handlerRotationAnglesStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RotationAnglesStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->P());
                serializer.Deserialize(q.value(8), c->R());
                serializer.Deserialize(q.value(9), c->H());
                serializer.Deserialize(q.value(10), c->Sp());
                serializer.Deserialize(q.value(11), c->Sr());
                serializer.Deserialize(q.value(12), c->Sh());
                serializer.Deserialize(q.value(13), c->SolType());
                serializer.Deserialize(q.value(14), c->Flags());
                serializer.Deserialize(q.value(15), c->Cs());
                return (Message*)c;
            };
        
        auto queryAngularVelocityStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `x`, `y`, `z`, `rms`, `flags`, `cs` FROM `msg_AngularVelocity`");
        auto handlerAngularVelocityStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new AngularVelocityStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->X());
                serializer.Deserialize(q.value(8), c->Y());
                serializer.Deserialize(q.value(9), c->Z());
                serializer.Deserialize(q.value(10), c->Rms());
                serializer.Deserialize(q.value(11), c->Flags());
                serializer.Deserialize(q.value(12), c->Cs());
                return (Message*)c;
            };
        
        auto queryInertialMeasurementsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `accelerations`, `angularVelocities`, `cs` FROM `msg_InertialMeasurements`");
        auto handlerInertialMeasurementsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new InertialMeasurementsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Accelerations());
                serializer.Deserialize(q.value(7), c->AngularVelocities());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryAccMagStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `accelerations`, `induction`, `magnitude`, `temperature`, `calibrated`, `cs` FROM `msg_AccMag`");
        auto handlerAccMagStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new AccMagStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->Accelerations());
                serializer.Deserialize(q.value(8), c->Induction());
                serializer.Deserialize(q.value(9), c->Magnitude());
                serializer.Deserialize(q.value(10), c->Temperature());
                serializer.Deserialize(q.value(11), c->Calibrated());
                serializer.Deserialize(q.value(12), c->Cs());
                return (Message*)c;
            };
        
        auto queryExtEventStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `ms`, `ns`, `timeScale`, `cs` FROM `msg_ExtEvent`");
        auto handlerExtEventStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new ExtEventStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Ms());
                serializer.Deserialize(q.value(7), c->Ns());
                serializer.Deserialize(q.value(8), c->TimeScale());
                serializer.Deserialize(q.value(9), c->Cs());
                return (Message*)c;
            };
        
        auto queryPPSOffsetStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `cs` FROM `msg_PPSOffset`");
        auto handlerPPSOffsetStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PPSOffsetStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Offs());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvTimeOffsAtPPSStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `offs`, `timeScale`, `cs` FROM `msg_RcvTimeOffsAtPPS`");
        auto handlerRcvTimeOffsAtPPSStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvTimeOffsAtPPSStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Offs());
                serializer.Deserialize(q.value(7), c->TimeScale());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryHeadAndPitchStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `heading`, `pitch`, `solType`, `cs` FROM `msg_HeadAndPitch`");
        auto handlerHeadAndPitchStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new HeadAndPitchStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Heading());
                serializer.Deserialize(q.value(7), c->Pitch());
                serializer.Deserialize(q.value(8), c->SolType());
                serializer.Deserialize(q.value(9), c->Cs());
                return (Message*)c;
            };
        
        auto queryRefEpochStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `crc16` FROM `msg_RefEpoch`");
        auto handlerRefEpochStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RefEpochStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Sample());
                serializer.Deserialize(q.value(7), c->Scale());
                serializer.Deserialize(q.value(8), c->Reftime());
                serializer.Deserialize(q.value(9), c->Crc16());
                return (Message*)c;
            };
        
        auto queryRawMeasStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `scale`, `reftime`, `clock`, `flags`, `svd`, `crc16` FROM `msg_RawMeas`");
        auto handlerRawMeasStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RawMeasStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryPosVelVectorStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `delta`, `word1`, `word2`, `word3`, `word4`, `word5`, `word6`, `word7`, `word8`, `word9`, `crc16` FROM `msg_PosVelVector`");
        auto handlerPosVelVectorStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new PosVelVectorStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Sample());
                serializer.Deserialize(q.value(7), c->Delta());
                serializer.Deserialize(q.value(8), c->Word1());
                serializer.Deserialize(q.value(9), c->Word2());
                serializer.Deserialize(q.value(10), c->Word3());
                serializer.Deserialize(q.value(11), c->Word4());
                serializer.Deserialize(q.value(12), c->Word5());
                serializer.Deserialize(q.value(13), c->Word6());
                serializer.Deserialize(q.value(14), c->Word7());
                serializer.Deserialize(q.value(15), c->Word8());
                serializer.Deserialize(q.value(16), c->Word9());
                serializer.Deserialize(q.value(17), c->Crc16());
                return (Message*)c;
            };
        
        auto queryClockOffsetsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `sample`, `reserved`, `Offs`, `crc16` FROM `msg_ClockOffsets`");
        auto handlerClockOffsetsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new ClockOffsetsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Sample());
                serializer.Deserialize(q.value(7), c->Reserved());
                c->Offs() = this->deserializeAndGetCustomTypes<ClkOffsCustomType>(ECustomTypeId::ClkOffs, q.value(8));
                serializer.Deserialize(q.value(9), c->Crc16());
                return (Message*)c;
            };
        
        auto queryREStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `reply` FROM `msg_RE`");
        auto handlerREStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new REStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Reply());
                return (Message*)c;
            };
        
        auto queryERStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `error` FROM `msg_ER`");
        auto handlerERStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new ERStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Error());
                return (Message*)c;
            };
        
        auto queryIonoParams0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tot`, `wn`, `alpha0`, `alpha1`, `alpha2`, `alpha3`, `beta0`, `beta1`, `beta2`, `beta3`, `cs` FROM `msg_IonoParams0`");
        auto handlerIonoParams0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IonoParams0StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Tot());
                serializer.Deserialize(q.value(7), c->Wn());
                serializer.Deserialize(q.value(8), c->Alpha0());
                serializer.Deserialize(q.value(9), c->Alpha1());
                serializer.Deserialize(q.value(10), c->Alpha2());
                serializer.Deserialize(q.value(11), c->Alpha3());
                serializer.Deserialize(q.value(12), c->Beta0());
                serializer.Deserialize(q.value(13), c->Beta1());
                serializer.Deserialize(q.value(14), c->Beta2());
                serializer.Deserialize(q.value(15), c->Beta3());
                serializer.Deserialize(q.value(16), c->Cs());
                return (Message*)c;
            };
        
        auto queryQzssIonoParamsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `par` FROM `msg_QzssIonoParams`");
        auto handlerQzssIonoParamsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new QzssIonoParamsStdMessage(id, bodySize);
                c->Par() = this->extractCustomType<IonoParams1CustomType>(ECustomTypeId::IonoParams1, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto queryBeiDouIonoParamsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `par` FROM `msg_BeiDouIonoParams`");
        auto handlerBeiDouIonoParamsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new BeiDouIonoParamsStdMessage(id, bodySize);
                c->Par() = this->extractCustomType<IonoParams1CustomType>(ECustomTypeId::IonoParams1, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto queryIrnssIonoParamsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `par` FROM `msg_IrnssIonoParams`");
        auto handlerIrnssIonoParamsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new IrnssIonoParamsStdMessage(id, bodySize);
                c->Par() = this->extractCustomType<IonoParams1CustomType>(ECustomTypeId::IonoParams1, q.value(6).toInt());
                return (Message*)c;
            };
        
        auto queryEventStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `time`, `type`, `data`, `cs` FROM `msg_Event`");
        auto handlerEventStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new EventStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Time());
                serializer.Deserialize(q.value(7), c->Type());
                serializer.Deserialize(q.value(8), c->Data());
                serializer.Deserialize(q.value(9), c->Cs());
                return (Message*)c;
            };
        
        auto queryLatencyStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `lt`, `cs` FROM `msg_Latency`");
        auto handlerLatencyStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new LatencyStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Lt());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryWrapperStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `id_sugar`, `data`, `cs` FROM `msg_Wrapper`");
        auto handlerWrapperStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new WrapperStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->IdField());
                serializer.Deserialize(q.value(7), c->Data());
                serializer.Deserialize(q.value(8), c->Cs());
                return (Message*)c;
            };
        
        auto queryParamsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `params` FROM `msg_Params`");
        auto handlerParamsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new ParamsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Params());
                return (Message*)c;
            };
        
        auto queryLoggingHistoryStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `svsCount`, `targetStream`, `issue`, `bitsCount`, `lastBitTime`, `uids`, `pad`, `hist` FROM `msg_LoggingHistory`");
        auto handlerLoggingHistoryStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new LoggingHistoryStdMessage(id, bodySize);
                
                /*throw Common::NotImplementedException();*/
                return (Message*)c;
            };
        
        auto queryBaseInfoStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `x`, `y`, `z`, `id_sugar`, `solType`, `cs` FROM `msg_BaseInfo`");
        auto handlerBaseInfoStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new BaseInfoStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->X());
                serializer.Deserialize(q.value(7), c->Y());
                serializer.Deserialize(q.value(8), c->Z());
                serializer.Deserialize(q.value(9), c->IdField());
                serializer.Deserialize(q.value(10), c->SolType());
                serializer.Deserialize(q.value(11), c->Cs());
                return (Message*)c;
            };
        
        auto querySecurity0StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `cs` FROM `msg_Security0`");
        auto handlerSecurity0StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new Security0StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Data());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto querySecurity1StdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `data`, `crc16` FROM `msg_Security1`");
        auto handlerSecurity1StdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new Security1StdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Data());
                serializer.Deserialize(q.value(7), c->Crc16());
                return (Message*)c;
            };
        
        auto queryTrackingTimeStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `tt`, `cs` FROM `msg_TrackingTime`");
        auto handlerTrackingTimeStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new TrackingTimeStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Tt());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        auto queryRcvOscOffsStdMessage = QString("SELECT `id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, `val`, `cs` FROM `msg_RcvOscOffs`");
        auto handlerRcvOscOffsStdMessage = [&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)
            {
                auto c = new RcvOscOffsStdMessage(id, bodySize);
                serializer.Deserialize(q.value(6), c->Val());
                serializer.Deserialize(q.value(7), c->Cs());
                return (Message*)c;
            };
        
        _msgQueries.insert(EMessageId::FileId, queryFileIdStdMessage);
        _msgHandlers.insert(EMessageId::FileId, handlerFileIdStdMessage);
        _msgQueries.insert(EMessageId::MsgFmt, queryMsgFmtStdMessage);
        _msgHandlers.insert(EMessageId::MsgFmt, handlerMsgFmtStdMessage);
        _msgQueries.insert(EMessageId::RcvTime, queryRcvTimeStdMessage);
        _msgHandlers.insert(EMessageId::RcvTime, handlerRcvTimeStdMessage);
        _msgQueries.insert(EMessageId::EpochTime, queryEpochTimeStdMessage);
        _msgHandlers.insert(EMessageId::EpochTime, handlerEpochTimeStdMessage);
        _msgQueries.insert(EMessageId::RcvDate, queryRcvDateStdMessage);
        _msgHandlers.insert(EMessageId::RcvDate, handlerRcvDateStdMessage);
        _msgQueries.insert(EMessageId::RcvTimeOffset, queryRcvTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvTimeOffset, handlerRcvTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::RcvTimeOffsetDot, queryRcvTimeOffsetDotStdMessage);
        _msgHandlers.insert(EMessageId::RcvTimeOffsetDot, handlerRcvTimeOffsetDotStdMessage);
        _msgQueries.insert(EMessageId::RcvTimeAccuracy, queryRcvTimeAccuracyStdMessage);
        _msgHandlers.insert(EMessageId::RcvTimeAccuracy, handlerRcvTimeAccuracyStdMessage);
        _msgQueries.insert(EMessageId::GPSTime, queryGPSTimeStdMessage);
        _msgHandlers.insert(EMessageId::GPSTime, handlerGPSTimeStdMessage);
        _msgQueries.insert(EMessageId::RcvGPSTimeOffset, queryRcvGPSTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvGPSTimeOffset, handlerRcvGPSTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::GLOTime, queryGLOTimeStdMessage);
        _msgHandlers.insert(EMessageId::GLOTime, handlerGLOTimeStdMessage);
        _msgQueries.insert(EMessageId::RcvGLOTimeOffset, queryRcvGLOTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvGLOTimeOffset, handlerRcvGLOTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::RcvGALTimeOffset, queryRcvGALTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvGALTimeOffset, handlerRcvGALTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::RcvSBASTimeOffset, queryRcvSBASTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvSBASTimeOffset, handlerRcvSBASTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::RcvQZSSTimeOffset, queryRcvQZSSTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvQZSSTimeOffset, handlerRcvQZSSTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::RcvBeiDouTimeOffset, queryRcvBeiDouTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvBeiDouTimeOffset, handlerRcvBeiDouTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::RcvIrnssTimeOffset, queryRcvIrnssTimeOffsetStdMessage);
        _msgHandlers.insert(EMessageId::RcvIrnssTimeOffset, handlerRcvIrnssTimeOffsetStdMessage);
        _msgQueries.insert(EMessageId::GpsUtcParam, queryGpsUtcParamStdMessage);
        _msgHandlers.insert(EMessageId::GpsUtcParam, handlerGpsUtcParamStdMessage);
        _msgQueries.insert(EMessageId::SbasUtcParam, querySbasUtcParamStdMessage);
        _msgHandlers.insert(EMessageId::SbasUtcParam, handlerSbasUtcParamStdMessage);
        _msgQueries.insert(EMessageId::GalUtcGpsParam, queryGalUtcGpsParamStdMessage);
        _msgHandlers.insert(EMessageId::GalUtcGpsParam, handlerGalUtcGpsParamStdMessage);
        _msgQueries.insert(EMessageId::QzssUtcParam, queryQzssUtcParamStdMessage);
        _msgHandlers.insert(EMessageId::QzssUtcParam, handlerQzssUtcParamStdMessage);
        _msgQueries.insert(EMessageId::BeiDouUtcParam, queryBeiDouUtcParamStdMessage);
        _msgHandlers.insert(EMessageId::BeiDouUtcParam, handlerBeiDouUtcParamStdMessage);
        _msgQueries.insert(EMessageId::IrnssUtcParam, queryIrnssUtcParamStdMessage);
        _msgHandlers.insert(EMessageId::IrnssUtcParam, handlerIrnssUtcParamStdMessage);
        _msgQueries.insert(EMessageId::GloUtcGpsParam, queryGloUtcGpsParamStdMessage);
        _msgHandlers.insert(EMessageId::GloUtcGpsParam, handlerGloUtcGpsParamStdMessage);
        _msgQueries.insert(EMessageId::SolutionTime, querySolutionTimeStdMessage);
        _msgHandlers.insert(EMessageId::SolutionTime, handlerSolutionTimeStdMessage);
        _msgQueries.insert(EMessageId::Pos, queryPosStdMessage);
        _msgHandlers.insert(EMessageId::Pos, handlerPosStdMessage);
        _msgQueries.insert(EMessageId::SpecificCrtPos0, querySpecificCrtPos0StdMessage);
        _msgHandlers.insert(EMessageId::SpecificCrtPos0, handlerSpecificCrtPos0StdMessage);
        _msgQueries.insert(EMessageId::Vel, queryVelStdMessage);
        _msgHandlers.insert(EMessageId::Vel, handlerVelStdMessage);
        _msgQueries.insert(EMessageId::PosVel, queryPosVelStdMessage);
        _msgHandlers.insert(EMessageId::PosVel, handlerPosVelStdMessage);
        _msgQueries.insert(EMessageId::GeoPos, queryGeoPosStdMessage);
        _msgHandlers.insert(EMessageId::GeoPos, handlerGeoPosStdMessage);
        _msgQueries.insert(EMessageId::SpecificCrtPos1, querySpecificCrtPos1StdMessage);
        _msgHandlers.insert(EMessageId::SpecificCrtPos1, handlerSpecificCrtPos1StdMessage);
        _msgQueries.insert(EMessageId::GeoVel, queryGeoVelStdMessage);
        _msgHandlers.insert(EMessageId::GeoVel, handlerGeoVelStdMessage);
        _msgQueries.insert(EMessageId::Rms, queryRmsStdMessage);
        _msgHandlers.insert(EMessageId::Rms, handlerRmsStdMessage);
        _msgQueries.insert(EMessageId::LocalPlanePos, queryLocalPlanePosStdMessage);
        _msgHandlers.insert(EMessageId::LocalPlanePos, handlerLocalPlanePosStdMessage);
        _msgQueries.insert(EMessageId::RSLocalPlanePos, queryRSLocalPlanePosStdMessage);
        _msgHandlers.insert(EMessageId::RSLocalPlanePos, handlerRSLocalPlanePosStdMessage);
        _msgQueries.insert(EMessageId::Dops, queryDopsStdMessage);
        _msgHandlers.insert(EMessageId::Dops, handlerDopsStdMessage);
        _msgQueries.insert(EMessageId::PosCov, queryPosCovStdMessage);
        _msgHandlers.insert(EMessageId::PosCov, handlerPosCovStdMessage);
        _msgQueries.insert(EMessageId::VelCov, queryVelCovStdMessage);
        _msgHandlers.insert(EMessageId::VelCov, handlerVelCovStdMessage);
        _msgQueries.insert(EMessageId::Baseline, queryBaselineStdMessage);
        _msgHandlers.insert(EMessageId::Baseline, handlerBaselineStdMessage);
        _msgQueries.insert(EMessageId::Baselines, queryBaselinesStdMessage);
        _msgHandlers.insert(EMessageId::Baselines, handlerBaselinesStdMessage);
        _msgQueries.insert(EMessageId::FullRotationMatrix, queryFullRotationMatrixStdMessage);
        _msgHandlers.insert(EMessageId::FullRotationMatrix, handlerFullRotationMatrixStdMessage);
        _msgQueries.insert(EMessageId::PosStat, queryPosStatStdMessage);
        _msgHandlers.insert(EMessageId::PosStat, handlerPosStatStdMessage);
        _msgQueries.insert(EMessageId::PosCompTime, queryPosCompTimeStdMessage);
        _msgHandlers.insert(EMessageId::PosCompTime, handlerPosCompTimeStdMessage);
        _msgQueries.insert(EMessageId::ExtSatIndex, queryExtSatIndexStdMessage);
        _msgHandlers.insert(EMessageId::ExtSatIndex, handlerExtSatIndexStdMessage);
        _msgQueries.insert(EMessageId::SatIndex, querySatIndexStdMessage);
        _msgHandlers.insert(EMessageId::SatIndex, handlerSatIndexStdMessage);
        _msgQueries.insert(EMessageId::AntName, queryAntNameStdMessage);
        _msgHandlers.insert(EMessageId::AntName, handlerAntNameStdMessage);
        _msgQueries.insert(EMessageId::SatNumbers, querySatNumbersStdMessage);
        _msgHandlers.insert(EMessageId::SatNumbers, handlerSatNumbersStdMessage);
        _msgQueries.insert(EMessageId::SatElevation, querySatElevationStdMessage);
        _msgHandlers.insert(EMessageId::SatElevation, handlerSatElevationStdMessage);
        _msgQueries.insert(EMessageId::SatAzimuth, querySatAzimuthStdMessage);
        _msgHandlers.insert(EMessageId::SatAzimuth, handlerSatAzimuthStdMessage);
        _msgQueries.insert(EMessageId::PR, queryPRStdMessage);
        _msgHandlers.insert(EMessageId::PR, handlerPRStdMessage);
        _msgQueries.insert(EMessageId::SPR, querySPRStdMessage);
        _msgHandlers.insert(EMessageId::SPR, handlerSPRStdMessage);
        _msgQueries.insert(EMessageId::RPR, queryRPRStdMessage);
        _msgHandlers.insert(EMessageId::RPR, handlerRPRStdMessage);
        _msgQueries.insert(EMessageId::SRPR, querySRPRStdMessage);
        _msgHandlers.insert(EMessageId::SRPR, handlerSRPRStdMessage);
        _msgQueries.insert(EMessageId::PrCorr, queryPrCorrStdMessage);
        _msgHandlers.insert(EMessageId::PrCorr, handlerPrCorrStdMessage);
        _msgQueries.insert(EMessageId::SC, querySCStdMessage);
        _msgHandlers.insert(EMessageId::SC, handlerSCStdMessage);
        _msgQueries.insert(EMessageId::SS, querySSStdMessage);
        _msgHandlers.insert(EMessageId::SS, handlerSSStdMessage);
        _msgQueries.insert(EMessageId::CP, queryCPStdMessage);
        _msgHandlers.insert(EMessageId::CP, handlerCPStdMessage);
        _msgQueries.insert(EMessageId::SCP, querySCPStdMessage);
        _msgHandlers.insert(EMessageId::SCP, handlerSCPStdMessage);
        _msgQueries.insert(EMessageId::RCPRC0, queryRCPRC0StdMessage);
        _msgHandlers.insert(EMessageId::RCPRC0, handlerRCPRC0StdMessage);
        _msgQueries.insert(EMessageId::RCPRc1, queryRCPRc1StdMessage);
        _msgHandlers.insert(EMessageId::RCPRc1, handlerRCPRc1StdMessage);
        _msgQueries.insert(EMessageId::PhCorr, queryPhCorrStdMessage);
        _msgHandlers.insert(EMessageId::PhCorr, handlerPhCorrStdMessage);
        _msgQueries.insert(EMessageId::DP, queryDPStdMessage);
        _msgHandlers.insert(EMessageId::DP, handlerDPStdMessage);
        _msgQueries.insert(EMessageId::SRDP, querySRDPStdMessage);
        _msgHandlers.insert(EMessageId::SRDP, handlerSRDPStdMessage);
        _msgQueries.insert(EMessageId::CNR, queryCNRStdMessage);
        _msgHandlers.insert(EMessageId::CNR, handlerCNRStdMessage);
        _msgQueries.insert(EMessageId::CNR4, queryCNR4StdMessage);
        _msgHandlers.insert(EMessageId::CNR4, handlerCNR4StdMessage);
        _msgQueries.insert(EMessageId::CNR2560, queryCNR2560StdMessage);
        _msgHandlers.insert(EMessageId::CNR2560, handlerCNR2560StdMessage);
        _msgQueries.insert(EMessageId::CNR2561, queryCNR2561StdMessage);
        _msgHandlers.insert(EMessageId::CNR2561, handlerCNR2561StdMessage);
        _msgQueries.insert(EMessageId::Flags, queryFlagsStdMessage);
        _msgHandlers.insert(EMessageId::Flags, handlerFlagsStdMessage);
        _msgQueries.insert(EMessageId::IAmp, queryIAmpStdMessage);
        _msgHandlers.insert(EMessageId::IAmp, handlerIAmpStdMessage);
        _msgQueries.insert(EMessageId::QAmp, queryQAmpStdMessage);
        _msgHandlers.insert(EMessageId::QAmp, handlerQAmpStdMessage);
        _msgQueries.insert(EMessageId::TrackingTimeCA, queryTrackingTimeCAStdMessage);
        _msgHandlers.insert(EMessageId::TrackingTimeCA, handlerTrackingTimeCAStdMessage);
        _msgQueries.insert(EMessageId::NavStatus, queryNavStatusStdMessage);
        _msgHandlers.insert(EMessageId::NavStatus, handlerNavStatusStdMessage);
        _msgQueries.insert(EMessageId::IonoDelay, queryIonoDelayStdMessage);
        _msgHandlers.insert(EMessageId::IonoDelay, handlerIonoDelayStdMessage);
        _msgQueries.insert(EMessageId::RangeResidual, queryRangeResidualStdMessage);
        _msgHandlers.insert(EMessageId::RangeResidual, handlerRangeResidualStdMessage);
        _msgQueries.insert(EMessageId::VelocityResidual, queryVelocityResidualStdMessage);
        _msgHandlers.insert(EMessageId::VelocityResidual, handlerVelocityResidualStdMessage);
        _msgQueries.insert(EMessageId::GPSAlm0, queryGPSAlm0StdMessage);
        _msgHandlers.insert(EMessageId::GPSAlm0, handlerGPSAlm0StdMessage);
        _msgQueries.insert(EMessageId::GALAlm, queryGALAlmStdMessage);
        _msgHandlers.insert(EMessageId::GALAlm, handlerGALAlmStdMessage);
        _msgQueries.insert(EMessageId::QZSSAlm, queryQZSSAlmStdMessage);
        _msgHandlers.insert(EMessageId::QZSSAlm, handlerQZSSAlmStdMessage);
        _msgQueries.insert(EMessageId::BeiDouAlm, queryBeiDouAlmStdMessage);
        _msgHandlers.insert(EMessageId::BeiDouAlm, handlerBeiDouAlmStdMessage);
        _msgQueries.insert(EMessageId::IrnssAlm, queryIrnssAlmStdMessage);
        _msgHandlers.insert(EMessageId::IrnssAlm, handlerIrnssAlmStdMessage);
        _msgQueries.insert(EMessageId::GLOAlmanac, queryGLOAlmanacStdMessage);
        _msgHandlers.insert(EMessageId::GLOAlmanac, handlerGLOAlmanacStdMessage);
        _msgQueries.insert(EMessageId::SBASAlmanac, querySBASAlmanacStdMessage);
        _msgHandlers.insert(EMessageId::SBASAlmanac, handlerSBASAlmanacStdMessage);
        _msgQueries.insert(EMessageId::GPSEphemeris0, queryGPSEphemeris0StdMessage);
        _msgHandlers.insert(EMessageId::GPSEphemeris0, handlerGPSEphemeris0StdMessage);
        _msgQueries.insert(EMessageId::GALEphemeris, queryGALEphemerisStdMessage);
        _msgHandlers.insert(EMessageId::GALEphemeris, handlerGALEphemerisStdMessage);
        _msgQueries.insert(EMessageId::QZSSEphemeris, queryQZSSEphemerisStdMessage);
        _msgHandlers.insert(EMessageId::QZSSEphemeris, handlerQZSSEphemerisStdMessage);
        _msgQueries.insert(EMessageId::BeiDouEphemeris, queryBeiDouEphemerisStdMessage);
        _msgHandlers.insert(EMessageId::BeiDouEphemeris, handlerBeiDouEphemerisStdMessage);
        _msgQueries.insert(EMessageId::GLOEphemeris, queryGLOEphemerisStdMessage);
        _msgHandlers.insert(EMessageId::GLOEphemeris, handlerGLOEphemerisStdMessage);
        _msgQueries.insert(EMessageId::SBASEhemeris, querySBASEhemerisStdMessage);
        _msgHandlers.insert(EMessageId::SBASEhemeris, handlerSBASEhemerisStdMessage);
        _msgQueries.insert(EMessageId::IrnssEphemeris, queryIrnssEphemerisStdMessage);
        _msgHandlers.insert(EMessageId::IrnssEphemeris, handlerIrnssEphemerisStdMessage);
        _msgQueries.insert(EMessageId::GpsRawNavData0, queryGpsRawNavData0StdMessage);
        _msgHandlers.insert(EMessageId::GpsRawNavData0, handlerGpsRawNavData0StdMessage);
        _msgQueries.insert(EMessageId::QzssRawNavData, queryQzssRawNavDataStdMessage);
        _msgHandlers.insert(EMessageId::QzssRawNavData, handlerQzssRawNavDataStdMessage);
        _msgQueries.insert(EMessageId::GloRawNavData, queryGloRawNavDataStdMessage);
        _msgHandlers.insert(EMessageId::GloRawNavData, handlerGloRawNavDataStdMessage);
        _msgQueries.insert(EMessageId::SbasRawNavData, querySbasRawNavDataStdMessage);
        _msgHandlers.insert(EMessageId::SbasRawNavData, handlerSbasRawNavDataStdMessage);
        _msgQueries.insert(EMessageId::GalRawNavData, queryGalRawNavDataStdMessage);
        _msgHandlers.insert(EMessageId::GalRawNavData, handlerGalRawNavDataStdMessage);
        _msgQueries.insert(EMessageId::CompRawNavData, queryCompRawNavDataStdMessage);
        _msgHandlers.insert(EMessageId::CompRawNavData, handlerCompRawNavDataStdMessage);
        _msgQueries.insert(EMessageId::IrnssRawNavData, queryIrnssRawNavDataStdMessage);
        _msgHandlers.insert(EMessageId::IrnssRawNavData, handlerIrnssRawNavDataStdMessage);
        _msgQueries.insert(EMessageId::GpsNavData0, queryGpsNavData0StdMessage);
        _msgHandlers.insert(EMessageId::GpsNavData0, handlerGpsNavData0StdMessage);
        _msgQueries.insert(EMessageId::QzssNavData, queryQzssNavDataStdMessage);
        _msgHandlers.insert(EMessageId::QzssNavData, handlerQzssNavDataStdMessage);
        _msgQueries.insert(EMessageId::GloNavData, queryGloNavDataStdMessage);
        _msgHandlers.insert(EMessageId::GloNavData, handlerGloNavDataStdMessage);
        _msgQueries.insert(EMessageId::Spectrum0, querySpectrum0StdMessage);
        _msgHandlers.insert(EMessageId::Spectrum0, handlerSpectrum0StdMessage);
        _msgQueries.insert(EMessageId::Spectrum1, querySpectrum1StdMessage);
        _msgHandlers.insert(EMessageId::Spectrum1, handlerSpectrum1StdMessage);
        _msgQueries.insert(EMessageId::MDMSpectrum, queryMDMSpectrumStdMessage);
        _msgHandlers.insert(EMessageId::MDMSpectrum, handlerMDMSpectrumStdMessage);
        _msgQueries.insert(EMessageId::SvDelays, querySvDelaysStdMessage);
        _msgHandlers.insert(EMessageId::SvDelays, handlerSvDelaysStdMessage);
        _msgQueries.insert(EMessageId::CalBandsDelay, queryCalBandsDelayStdMessage);
        _msgHandlers.insert(EMessageId::CalBandsDelay, handlerCalBandsDelayStdMessage);
        _msgQueries.insert(EMessageId::RotationMatrix, queryRotationMatrixStdMessage);
        _msgHandlers.insert(EMessageId::RotationMatrix, handlerRotationMatrixStdMessage);
        _msgQueries.insert(EMessageId::RotationMatrixAndVectors, queryRotationMatrixAndVectorsStdMessage);
        _msgHandlers.insert(EMessageId::RotationMatrixAndVectors, handlerRotationMatrixAndVectorsStdMessage);
        _msgQueries.insert(EMessageId::RotationAngles, queryRotationAnglesStdMessage);
        _msgHandlers.insert(EMessageId::RotationAngles, handlerRotationAnglesStdMessage);
        _msgQueries.insert(EMessageId::AngularVelocity, queryAngularVelocityStdMessage);
        _msgHandlers.insert(EMessageId::AngularVelocity, handlerAngularVelocityStdMessage);
        _msgQueries.insert(EMessageId::InertialMeasurements, queryInertialMeasurementsStdMessage);
        _msgHandlers.insert(EMessageId::InertialMeasurements, handlerInertialMeasurementsStdMessage);
        _msgQueries.insert(EMessageId::AccMag, queryAccMagStdMessage);
        _msgHandlers.insert(EMessageId::AccMag, handlerAccMagStdMessage);
        _msgQueries.insert(EMessageId::ExtEvent, queryExtEventStdMessage);
        _msgHandlers.insert(EMessageId::ExtEvent, handlerExtEventStdMessage);
        _msgQueries.insert(EMessageId::PPSOffset, queryPPSOffsetStdMessage);
        _msgHandlers.insert(EMessageId::PPSOffset, handlerPPSOffsetStdMessage);
        _msgQueries.insert(EMessageId::RcvTimeOffsAtPPS, queryRcvTimeOffsAtPPSStdMessage);
        _msgHandlers.insert(EMessageId::RcvTimeOffsAtPPS, handlerRcvTimeOffsAtPPSStdMessage);
        _msgQueries.insert(EMessageId::HeadAndPitch, queryHeadAndPitchStdMessage);
        _msgHandlers.insert(EMessageId::HeadAndPitch, handlerHeadAndPitchStdMessage);
        _msgQueries.insert(EMessageId::RefEpoch, queryRefEpochStdMessage);
        _msgHandlers.insert(EMessageId::RefEpoch, handlerRefEpochStdMessage);
        _msgQueries.insert(EMessageId::RawMeas, queryRawMeasStdMessage);
        _msgHandlers.insert(EMessageId::RawMeas, handlerRawMeasStdMessage);
        _msgQueries.insert(EMessageId::PosVelVector, queryPosVelVectorStdMessage);
        _msgHandlers.insert(EMessageId::PosVelVector, handlerPosVelVectorStdMessage);
        _msgQueries.insert(EMessageId::ClockOffsets, queryClockOffsetsStdMessage);
        _msgHandlers.insert(EMessageId::ClockOffsets, handlerClockOffsetsStdMessage);
        _msgQueries.insert(EMessageId::RE, queryREStdMessage);
        _msgHandlers.insert(EMessageId::RE, handlerREStdMessage);
        _msgQueries.insert(EMessageId::ER, queryERStdMessage);
        _msgHandlers.insert(EMessageId::ER, handlerERStdMessage);
        _msgQueries.insert(EMessageId::IonoParams0, queryIonoParams0StdMessage);
        _msgHandlers.insert(EMessageId::IonoParams0, handlerIonoParams0StdMessage);
        _msgQueries.insert(EMessageId::QzssIonoParams, queryQzssIonoParamsStdMessage);
        _msgHandlers.insert(EMessageId::QzssIonoParams, handlerQzssIonoParamsStdMessage);
        _msgQueries.insert(EMessageId::BeiDouIonoParams, queryBeiDouIonoParamsStdMessage);
        _msgHandlers.insert(EMessageId::BeiDouIonoParams, handlerBeiDouIonoParamsStdMessage);
        _msgQueries.insert(EMessageId::IrnssIonoParams, queryIrnssIonoParamsStdMessage);
        _msgHandlers.insert(EMessageId::IrnssIonoParams, handlerIrnssIonoParamsStdMessage);
        _msgQueries.insert(EMessageId::Event, queryEventStdMessage);
        _msgHandlers.insert(EMessageId::Event, handlerEventStdMessage);
        _msgQueries.insert(EMessageId::Latency, queryLatencyStdMessage);
        _msgHandlers.insert(EMessageId::Latency, handlerLatencyStdMessage);
        _msgQueries.insert(EMessageId::Wrapper, queryWrapperStdMessage);
        _msgHandlers.insert(EMessageId::Wrapper, handlerWrapperStdMessage);
        _msgQueries.insert(EMessageId::Params, queryParamsStdMessage);
        _msgHandlers.insert(EMessageId::Params, handlerParamsStdMessage);
        _msgQueries.insert(EMessageId::LoggingHistory, queryLoggingHistoryStdMessage);
        _msgHandlers.insert(EMessageId::LoggingHistory, handlerLoggingHistoryStdMessage);
        _msgQueries.insert(EMessageId::BaseInfo, queryBaseInfoStdMessage);
        _msgHandlers.insert(EMessageId::BaseInfo, handlerBaseInfoStdMessage);
        _msgQueries.insert(EMessageId::Security0, querySecurity0StdMessage);
        _msgHandlers.insert(EMessageId::Security0, handlerSecurity0StdMessage);
        _msgQueries.insert(EMessageId::Security1, querySecurity1StdMessage);
        _msgHandlers.insert(EMessageId::Security1, handlerSecurity1StdMessage);
        _msgQueries.insert(EMessageId::TrackingTime, queryTrackingTimeStdMessage);
        _msgHandlers.insert(EMessageId::TrackingTime, handlerTrackingTimeStdMessage);
        _msgQueries.insert(EMessageId::RcvOscOffs, queryRcvOscOffsStdMessage);
        _msgHandlers.insert(EMessageId::RcvOscOffs, handlerRcvOscOffsStdMessage);
    }
}
