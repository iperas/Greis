#ifndef ClkOffsCustomType_h__
#define ClkOffsCustomType_h__

#include "CustomType.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class ClkOffsCustomType : public CustomType
    {
    public:
        SMART_PTR_T(ClkOffsCustomType);

        ClkOffsCustomType(const char* p_message, int p_length);

        virtual QByteArray ToByteArray() const;
        virtual int Size() const;

        // [bitfield]:
        // 31: reserved;
        // 30: if set, improved timing mode is turned on;
        // 29…0: clock offset [10-4 meters], bit combination
        // 0x20000000 means the clock offset is
        // unavailable or exceeds ±536870911;
        const Types::u4& Word1() const { return _word1; }
        Types::u4& Word1() { return _word1; }

        // [bitfield]:
        // 31…29: reserved;
        // 28…26: navigation system (0 - GPS, 1 - GLN);
        // 25…0: derivative of clock offset [10-4 m/s],
        // bit combination 0x2000000 means that clock
        // offset is unavailable or exceeds ±33554431;
        const Types::u4& Word2() const { return _word2; }
        Types::u4& Word2() { return _word2; }
    private:
        int _size;

        Types::u4 _word1;
        Types::u4 _word2;
    };
}

#endif // ClkOffsCustomType_h__
