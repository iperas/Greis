#ifndef SmoothCustomType_h__
#define SmoothCustomType_h__

#include "CustomType.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SmoothCustomType : public CustomType
    {
    public:
        SMART_PTR_T(SmoothCustomType);

        SmoothCustomType(const char* p_message, int p_length);

        virtual QByteArray ToByteArray() const;
        virtual int Size() const;

        // Smoothing correction [s]
        const Types::f4& Value() const { return _value; }
        Types::f4& Value() { return _value; }

        // Smoothing interval [s]
        const Types::u2& Interval() const { return _interval; }
        Types::u2& Interval() { return _interval; }
    private:
        int _size;

        Types::f4 _value;
        Types::u2 _interval;
    };
}

#endif // SmoothCustomType_h__
