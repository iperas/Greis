#pragma once

#include <QtCore/QByteArray>
#include "Greis/CustomType.h"
#include "Greis/ECustomTypeId.h"

namespace Greis
{
    class SpecDataCustomType : public CustomType
    {
    public:
        SMART_PTR_T(SpecDataCustomType);

        SpecDataCustomType(const char* p_message, int p_length);
        SpecDataCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::SpecData; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Spectrum values for n spectra [dB*0.1]
        const std::vector<Types::i2>& Spec() const { return _spec; }
        std::vector<Types::i2>& Spec() { return _spec; }
    private:
        int _size;
        bool _isCorrect;

        std::vector<Types::i2> _spec;
    };
}
