#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

#include "greis/CustomType/UtcOffsCustomType.h"

namespace Greis
{
    class GpsUtcParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GpsUtcParamStdMessage);

        GpsUtcParamStdMessage(const char* p_message, int p_length);
        GpsUtcParamStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GpsUtcParam; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GPS UTC time offset parametersu1 cs; // Checksum 
        const UtcOffsCustomType::UniquePtr_t& Utc() const { return _utc; }
        UtcOffsCustomType::UniquePtr_t& Utc() { return _utc; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        UtcOffsCustomType::UniquePtr_t _utc;
    };
}
