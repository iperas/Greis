#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class RcvDateStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RcvDateStdMessage);

        RcvDateStdMessage(const char* p_message, int p_length);
        RcvDateStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RcvDate; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Current year [1…65534][]
        const Types::u2& Year() const { return _year; }
        Types::u2& Year() { return _year; }

        // Current month [1…12] []
        const Types::u1& Month() const { return _month; }
        Types::u1& Month() { return _month; }

        // Current day [1…31] []
        const Types::u1& Day() const { return _day; }
        Types::u1& Day() { return _day; }

        // Receiver reference time [enumerated]
        // 0 — GPS
        // 1 — UTC_USNO
        // 2 — GLONASS
        // 3 — UTC_SU
        // 4…254 — Reserved
        const Types::u1& Base() const { return _base; }
        Types::u1& Base() { return _base; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u2 _year;
        Types::u1 _month;
        Types::u1 _day;
        Types::u1 _base;
        Types::u1 _cs;
    };
}
