#ifndef SkyPeek_h__
#define SkyPeek_h__

#include <QtCore/QDateTime>
#include <vector>
#include <array>
#include <cmath>
#include "greis/Message.h"
#include "greis/StdMessage/SatAzimuthStdMessage.h"
#include "greis/StdMessage/SatElevationStdMessage.h"
#include "greis/StdMessage/SatIndexStdMessage.h"
#include "greis/StdMessage/SCPStdMessage.h"
#include "greis/StdMessage/CPStdMessage.h"
#include "greis/StdMessage/PRStdMessage.h"
#include "greis/StdMessage/RCPRc1StdMessage.h"
#include "greis/StdMessage/RCPRC0StdMessage.h"
#include "greis/StdMessage/RPRStdMessage.h"
#include "greis/StdMessage/SCPStdMessage.h"
#include "greis/StdMessage/SPRStdMessage.h"
#include "greis/StdMessage/SRPRStdMessage.h"
#include "greis/StdMessage/ExtSatIndexStdMessage.h"
#include "greis/StdMessage/RcvTimeStdMessage.h"
#include "greis/StdMessage/RcvDateStdMessage.h"
#include "common/Logger.h"

namespace Greis
{
    class SkyPeek
    {
    public:
        enum Signals {
            caL1, pL1, pL2, caL2, L5, L1C
        };
        enum Systems {
            Unused, NAVSTAR, GLONASS, SBAS, GALILEO, QZSS, BeiDou, IRNSS
        };
        struct ESIdx
        {
            uint SSID;
            int SVID;
        };
        struct SV
        {
        public:
            uint USI;
            ESIdx ESI;
            uint Azimuth;
            int Elevation;
            std::array<double,6> Pseudorange;
            std::array<double,6> CarrierPhase;
            std::array<double,6> CarrierFrequency;
            double pr_ref;
            bool pr_ref_use_rx;
            float Ksys;
            float Asys;
        };

        QHash<uint,SV> SVs;

        QHash<uint,SV> pSVs; //Previous

        SMART_PTR_T(SkyPeek);

        QDateTime DateTime;

        void AddMessage(Message * msg);

        SkyPeek();
    private:

        uint revision;

        double recoverIntegerPseudoRange(int integerPseudoRange, int seq);
        double recoverRelativePseudoRange(float relativePseudoRange, int seq);
        double recoverIntegerRelativePseudoRange(int integerRelativePseudoRange, int seq);
        double recoverIntegerCarrierPhases(uint integerCarrierPhase, int seq);
        double recoverRelativeCarrierPhases(float integerRelativeCarrierPhase, int seq, int Fn);
        double recoverIntegerRelativeCarrierPhases(int integerRelativeCarrierPhase, int seq, int Fn);

        float getKsys(ESIdx ESI);
        float getAsys(ESIdx ESI);
        
        std::array<double,6> getCarrierFrequency(ESIdx ESI);

        ESIdx getESI(int USI);
        int getUSI(ESIdx ESI);

        void updateTimePart( RcvTimeStdMessage* msg )
        {
            DateTime.setTime(QTime(0, 0).addMSecs(msg->Tod()));
        }

        void updateDatePart( RcvDateStdMessage* msg ) 
        {
            DateTime.setDate(QDate(msg->Year(), msg->Month(), msg->Day()));
        }
    };
}

#endif // SkyPeek_h__
