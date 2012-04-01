#ifndef SlotRecCustomType_h__
#define SlotRecCustomType_h__

#include "CustomType.h"
#include <QtCore/QByteArray>
#include "ECustomTypeId.h"

namespace Greis
{
    class SlotRecCustomType : public CustomType
    {
    public:
        SMART_PTR_T(SlotRecCustomType);

        SlotRecCustomType(const char* p_message, int p_length);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::SlotRec; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }

        // SV status [bitfield], or
        // Delta pseudo-range [0.02 meters].
        // SV status [bitfield]:
        // 15…11: GLONASS slot number (for GPS SV the field
        // is undefined), [0…24], 0 - unknown
        // 10…6: Channel number [0…31], 31 - unavailable
        // 5…0: SV navigation status
        // Delta pseudo-range [0.02 meters]:
        // [full pseudo-range for given slot]-[refrange]
        const Types::i2& SvstOrDelrange() const { return _svstOrDelrange; }
        Types::i2& SvstOrDelrange() { return _svstOrDelrange; }

        // Packed data 1 [bitfield]:
        // 31…12: [carrier phase] - [refrange]
        // [-219…(219-1)] [0.0005 meters]
        // 11…9: slot ID:
        // 0 - C/A L1; 1 - P1; 2 - P2; 3 - C/A L2;
        // 4 - L5; 5,6,7 - reserved
        // 8: reserved
        // 7: signal lock loop flags are available
        // 6: lock time is available
        // 5…0: Signal-to-noise ratio [dB*Hz]
        const Types::u4& Word1() const { return _word1; }
        Types::u4& Word1() { return _word1; }

        // Signal lock loop flags (see [FC] message)
        const Types::u2& Flags() const { return _flags; }
        Types::u2& Flags() { return _flags; }

        // Packed data 2 [bitfield]:
        // 15…12: fractional part of Signal-to-noise
        // ratio [0.1 dB*Hz]
        // 11…10: reserved
        // 9…0: lock time [0.1 second]. Tracking time since
        // last loss of lock. Varies between 0 and
        // 102.3 seconds. “Gets stuck” at 102.3s after
        // the actual tracking time exceeds this value
        // (until another loss of lock occurs).
        const Types::u2& Lock() const { return _lock; }
        Types::u2& Lock() { return _lock; }

        // Packed data 3. Only present for “version” 0 [bitfield]:
        // 31…7: Doppler [-224…(224-1)], [0.001 Hz]
        // 6…0: reserved
        const Types::u4& Word2() const { return _word2; }
        Types::u4& Word2() { return _word2; }
    private:
        int _size;

        Types::i2 _svstOrDelrange;
        Types::u4 _word1;
        Types::u2 _flags;
        Types::u2 _lock;
        Types::u4 _word2;
    };
}

#endif // SlotRecCustomType_h__
