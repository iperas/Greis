#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

#include "Greis/CustomType/UtcOffsCustomType.h"

namespace Greis
{
    class BeiDouUtcParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(BeiDouUtcParamStdMessage);

        BeiDouUtcParamStdMessage(const char* p_message, int p_length);
        BeiDouUtcParamStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::BeiDouUtcParam; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // BeiDou UTC time offset parametersu1 cs; // Checksum 
        const UtcOffsCustomType::UniquePtr_t& Utc() const { return _utc; }
        UtcOffsCustomType::UniquePtr_t& Utc() { return _utc; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        UtcOffsCustomType::UniquePtr_t _utc;
    };
}
