#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

#include "Greis/CustomType/IonoParams1CustomType.h"

namespace Greis
{
    class BeiDouIonoParamsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(BeiDouIonoParamsStdMessage);

        BeiDouIonoParamsStdMessage(const char* p_message, int p_length);
        BeiDouIonoParamsStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::BeiDouIonoParams; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // 
        const IonoParams1CustomType::UniquePtr_t& Par() const { return _par; }
        IonoParams1CustomType::UniquePtr_t& Par() { return _par; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        IonoParams1CustomType::UniquePtr_t _par;
    };
}
