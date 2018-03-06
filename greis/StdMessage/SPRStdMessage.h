#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class SPRStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SPRStdMessage);

        SPRStdMessage(const char* p_message, int p_length);
        SPRStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SPR; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // (PR[s] - Asys) / Ksys 
        const std::vector<Types::i4>& Spr() const { return _spr; }
        std::vector<Types::i4>& Spr() { return _spr; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::i4> _spr;
        Types::u1 _cs;
    };
}
