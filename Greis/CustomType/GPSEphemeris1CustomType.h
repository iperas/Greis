#pragma once

#include <QtCore/QByteArray>
#include "Greis/CustomType.h"
#include "Greis/ECustomTypeId.h"

#include "Greis/CustomType/GpsEphReqDataCustomType.h"

namespace Greis
{
    class GPSEphemeris1CustomType : public CustomType
    {
    public:
        SMART_PTR_T(GPSEphemeris1CustomType);

        GPSEphemeris1CustomType(const char* p_message, int p_length);
        GPSEphemeris1CustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::GPSEphemeris1; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Required data
        // --- Optional data block ---
        const GpsEphReqDataCustomType::UniquePtr_t& Req() const { return _req; }
        GpsEphReqDataCustomType::UniquePtr_t& Req() { return _req; }

        // Signal type nav. data was decoded from
        const Types::u1& CNavType() const { return _cNavType; }
        Types::u1& CNavType() { return _cNavType; }

        // Time of prediction for ephemeris data
        const Types::i4& LTope() const { return _lTope; }
        Types::i4& LTope() { return _lTope; }

        // Time of prediction for clock data
        const Types::i4& LTopc() const { return _lTopc; }
        Types::i4& LTopc() { return _lTopc; }

        // Change rate in semi-major axis
        const Types::f8& DADot() const { return _dADot; }
        Types::f8& DADot() { return _dADot; }

        // Rate of mean motion
        const Types::f4& FDelnDot() const { return _fDelnDot; }
        Types::f4& FDelnDot() { return _fDelnDot; }

        // SV ephemeris URA index
        const Types::i1& CURAoe() const { return _cURAoe; }
        Types::i1& CURAoe() { return _cURAoe; }

        // SV clock URA index
        const Types::i1& CURAoc() const { return _cURAoc; }
        Types::i1& CURAoc() { return _cURAoc; }

        // SV clock URA change index
        const Types::i1& CURAoc1() const { return _cURAoc1; }
        Types::i1& CURAoc1() { return _cURAoc1; }

        // SV clock URA change rate index
        // --- End of optional data block ---
        const Types::i1& CURAoc2() const { return _cURAoc2; }
        Types::i1& CURAoc2() { return _cURAoc2; }
    private:
        int _size;
        bool _isCorrect;

        GpsEphReqDataCustomType::UniquePtr_t _req;
        Types::u1 _cNavType;
        Types::i4 _lTope;
        Types::i4 _lTopc;
        Types::f8 _dADot;
        Types::f4 _fDelnDot;
        Types::i1 _cURAoe;
        Types::i1 _cURAoc;
        Types::i1 _cURAoc1;
        Types::i1 _cURAoc2;
    };
}
