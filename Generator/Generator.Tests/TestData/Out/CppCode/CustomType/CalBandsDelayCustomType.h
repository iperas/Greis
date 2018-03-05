#pragma once

#include <QtCore/QByteArray>
#include "Greis/CustomType.h"
#include "Greis/ECustomTypeId.h"

#include "Greis/CustomType/BandDelayCustomType.h"

namespace Greis
{
    class CalBandsDelayCustomType : public CustomType
    {
    public:
        SMART_PTR_T(CalBandsDelayCustomType);

        CalBandsDelayCustomType(const char* p_message, int p_length);
        CalBandsDelayCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::CalBandsDelay; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // n may vary depending on receiver model
        const std::vector<BandDelayCustomType::UniquePtr_t>& D() const { return _d; }
        std::vector<BandDelayCustomType::UniquePtr_t>& D() { return _d; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        int _size;
        bool _isCorrect;

        std::vector<BandDelayCustomType::UniquePtr_t> _d;
        Types::u1 _cs;
    };
}
