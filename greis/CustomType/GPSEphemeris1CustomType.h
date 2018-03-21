#pragma once

#include <QtCore/QByteArray>
#include "greis/CustomType.h"
#include "greis/ECustomTypeId.h"

#include "greis/CustomType/GpsEphReqDataCustomType.h"
#include "greis/CustomType/GpsEphOptDataCustomType.h"

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
        // --- Optional data block --
        const GpsEphReqDataCustomType::UniquePtr_t& Req() const { return _req; }
        GpsEphReqDataCustomType::UniquePtr_t& Req() { return _req; }

        // Optional data block. Present when length > 123.
        // --- End of optional data block --
        const GpsEphOptDataCustomType::UniquePtr_t& Opt() const { return _opt; }
        GpsEphOptDataCustomType::UniquePtr_t& Opt() { return _opt; }
    private:
        int _size;
        bool _isCorrect;

        GpsEphReqDataCustomType::UniquePtr_t _req;
        GpsEphOptDataCustomType::UniquePtr_t _opt;
    };
}
