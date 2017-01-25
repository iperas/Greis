#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

#include "Greis/CustomType/BandDelayCustomType.h"

namespace Greis
{
    class CalBandsDelayStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CalBandsDelayStdMessage);

        CalBandsDelayStdMessage(const char* p_message, int p_length);
        CalBandsDelayStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::CalBandsDelay; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ‘n’ may vary depending on receiver model
        // and calibrator data readiness
        const std::vector<BandDelayCustomType::UniquePtr_t>& D() const { return _d; }
        std::vector<BandDelayCustomType::UniquePtr_t>& D() { return _d; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<BandDelayCustomType::UniquePtr_t> _d;
        Types::u1 _cs;
    };
}
