#include <QtCore/QDateTime>
#include <vector>
#include "greis/Message.h"
#include "extras/SkyPeek.h"

using namespace Common;

namespace Greis
{
	SkyPeek::ESIdx SkyPeek::getESI(int USI)
	{
		ESIdx ESI;
		if (1<=USI<=37){ // NAVSTAR
			ESI.SSID=SkyPeek::Systems::NAVSTAR; ESI.SVID=USI;
		} else if (38<=USI<=69) { // GLONASS
			ESI.SSID=SkyPeek::Systems::GLONASS; ESI.SVID=USI-45;
		} else if (70) { // GLONASS Unknown FCN
			ESI.SSID=SkyPeek::Systems::GLONASS; ESI.SVID=127; 
		} else if (71<=USI<=119) { // GALILEO
			ESI.SSID=SkyPeek::Systems::GALILEO; ESI.SVID=USI-70;
		} else if (120<=USI<=142) { // SBAS
			ESI.SSID=SkyPeek::Systems::SBAS; ESI.SVID=USI;
		} else if (193<=USI<=197) { // QZSS
			ESI.SSID=SkyPeek::Systems::QZSS; ESI.SVID=USI;
		} else if (211<=USI<=247) { // BeiDou
			ESI.SSID=SkyPeek::Systems::BeiDou; ESI.SVID=USI-210;
		} else {
			ESI.SSID=0;
			ESI.SVID=0;
		}
		return ESI;
	}
	int SkyPeek::getUSI(SkyPeek::ESIdx ESI)
	{
		switch (ESI.SSID)
		{
			case Systems::NAVSTAR:
				return ESI.SVID;
				break;
			case Systems::GLONASS:
				if (ESI.SVID<127) return ESI.SVID+45; else return 70;
				break;
			case Systems::GALILEO:
				return ESI.SVID+70;
				break;
			case Systems::SBAS:
				return ESI.SVID;
				break;
			case Systems::QZSS:
				return ESI.SVID;
				break;
			case Systems::BeiDou:
				return ESI.SVID+210;
				break;
			case Systems::IRNSS:
				return 0.105;
				break;
			default:
				return 0;
				break;

		}

	}

	float SkyPeek::getAsys(SkyPeek::ESIdx ESI)
	{
		switch (ESI.SSID)
		{
			case Systems::NAVSTAR:
				return 0.075;
				break;
			case Systems::GLONASS:
				return 0.075;
				break;
			case Systems::GALILEO:
				return 0.085;
				break;
			case Systems::SBAS:
				return 0.125;
				break;
			case Systems::QZSS:
				return 0.125;
				break;
			case Systems::BeiDou:
				return 0.105;
				break;
			case Systems::IRNSS:
				return 0.105;
				break;
			default:
				return 0;
				break;

		}
	}
	float SkyPeek::getKsys(SkyPeek::ESIdx ESI)
	{
		switch (ESI.SSID)
		{
			case Systems::NAVSTAR:
				return 1e-11;
				break;
			case Systems::GLONASS:
				return 1e-11;
				break;
			case Systems::GALILEO:
				return 2e-11;
				break;
			case Systems::SBAS:
				return 1e-11;
				break;
			case Systems::QZSS:
				return 2e-11;
				break;
			case Systems::BeiDou:
				return 2e-11;
				break;
			case Systems::IRNSS:
				return 2e-11;
				break;
			default:
				return 0;
				break;

		}
	}
	std::array<double,6> SkyPeek::getCarrierFrequency(ESIdx ESI)
	{
		switch (ESI.SSID)
		{
			case Systems::NAVSTAR:
				return std::array<double,6> {1575.42,1575.42,1227.60,1227.60,1176.45,1575.42};
			break;
			case Systems::GLONASS:
				return std::array<double,6> {1602+ESI.SVID*0.5625
											,1602+ESI.SVID*0.5625
											,1246+ESI.SVID*0.4375
											,1246+ESI.SVID*0.4375
											,1202.025,0.0};
			break;
			case Systems::SBAS:
				return std::array<double,6> {1575.42,0.0,0.0,0.0,1176.45,0.0};
			break;
			case Systems::GALILEO:
				return std::array<double,6> {1575.42,1191.795,1207.14,1278.75,1176.45,0.0};
			break;
			case Systems::QZSS:
				return std::array<double,6> {1575.42,1575.42,1278.75,1227.60,1176.45,1575.42};
			break;
			case Systems::BeiDou:
				return std::array<double,6> {1561.098,1589.742,1207.14,1268.52,1176.45,1575.42};
			break;
			case Systems::IRNSS:
				return std::array<double,6> {0.0,0.0,0.0,0.0,1176.45,0.0};
			break;
			default:
				return std::array<double,6> {0.0,0.0,0.0,0.0,0.0,0.0};

		}
	}
	double SkyPeek::recoverIntegerPseudoRange(int integerPseudoRange, int seq)
	{
		double PR;
		PR = integerPseudoRange*SVs[seq].Ksys+SVs[seq].Asys;
		return PR;
	}
	double SkyPeek::recoverRelativePseudoRange(float relativePseudoRange, int seq)
	{
		double PR;
		PR = relativePseudoRange + SVs[seq].pr_ref;
		return PR;
	}
	double SkyPeek::recoverIntegerRelativePseudoRange(int integerRelativePseudoRange, int seq)
	{
		double PR;
		PR = (integerRelativePseudoRange * 1e-11) + 2e-7 + SVs[seq].pr_ref;
		return PR;
	}
	double SkyPeek::recoverIntegerCarrierPhases(uint integerCarrierPhase, int seq)
	{
		double CP;
		CP = integerCarrierPhase / 1024.0;
		return CP;
	}
	double SkyPeek::recoverRelativeCarrierPhases(float relativeCarrierPhase, int seq, int Fn)
	{
		double CP;
		CP = (relativeCarrierPhase + SVs[seq].pr_ref) * SVs[seq].CarrierFrequency[Fn];
		return CP;
	}
	double SkyPeek::recoverIntegerRelativeCarrierPhases(int integerRelativeCarrierPhase, int seq, int Fn)
	{
		double CP; 
		CP = (integerRelativeCarrierPhase*2e-40 + (SVs[seq].Asys-SVs[seq].pr_ref)*1e11) * SVs[seq].CarrierFrequency[Fn];
		return CP;
	}
	void SkyPeek::AddMessage(Message * msg)
	{
		if (msg->Kind() == EMessageKind::StdMessage)
        {
			sLogger.Trace(QString("SkyPeek: standard message"));
        	auto stdMsg = dynamic_cast<StdMessage*>(msg);
			if (stdMsg->IdNumber() == EMessageId::RcvTime)
            {
                this->updateTimePart(dynamic_cast<RcvTimeStdMessage*>(stdMsg));
            }
            else if (stdMsg->IdNumber() == EMessageId::RcvDate)
            {
                this->updateDatePart(dynamic_cast<RcvDateStdMessage*>(stdMsg));
            }
            else if (stdMsg->IdNumber() == EMessageId::SatIndex) // [SI]
            {
				sLogger.Trace(QString("SkyPeek: new [SI]"));
            	SVs.clear();
            	auto satIndexMsg = dynamic_cast<SatIndexStdMessage*>(msg);
            	auto usis = satIndexMsg->Usi();
            	for(int i=0;i<usis.size();i++){
            		SVs[i].USI = (int)usis[i];
					SVs[i].ESI = getESI(SVs[i].USI);
					SVs[i].Asys = getAsys(SVs[i].ESI);
					SVs[i].Ksys = getKsys(SVs[i].ESI);
					SVs[i].CarrierFrequency = getCarrierFrequency(SVs[i].ESI);
					if(SVs[i].ESI.SSID==0 || SVs[i].ESI.SSID>7)
					sLogger.Warn(QString("SkyPeek: unknown satellite in lock: SSID: %1, SVID: %2, USI: %3").arg(SVs[i].ESI.SSID).arg(SVs[i].ESI.SVID).arg(SVs[i].USI));
            	}
			}  else if (stdMsg->IdNumber() == EMessageId::ExtSatIndex) // [SX]
            {
				sLogger.Trace(QString("SkyPeek: new [SX]"));
            	SVs.clear();
            	auto satIndexMsg = dynamic_cast<ExtSatIndexStdMessage*>(msg);
            	for(int i=0;i<satIndexMsg->Esi().size();i++){
            		SVs[i].ESI.SSID = satIndexMsg->Esi()[i]->Ssid(); 
					SVs[i].ESI.SVID = satIndexMsg->Esi()[i]->Svid(); 
					SVs[i].Asys = getAsys(SVs[i].ESI);
					SVs[i].Ksys = getKsys(SVs[i].ESI);
					SVs[i].CarrierFrequency = getCarrierFrequency(SVs[i].ESI);
            	}
            }  else if (stdMsg->IdNumber() == EMessageId::PR) // [RX], [RC], [R1], [R2], [R3], [R5], [Rl]
            {
				sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto pRMsg = dynamic_cast<PRStdMessage*>(msg);
            	auto pRs = pRMsg->Pr();
            	if(stdMsg->Id() == "RC"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL1] = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R1"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL1] = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R2"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL2] = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R3"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL2] = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R5"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange[Signals::L5] = (double)pRs[i];
					}
				} else if (stdMsg->Id() == "Rl"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange[Signals::L1C] = (double)pRs[i];
					}
				} else if (stdMsg->Id() == "RX"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].pr_ref = std::trunc(((double)pRs[i]-SVs[i].Asys)/SVs[i].Ksys)*SVs[i].Ksys+SVs[i].Asys;
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::RPR) // [CR], [1R], [2R], [3R], [5R], [lR]
            {
            	sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto rPRMsg = dynamic_cast<RPRStdMessage*>(msg);
            	auto rPRs = rPRMsg->Rpr();	
            	if(stdMsg->Id() == "1R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL1] = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "2R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL2] = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "3R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL2] = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "5R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange[Signals::L5]= recoverRelativePseudoRange((float)rPRs[i],i);
            		}
		       	} else if (stdMsg->Id() == "CR"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL1] = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
		       	} else if (stdMsg->Id() == "LR"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange[Signals::L1C]= recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::SPR) // [rx], [rc], [r1], [r2], [r3], [r5], [rl]
            {
            	sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto sPRMsg = dynamic_cast<SPRStdMessage*>(msg);
            	auto sPRs = sPRMsg->Spr();
            	if(stdMsg->Id() == "rc"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL1] = recoverIntegerPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r1"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL1] = recoverIntegerPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r2"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL2] = recoverIntegerPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r3"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL2] = recoverIntegerPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r5"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange[Signals::L5] = recoverIntegerPseudoRange((int)sPRs[i],i);
            		}
				} else if (stdMsg->Id() == "rl"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange[Signals::L1C] = recoverIntegerPseudoRange((int)sPRs[i],i);
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::SRPR) // [cr], [1r], [2r], [3r], [5r], [lr]
            {
            	sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto sRPRMsg = dynamic_cast<SRPRStdMessage*>(msg);
            	auto sRPRs = sRPRMsg->Srpr();
				if(stdMsg->Id() == "cr"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL1] = recoverIntegerRelativePseudoRange((int)sRPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "1r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL1] = recoverIntegerRelativePseudoRange((int)sRPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "2r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange[Signals::pL2] = recoverIntegerRelativePseudoRange((int)sRPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "3r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange[Signals::caL2] = recoverIntegerRelativePseudoRange((int)sRPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "5r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange[Signals::L5] = recoverIntegerRelativePseudoRange((int)sRPRs[i],i);
            		}
				} else if (stdMsg->Id() == "lr"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange[Signals::L1C] = recoverIntegerRelativePseudoRange((int)sRPRs[i],i);
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::CP)
            {
            	sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto cPMsg = dynamic_cast<CPStdMessage*>(msg);
            	auto cPs = cPMsg->Cp();
            	if(stdMsg->Id() == "PC"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase[Signals::caL1] = (double)cPs[i];
            		}
            	} else if (stdMsg->Id() == "P1"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase[Signals::pL1] = (double)cPs[i];
            		}
            	} else if (stdMsg->Id() == "P2"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase[Signals::pL2] = (double)cPs[i];
            		}
            	} else if (stdMsg->Id() == "P3"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase[Signals::caL2] = (double)cPs[i];
            		}
				} else if (stdMsg->Id() == "P5"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase[Signals::L5] = (double)cPs[i];
            		}
				} else if (stdMsg->Id() == "Pl"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase[Signals::L1C] = (double)cPs[i];
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::SCP)
            {
				sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto sCPMsg = dynamic_cast<SCPStdMessage*>(msg);
            	auto sCPs = sCPMsg->Scp();
            	if(stdMsg->Id() == "pc"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase[Signals::caL1] = recoverIntegerCarrierPhases((uint)sCPs[i],i);
            		}
            	} else if (stdMsg->Id() == "p1"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase[Signals::pL1] = recoverIntegerCarrierPhases((uint)sCPs[i],i);
            		}
            	} else if (stdMsg->Id() == "p2"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase[Signals::pL2] = recoverIntegerCarrierPhases((uint)sCPs[i],i);
            		}
            	} else if (stdMsg->Id() == "p3"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase[Signals::caL2] = recoverIntegerCarrierPhases((uint)sCPs[i],i);
            		}
				} else if (stdMsg->Id() == "p5"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase[Signals::L5] = recoverIntegerCarrierPhases((uint)sCPs[i],i);
            		}
				} else if (stdMsg->Id() == "Pl"){
            		for(int i=0;i++;i<sCPs.size()){
            			SVs[i].CarrierPhase[Signals::L1C] = recoverIntegerCarrierPhases((uint)sCPs[i],i);
            		}
            	}
			} else if (stdMsg->IdNumber() == EMessageId::RCPRC0)
            {
				sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto rCPRC0Msg = dynamic_cast<RCPRC0StdMessage*>(msg);
            	auto rCPRC0s = rCPRC0Msg->Rcp();
           		if(stdMsg->Id() == "CP"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase[Signals::caL1] = recoverRelativeCarrierPhases((float)rCPRC0s[i],i,Signals::caL1);
            		}
            	} else if (stdMsg->Id() == "1P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase[Signals::pL1] = recoverRelativeCarrierPhases((float)rCPRC0s[i],i,Signals::pL1);
            		}
            	} else if (stdMsg->Id() == "2P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase[Signals::pL2] = recoverRelativeCarrierPhases((float)rCPRC0s[i],i,Signals::pL2);
            		}
            	} else if (stdMsg->Id() == "3P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase[Signals::caL2] = recoverRelativeCarrierPhases((float)rCPRC0s[i],i,Signals::caL2);
            		}
				} else if (stdMsg->Id() == "5P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase[Signals::L5] = recoverRelativeCarrierPhases((float)rCPRC0s[i],i,Signals::L5);
            		}
				} else if (stdMsg->Id() == "lP"){
            		for(int i=0;i++;i<rCPRC0s.size()){
            			SVs[i].CarrierPhase[Signals::L1C] = recoverRelativeCarrierPhases((float)rCPRC0s[i],i,Signals::L1C);
            		}
            	}
			} else if (stdMsg->IdNumber() == EMessageId::RCPRc1)
            {
				sLogger.Trace(QString("SkyPeek: new %1").arg(QString::fromStdString(stdMsg->Id())));
            	auto rCPRc1Msg = dynamic_cast<RCPRc1StdMessage*>(msg);
            	auto rCPRc1s = rCPRc1Msg->Rcp();
           		if(stdMsg->Id() == "cp"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase[Signals::caL1] = recoverIntegerRelativeCarrierPhases((int)rCPRc1s[i],i,Signals::caL1);
            		}
            	} else if (stdMsg->Id() == "1p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase[Signals::pL1] = recoverIntegerRelativeCarrierPhases((int)rCPRc1s[i],i,Signals::pL1);
            		}
            	} else if (stdMsg->Id() == "2p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase[Signals::pL2] = recoverIntegerRelativeCarrierPhases((int)rCPRc1s[i],i,Signals::pL2);
            		}
            	} else if (stdMsg->Id() == "3p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase[Signals::caL2] = recoverIntegerRelativeCarrierPhases((int)rCPRc1s[i],i,Signals::caL2);
            		}
				} else if (stdMsg->Id() == "5p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase[Signals::L5] = recoverIntegerRelativeCarrierPhases((int)rCPRc1s[i],i,Signals::L5);
            		}
				} else if (stdMsg->Id() == "lp"){
            		for(int i=0;i++;i<rCPRc1s.size()){
            			SVs[i].CarrierPhase[Signals::L1C] = recoverIntegerRelativeCarrierPhases((int)rCPRc1s[i],i,Signals::L1C);
            		}
            	}
			} else if (stdMsg->IdNumber() == EMessageId::SatElevation)
            {
				sLogger.Trace(QString("SkyPeek: updating EL"));
            	auto SatElevationMsg = dynamic_cast<SatElevationStdMessage*>(msg);
            	auto SatElevations = SatElevationMsg->Elev();
            	for(int i=0;i<SatElevations.size();i++){
            			SVs[i].Elevation = (int)SatElevations[i];
            	}
			} else if (stdMsg->IdNumber() == EMessageId::SatAzimuth)
            {
				sLogger.Trace(QString("SkyPeek: updating AZ"));
            	auto SatAzimuthMsg = dynamic_cast<SatAzimuthStdMessage*>(msg);
            	auto SatAzimuths = SatAzimuthMsg->Azim();
            	for(int i=0;i<SatAzimuths.size();i++){
            			SVs[i].Azimuth = (int)SatAzimuths[i] * 2;
            	}
            }

        }
	}
}