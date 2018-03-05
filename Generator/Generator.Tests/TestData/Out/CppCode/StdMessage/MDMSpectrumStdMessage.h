#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class MDMSpectrumStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(MDMSpectrumStdMessage);

        MDMSpectrumStdMessage(const char* p_message, int p_length);
        MDMSpectrumStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::MDMSpectrum; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Current frequency [Hz]
        const Types::i4& Frq() const { return _frq; }
        Types::i4& Frq() { return _frq; }

        // Current signal (or noise) power [dBm]
        const Types::i4& Pwr() const { return _pwr; }
        Types::i4& Pwr() { return _pwr; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::i4 _frq;
        Types::i4 _pwr;
        Types::u1 _cs;
    };
}
