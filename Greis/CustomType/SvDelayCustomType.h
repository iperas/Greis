#pragma once

#include <QtCore/QByteArray>
#include "Greis/CustomType.h"
#include "Greis/ECustomTypeId.h"

namespace Greis
{
    class SvDelayCustomType : public CustomType
    {
    public:
        SMART_PTR_T(SvDelayCustomType);

        SvDelayCustomType(const char* p_message, int p_length);
        SvDelayCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::SvDelay; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // GLONASS FCN[-7…6]
        const Types::i1& Fcn() const { return _fcn; }
        Types::i1& Fcn() { return _fcn; }

        // Phase delay [cycles]
        const Types::f4& Phase() const { return _phase; }
        Types::f4& Phase() { return _phase; }

        // Range delay [s]
        const Types::f4& Range() const { return _range; }
        Types::f4& Range() { return _range; }
    private:
        int _size;
        bool _isCorrect;

        Types::i1 _fcn;
        Types::f4 _phase;
        Types::f4 _range;
    };
}
