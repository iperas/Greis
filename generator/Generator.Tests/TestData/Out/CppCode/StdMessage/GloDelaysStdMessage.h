#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

#include "greis/CustomType/SvDelayCustomType.h"

namespace Greis
{
    class GloDelaysStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GloDelaysStdMessage);

        GloDelaysStdMessage(const char* p_message, int p_length);
        GloDelaysStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GloDelays; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Delays
        const std::vector<SvDelayCustomType::UniquePtr_t>& Del() const { return _del; }
        std::vector<SvDelayCustomType::UniquePtr_t>& Del() { return _del; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<SvDelayCustomType::UniquePtr_t> _del;
        Types::u1 _cs;
    };
}
