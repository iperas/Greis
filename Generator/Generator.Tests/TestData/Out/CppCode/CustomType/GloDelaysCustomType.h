#pragma once

#include <QtCore/QByteArray>
#include "Greis/CustomType.h"
#include "Greis/ECustomTypeId.h"

#include "Greis/CustomType/SvDelayCustomType.h"

namespace Greis
{
    class GloDelaysCustomType : public CustomType
    {
    public:
        SMART_PTR_T(GloDelaysCustomType);

        GloDelaysCustomType(const char* p_message, int p_length);
        GloDelaysCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::GloDelays; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Delays
        const std::vector<SvDelayCustomType::UniquePtr_t>& Del() const { return _del; }
        std::vector<SvDelayCustomType::UniquePtr_t>& Del() { return _del; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        int _size;
        bool _isCorrect;

        std::vector<SvDelayCustomType::UniquePtr_t> _del;
        Types::u1 _cs;
    };
}
