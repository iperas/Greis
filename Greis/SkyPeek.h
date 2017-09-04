#ifndef SkyPeek_h__
#define SkyPeek_h__

#include <QtCore/QDateTime>
#include <vector>
#include "Message.h"
#include "StdMessage/SatAzimuthStdMessage.h"
#include "StdMessage/SatElevationStdMessage.h"
#include "StdMessage/SatIndexStdMessage.h"
#include "StdMessage/SCPStdMessage.h"
#include "StdMessage/CPStdMessage.h"
#include "StdMessage/PRStdMessage.h"
#include "StdMessage/RCPRc1StdMessage.h"
#include "StdMessage/RCPRC0StdMessage.h"
#include "StdMessage/RPRStdMessage.h"
#include "StdMessage/SCPStdMessage.h"
#include "StdMessage/SPRStdMessage.h"
#include "StdMessage/SRPRStdMessage.h"
#include "StdMessage/RcvTimeStdMessage.h"
#include "StdMessage/RcvDateStdMessage.h"
#include "Common/Logger.h"

namespace Greis
{
    class SkyPeek
    {
    public:
        struct SV
        {
        public:
            int USI;
            uint Azimuth;
            int Elevation;
            double PseudorangeC1;
            double PseudorangeC2; 
            double Pseudorange1; 
            double Pseudorange2;
            double Pseudorange5;
            double CarrierPhaseC1; 
            double CarrierPhaseC2; 
            double CarrierPhase1; 
            double CarrierPhase2;
            double CarrierPhase5;
        };

        QHash<uint,SV> SVs;
        double recoverShortPseudoRange(int shortPseudoRange, int seq);
        double recoverRelativePseudoRange(float relativePseudoRange, int seq);
        double recoverShortRelativePseudoRange(float shortRelativePseudoRange, int seq);
        double recoverShortCarrierPhases(uint shortCarrierPhase, int seq);
        double recoverShortRelativeCarrierPhases(float shortRelativeCarrierPhase, int seq, int Fn);
        double recoverShortRelativeCarrierPhases(int shortRelativeCarrierPhase, int seq, int Fn);


        SMART_PTR_T(SkyPeek);

        QDateTime dateTime();

        void AddMessage(Message * msg);
        float getCarrierFrequency(int, int);
    private:
        void updateTimePart( RcvTimeStdMessage* );
        void updateDatePart( RcvDateStdMessage* );
        QDateTime _dateTime;
        bool _dateIsSet;
        bool _timeIsSet;
        float getAsys(int);
        float getKsys(int);
    };
}

#endif // SkyPeek_h__
