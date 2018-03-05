#pragma once

#include <QtCore/QByteArray>
#include "Greis/CustomType.h"
#include "Greis/ECustomTypeId.h"

namespace Greis
{
    class BandDelayCustomType : public CustomType
    {
    public:
        SMART_PTR_T(BandDelayCustomType);

        BandDelayCustomType(const char* p_message, int p_length);
        BandDelayCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::BandDelay; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // 0-gps1, 1-gps2, 2-gps5, 3-glo1, 4-glo2, 5-glo3
        const Types::i1& Band() const { return _band; }
        Types::i1& Band() { return _band; }

        // 0-ca, 1-p
        const Types::i1& Signal() const { return _signal; }
        Types::i1& Signal() { return _signal; }

        // Code delay [s] 
        const Types::f4& Delay() const { return _delay; }
        Types::f4& Delay() { return _delay; }
    private:
        int _size;
        bool _isCorrect;

        Types::i1 _band;
        Types::i1 _signal;
        Types::f4 _delay;
    };
}
