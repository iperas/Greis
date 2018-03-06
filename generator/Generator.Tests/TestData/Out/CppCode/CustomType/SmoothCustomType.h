#pragma once

#include <QtCore/QByteArray>
#include "greis/CustomType.h"
#include "greis/ECustomTypeId.h"

namespace Greis
{
    class SmoothCustomType : public CustomType
    {
    public:
        SMART_PTR_T(SmoothCustomType);

        SmoothCustomType(const char* p_message, int p_length);
        SmoothCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::Smooth; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Smoothing correction [s]
        const Types::f4& Value() const { return _value; }
        Types::f4& Value() { return _value; }

        // Smoothing interval [s]
        const Types::u2& Interval() const { return _interval; }
        Types::u2& Interval() { return _interval; }
    private:
        int _size;
        bool _isCorrect;

        Types::f4 _value;
        Types::u2 _interval;
    };
}
