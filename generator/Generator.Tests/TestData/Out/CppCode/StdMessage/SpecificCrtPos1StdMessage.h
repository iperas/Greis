#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class SpecificCrtPos1StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SpecificCrtPos1StdMessage);

        SpecificCrtPos1StdMessage(const char* p_message, int p_length);
        SpecificCrtPos1StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SpecificCrtPos1; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Latitude [rad] 
        const Types::f8& Lat() const { return _lat; }
        Types::f8& Lat() { return _lat; }

        // Longitude [rad] 
        const Types::f8& Lon() const { return _lon; }
        Types::f8& Lon() { return _lon; }

        // Ellipsoidal height [m] 
        const Types::f8& Alt() const { return _alt; }
        Types::f8& Alt() { return _alt; }

        // Position SEP [m] 
        const Types::f4& PSigma() const { return _pSigma; }
        Types::f4& PSigma() { return _pSigma; }

        // Solution type 
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Coordinate system
        // 0 - WGS
        // 1 - Locala1 crsCode[5]; // Name of the coordinate reference systemu1 cs; // Checksum 
        const Types::u1& System() const { return _system; }
        Types::u1& System() { return _system; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::f8 _lat;
        Types::f8 _lon;
        Types::f8 _alt;
        Types::f4 _pSigma;
        Types::u1 _solType;
        Types::u1 _system;
    };
}
