#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class SpecificCrtPos0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SpecificCrtPos0StdMessage);

        SpecificCrtPos0StdMessage(const char* p_message, int p_length);
        SpecificCrtPos0StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SpecificCrtPos0; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Cartesian coordinates [m] 
        const Types::f8& X() const { return _x; }
        Types::f8& X() { return _x; }

        // Cartesian coordinates [m] 
        const Types::f8& Y() const { return _y; }
        Types::f8& Y() { return _y; }

        // Cartesian coordinates [m] 
        const Types::f8& Z() const { return _z; }
        Types::f8& Z() { return _z; }

        // Position SEP [m] 
        const Types::f4& PSigma() const { return _pSigma; }
        Types::f4& PSigma() { return _pSigma; }

        // Solution type 
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Source of position
        // 0 - WGS
        // 1 - Local
        const Types::u1& System() const { return _system; }
        Types::u1& System() { return _system; }

        // Name of the coordinate reference system
        const std::string& CrsCode() const { return _crsCode; }
        std::string& CrsCode() { return _crsCode; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::f8 _x;
        Types::f8 _y;
        Types::f8 _z;
        Types::f4 _pSigma;
        Types::u1 _solType;
        Types::u1 _system;
        std::string _crsCode;
        Types::u1 _cs;
    };
}
