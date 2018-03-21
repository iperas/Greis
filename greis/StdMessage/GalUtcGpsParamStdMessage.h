#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

#include "greis/CustomType/UtcOffsCustomType.h"

namespace Greis
{
    class GalUtcGpsParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GalUtcGpsParamStdMessage);

        GalUtcGpsParamStdMessage(const char* p_message, int p_length);
        GalUtcGpsParamStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GalUtcGpsParam; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GALILEO to UTC time offset parameters// GALILEO to GPS time offset parametersf4 a0g; // Constant term of time offset [s] 
        const UtcOffsCustomType::UniquePtr_t& Utc() const { return _utc; }
        UtcOffsCustomType::UniquePtr_t& Utc() { return _utc; }

        // Rate of time offset [s/s] 
        const Types::f4& A1g() const { return _a1g; }
        Types::f4& A1g() { return _a1g; }

        // Reference time of week 
        const Types::u4& T0g() const { return _t0g; }
        Types::u4& T0g() { return _t0g; }

        // Reference week number 
        const Types::u2& Wn0g() const { return _wn0g; }
        Types::u2& Wn0g() { return _wn0g; }

        // Flags of data availability [bitfield]
        // 0 - GGTO availability 
        // 1…15 - reserved 
        const Types::u2& Flags() const { return _flags; }
        Types::u2& Flags() { return _flags; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        UtcOffsCustomType::UniquePtr_t _utc;
        Types::f4 _a1g;
        Types::u4 _t0g;
        Types::u2 _wn0g;
        Types::u2 _flags;
        Types::u1 _cs;
    };
}
