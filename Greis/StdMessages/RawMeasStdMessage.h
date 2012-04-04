#ifndef RawMeasStdMessage_h__
#define RawMeasStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/SvData2CustomType.h"

namespace Greis
{
    class RawMeasStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RawMeasStdMessage);

        RawMeasStdMessage(const char* p_message, int p_length);
        RawMeasStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RawMeas; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Sample number []
        const Types::u2& Sample() const { return _sample; }
        Types::u2& Sample() { return _sample; }

        // See [rE] for description
        const Types::u2& Scale() const { return _scale; }
        Types::u2& Scale() { return _scale; }

        // See [rE] for description
        const Types::u4& Reftime() const { return _reftime; }
        Types::u4& Reftime() { return _reftime; }

        // Clock offset:
        // 15…2: Clock offset
        // -213 /+(213-1) [125 nanoseconds]:
        // 1…0: Clock offset ID:
        // 0 – clock offset is unavailable
        // 1 – [GPS - Receiver time]
        // 2 – [GLONASS - Receiver time]
        // 3 - reserved
        const Types::i2& Clock() const { return _clock; }
        Types::i2& Clock() { return _clock; }

        // Flags [bitfield]:
        // 15…13: message version [0…7]
        // 12…8: total number of “svd” records (N)
        // 7…5: this value plus 6 makes the length
        // of the structure “Header” in bytes
        // 4…0: this value plus 10 (for “version” 0 and 1),
        // or 6 (for “version” [2…7]) makes the length
        // of the structure “SlotRec” in bytes
        const Types::u2& Flags() const { return _flags; }
        Types::u2& Flags() { return _flags; }

        // SVs data (see below)
        const std::vector<SvData2CustomType::UniquePtr_t>& Svd() const { return _svd; }
        std::vector<SvData2CustomType::UniquePtr_t>& Svd() { return _svd; }

        // 16-bit CRC
        const Types::u2& Crc16() const { return _crc16; }
        Types::u2& Crc16() { return _crc16; }
    private:
        std::string _id;
        int _bodySize;

        Types::u2 _sample;
        Types::u2 _scale;
        Types::u4 _reftime;
        Types::i2 _clock;
        Types::u2 _flags;
        std::vector<SvData2CustomType::UniquePtr_t> _svd;
        Types::u2 _crc16;
    };
}

#endif // RawMeasStdMessage_h__
