#include <QtCore/QDateTime>
#include <vector>
#include "Message.h"
#include "SkyPeek.h"

using namespace Common;

namespace Greis
{
	float SkyPeek::getCarrierFrequency(int PRN, int Fn)
	{
		if((1<=PRN<=37 ||
			71<=PRN<=119 ||
			120<=PRN<=138))
		{
			if (Fn==1) return 1575.42;
			if (Fn==2) return 1227.60; 
			if (Fn==5) return 1176.45; 
		}
		if(38<=PRN<=69){
			if (Fn==1) return 1602+((PRN-45)*0.5625);
			if (Fn==2) return 1246+((PRN-45)*0.4375);
		}
	}
	double SkyPeek::recoverShortPseudoRange(int shortPseudoRange, int seq)
	{
		double PR; float Asys;
		if(120<=SVs[seq].USI<=138) Asys=0.115; else Asys=0.075;
		PR = shortPseudoRange*1e-11+Asys;
		return PR;
	}
	double SkyPeek::recoverRelativePseudoRange(float relativePseudoRange, int seq)
	{
		double PR;
		PR = relativePseudoRange + SVs[seq].PseudorangeC1;
		return PR;
	}
	double SkyPeek::recoverShortRelativePseudoRange(float shortRelativePseudoRange, int seq)
	{
		double PR;
		PR = (shortRelativePseudoRange * 1e-11) + 2e-7 + SVs[seq].PseudorangeC1;
		return PR;
	}
	double SkyPeek::recoverShortCarrierPhases(uint shortCarrierPhase, int seq)
	{
		double CP;
		CP = shortCarrierPhase / 1024.0;
		return CP;
	}
	double SkyPeek::recoverShortRelativeCarrierPhases(float shortRelativeCarrierPhase, int seq, int Fn)
	{
		double CP; float Fln;
		CP = (shortRelativeCarrierPhase + SVs[seq].PseudorangeC1) * getCarrierFrequency(SVs[seq].USI,Fn);
		return CP;
	}
	double SkyPeek::recoverShortRelativeCarrierPhases(int shortRelativeCarrierPhase, int seq, int Fn)
	{
		double CP; float Fln; float Asys;
		if(120<=SVs[seq].USI<=138) Asys=0.115; else Asys=0.075;
		CP = (shortRelativeCarrierPhase*2e-40 + (Asys-SVs[seq].PseudorangeC1)*1e11) * getCarrierFrequency(SVs[seq].USI,Fn);
		return CP;
	}
	void SkyPeek::AddMessage(Message * msg)
	{
		sLogger.Trace(QString("SkyPeek: new message"));
		if (msg->Kind() == EMessageKind::StdMessage)
        {
        	auto stdMsg = dynamic_cast<StdMessage*>(msg);
            if (stdMsg->IdNumber() == EMessageId::SatIndex)
            {
				sLogger.Trace(QString("SkyPeek: new SI"));
            	SVs.clear();
            	auto satIndexMsg = dynamic_cast<SatIndexStdMessage*>(msg);
            	auto usis = satIndexMsg->Usi();
            	for(int i=0;i<usis.size();i++){
            		SVs[i].USI = (int)usis[i];
            	}
            }  else if (stdMsg->IdNumber() == EMessageId::PR)
            {
            	sLogger.Trace(QString("SkyPeek: updating PR"));
            	auto pRMsg = dynamic_cast<PRStdMessage*>(msg);
            	auto pRs = pRMsg->Pr();
            	if(stdMsg->Id() == "RC"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].PseudorangeC1 = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R1"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange1 = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R2"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange2 = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R3"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].PseudorangeC2 = (double)pRs[i];
            		}
            	} else if (stdMsg->Id() == "R5"){
            		for(int i=0;i<pRs.size();i++){
            			SVs[i].Pseudorange5 = (double)pRs[i];
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::RPR)
            {
            	sLogger.Trace(QString("SkyPeek: updating PR"));
            	auto rPRMsg = dynamic_cast<RPRStdMessage*>(msg);
            	auto rPRs = rPRMsg->Rpr();	
            	if(stdMsg->Id() == "1R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange1 = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "2R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange2 = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "3R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].PseudorangeC2 = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "5R"){
            		for(int i=0;i<rPRs.size();i++){
            			SVs[i].Pseudorange5 = recoverRelativePseudoRange((float)rPRs[i],i);
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::SPR)
            {
            	sLogger.Trace(QString("SkyPeek: updating PR"));
            	auto sPRMsg = dynamic_cast<SPRStdMessage*>(msg);
            	auto sPRs = sPRMsg->Spr();
            	if(stdMsg->Id() == "rc"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].PseudorangeC1 = recoverShortPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r1"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange1 = recoverShortPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r2"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange2 = recoverShortPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r3"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].PseudorangeC2 = recoverShortPseudoRange((int)sPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "r5"){
            		for(int i=0;i<sPRs.size();i++){
            			SVs[i].Pseudorange5 = recoverShortPseudoRange((int)sPRs[i],i);
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::SRPR)
            {
            	sLogger.Trace(QString("SkyPeek: updating PR"));
            	auto sRPRMsg = dynamic_cast<SRPRStdMessage*>(msg);
            	auto sRPRs = sRPRMsg->Srpr();
            	if(stdMsg->Id() == "1r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange1 = recoverShortRelativePseudoRange((float)sRPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "2r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange2 = recoverShortRelativePseudoRange((float)sRPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "3r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].PseudorangeC2 = recoverShortRelativePseudoRange((float)sRPRs[i],i);
            		}
            	} else if (stdMsg->Id() == "5r"){
            		for(int i=0;i<sRPRs.size();i++){
            			SVs[i].Pseudorange1 = recoverShortRelativePseudoRange((float)sRPRs[i],i);
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::CP)
            {
            	sLogger.Trace(QString("SkyPeek: updating CP"));
            	auto cPMsg = dynamic_cast<CPStdMessage*>(msg);
            	auto cPs = cPMsg->Cp();
            	if(stdMsg->Id() == "PC"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhaseC1 = (double)cPs[i];
            		}
            	} else if (stdMsg->Id() == "P1"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase1 = (double)cPs[i];
            		}
            	} else if (stdMsg->Id() == "P2"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase2 = (double)cPs[i];
            		}
            	} else if (stdMsg->Id() == "P3"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhaseC2 = (double)cPs[i];
            		}
				} else if (stdMsg->Id() == "P5"){
            		for(int i=0;i++;i<cPs.size()){
            			SVs[i].CarrierPhase5 = (double)cPs[i];
            		}
            	}
            } else if (stdMsg->IdNumber() == EMessageId::SCP)
            {
				sLogger.Trace(QString("SkyPeek: updating CP"));
            	auto sCPMsg = dynamic_cast<SCPStdMessage*>(msg);
            	auto sCPs = sCPMsg->Scp();
            	if(stdMsg->Id() == "pc"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhaseC1 = recoverShortCarrierPhases((uint)sCPs[i],i);
            		}
            	} else if (stdMsg->Id() == "p1"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase1 = recoverShortCarrierPhases((uint)sCPs[i],i);
            		}
            	} else if (stdMsg->Id() == "p2"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase2 = recoverShortCarrierPhases((uint)sCPs[i],i);
            		}
            	} else if (stdMsg->Id() == "p3"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhaseC2 = recoverShortCarrierPhases((uint)sCPs[i],i);
            		}
				} else if (stdMsg->Id() == "p5"){
            		for(int i=0;i<sCPs.size();i++){
            			SVs[i].CarrierPhase5 = recoverShortCarrierPhases((uint)sCPs[i],i);
            		}
            	}
			} else if (stdMsg->IdNumber() == EMessageId::RCPRC0)
            {
				sLogger.Trace(QString("SkyPeek: updating CP"));
            	auto rCPRC0Msg = dynamic_cast<RCPRC0StdMessage*>(msg);
            	auto rCPRC0s = rCPRC0Msg->Rcp();
            	if(stdMsg->Id() == "CP"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhaseC1 = recoverShortRelativeCarrierPhases((float)rCPRC0s[i],i,1);
            		}
            	} else if (stdMsg->Id() == "1P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase1 = recoverShortRelativeCarrierPhases((float)rCPRC0s[i],i,1);
            		}
            	} else if (stdMsg->Id() == "2P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase2 = recoverShortRelativeCarrierPhases((float)rCPRC0s[i],i,2);
            		}
            	} else if (stdMsg->Id() == "3P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhaseC2 = recoverShortRelativeCarrierPhases((float)rCPRC0s[i],i,2);
            		}
				} else if (stdMsg->Id() == "5P"){
            		for(int i=0;i<rCPRC0s.size();i++){
            			SVs[i].CarrierPhase5 = recoverShortRelativeCarrierPhases((float)rCPRC0s[i],i,5);
            		}
            	}
			} else if (stdMsg->IdNumber() == EMessageId::RCPRc1)
            {
				sLogger.Trace(QString("SkyPeek: updating CP"));
            	auto rCPRc1Msg = dynamic_cast<RCPRC0StdMessage*>(msg);
            	auto rCPRc1s = rCPRc1Msg->Rcp();
            	if(stdMsg->Id() == "cp"){
            		for(int i=0;i++;i<rCPRc1s.size() ){
            			SVs[i].CarrierPhaseC1 = recoverShortRelativeCarrierPhases((int)rCPRc1s[i],i,1);
            		}
            	} else if (stdMsg->Id() == "1p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase1 = recoverShortRelativeCarrierPhases((int)rCPRc1s[i],i,1);
            		}
            	} else if (stdMsg->Id() == "2p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase2 = recoverShortRelativeCarrierPhases((int)rCPRc1s[i],i,2);
            		}
            	} else if (stdMsg->Id() == "3p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhaseC2 = recoverShortRelativeCarrierPhases((int)rCPRc1s[i],i,2);
            		}
				} else if (stdMsg->Id() == "5p"){
            		for(int i=0;i<rCPRc1s.size();i++){
            			SVs[i].CarrierPhase5 = recoverShortRelativeCarrierPhases((int)rCPRc1s[i],i,5);
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