#ifndef RefEpochStdMessage_h__
#define RefEpochStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class RefEpochStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RefEpochStdMessage);

        RefEpochStdMessage(const char* p_message, int p_length);
        RefEpochStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RefEpoch; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Sample number [dimensionless]
        const Types::u2& Sample() const { return _sample; }
        Types::u2& Sample() { return _sample; }

        // Time scale ID, leap second status and
        // week/day part of epoch representation [bitfield]
        // 15…13: time scale ID:
        // 0 – GPS, 1 – GLONASS, 2 – UTC;
        // 12…11: leap second status:
        // 0 – no leap second epoch;
        // 1 – positive leap second;
        // 2 – negative leap second;
        // 3 – leap second status is unknown;
        // this flag shows whether a leap second
        // occurred at the current epoch;
        // 10…0: week/day representation:
        // (a) if time scale ID is GPS:
        // week number [0…1023],
        // 1024 indicates unknown week number;
        // (b) if time scale ID is GLONASS:
        // day number within 4-year period [1…1461],
        // 0 indicates unknown day number
        // (c) if time scale ID is UTC:
        // day number within the year [1…366],
        // 0 indicates unknown day number;
        const Types::u2& Scale() const { return _scale; }
        Types::u2& Scale() { return _scale; }

        // Milliseconds part of epoch representation [ms]:
        // (a) if time scale ID is GPS:
        // milliseconds of GPS week;
        // (b) if time scale ID is GLONASS:
        // milliseconds of GLONASS day;
        // (c) if time scale ID is UTC,
        // milliseconds of UTC day;
        const Types::u4& Reftime() const { return _reftime; }
        Types::u4& Reftime() { return _reftime; }

        // 16-bit CRC
        const Types::u2& Crc16() const { return _crc16; }
        Types::u2& Crc16() { return _crc16; }
    private:
        std::string _id;
        int _bodySize;

        Types::u2 _sample;
        Types::u2 _scale;
        Types::u4 _reftime;
        Types::u2 _crc16;
    };
}

#endif // RefEpochStdMessage_h__
