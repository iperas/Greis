#ifndef HeaderCustomType_h__
#define HeaderCustomType_h__

#include "CustomType.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class HeaderCustomType : public CustomType
    {
    public:
        SMART_PTR_T(HeaderCustomType);

        HeaderCustomType(const char* p_message, int p_length);

        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }

        // Reference pseudo-range [0.02 meters]
        const Types::u4& Refrange() const { return _refrange; }
        Types::u4& Refrange() { return _refrange; }

        // USI (see [SI] message)
        const Types::u1& Usi() const { return _usi; }
        Types::u1& Usi() { return _usi; }

        // Number of slot records (M) [bitfield]:
        // 7…3: reserved
        // 2…0: number of slot records minus one (M)
        const Types::u1& Num() const { return _num; }
        Types::u1& Num() { return _num; }
    private:
        int _size;

        Types::u4 _refrange;
        Types::u1 _usi;
        Types::u1 _num;
    };
}

#endif // HeaderCustomType_h__
