#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

#include "greis/CustomType/UtcOffsCustomType.h"

namespace Greis
{
    class QzssUtcParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(QzssUtcParamStdMessage);

        QzssUtcParamStdMessage(const char* p_message, int p_length);
        QzssUtcParamStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::QzssUtcParam; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // QZSS UTC time offset parameters
        const UtcOffsCustomType::UniquePtr_t& Utc() const { return _utc; }
        UtcOffsCustomType::UniquePtr_t& Utc() { return _utc; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        UtcOffsCustomType::UniquePtr_t _utc;
        Types::u1 _cs;
    };
}
