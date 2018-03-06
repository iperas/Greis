#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class LocalPlanePosStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(LocalPlanePosStdMessage);

        LocalPlanePosStdMessage(const char* p_message, int p_length);
        LocalPlanePosStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::LocalPlanePos; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Northern coordinate [m] 
        const Types::f8& N() const { return _n; }
        Types::f8& N() { return _n; }

        // Eastern coordinate [m] 
        const Types::f8& E() const { return _e; }
        Types::f8& E() { return _e; }

        // Altitude above local ellipsoid [m] 
        const Types::f8& U() const { return _u; }
        Types::f8& U() { return _u; }

        // Geoid separation relatively to local ellipsoid [m] 
        const Types::f8& Sep() const { return _sep; }
        Types::f8& Sep() { return _sep; }

        // Position SEP [m]
        const Types::f4& PSigma() const { return _pSigma; }
        Types::f4& PSigma() { return _pSigma; }

        // Solution typeu1 grid; // Grid source
        // 0 - none 
        // 1 - predefined grid 
        // 2 - user defined grid 
        // 3 - result of localization 
        // 4 - grid got from external source 
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Geoid source
        // 0 - none 
        // 1 - predefined geoid 
        // 2 - user defined geoid 
        // 4 - geoid got from external source 
        const Types::u1& Geoid() const { return _geoid; }
        Types::u1& Geoid() { return _geoid; }

        // EPSG code of used projection 
        const Types::u2& Prj() const { return _prj; }
        Types::u2& Prj() { return _prj; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::f8 _n;
        Types::f8 _e;
        Types::f8 _u;
        Types::f8 _sep;
        Types::f4 _pSigma;
        Types::u1 _solType;
        Types::u1 _geoid;
        Types::u2 _prj;
        Types::u1 _cs;
    };
}
