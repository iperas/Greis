#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class SRDPStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SRDPStdMessage);

        SRDPStdMessage(const char* p_message, int p_length);
        SRDPStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SRDP; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // (dp * FL1/FLn - dpCA1)[Hz*10-4]
        const std::vector<Types::i2>& Srdp() const { return _srdp; }
        std::vector<Types::i2>& Srdp() { return _srdp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::i2> _srdp;
        Types::u1 _cs;
    };
}
