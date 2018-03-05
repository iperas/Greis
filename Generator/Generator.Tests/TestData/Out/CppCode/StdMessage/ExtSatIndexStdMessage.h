#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

#include "Greis/CustomType/ESICustomType.h"

namespace Greis
{
    class ExtSatIndexStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(ExtSatIndexStdMessage);

        ExtSatIndexStdMessage(const char* p_message, int p_length);
        ExtSatIndexStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::ExtSatIndex; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ESI array []
        const std::vector<ESICustomType::UniquePtr_t>& Esi() const { return _esi; }
        std::vector<ESICustomType::UniquePtr_t>& Esi() { return _esi; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<ESICustomType::UniquePtr_t> _esi;
        Types::u1 _cs;
    };
}
