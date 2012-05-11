#ifndef Spectrum0StdMessage_h__
#define Spectrum0StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/SpecDataCustomType.h"

namespace Greis
{
    class Spectrum0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(Spectrum0StdMessage);

        Spectrum0StdMessage(const char* p_message, int p_length);
        Spectrum0StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Spectrum0; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Current frequency [Hz*104]
        const Types::i2& CurrFrq() const { return _currFrq; }
        Types::i2& CurrFrq() { return _currFrq; }

        // Frequency of the last message [Hz*104]
        const Types::i2& FinalFrq() const { return _finalFrq; }
        Types::i2& FinalFrq() { return _finalFrq; }

        // Number of spectrums in this
        const Types::u1& N() const { return _n; }
        Types::u1& N() { return _n; }

        // Number of spectrum blocks in this message
        const Types::u1& M() const { return _m; }
        Types::u1& M() { return _m; }

        // Spectrum data
        const std::vector<SpecDataCustomType::UniquePtr_t>& S() const { return _s; }
        std::vector<SpecDataCustomType::UniquePtr_t>& S() { return _s; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::i2 _currFrq;
        Types::i2 _finalFrq;
        Types::u1 _n;
        Types::u1 _m;
        std::vector<SpecDataCustomType::UniquePtr_t> _s;
        Types::u1 _cs;
    };
}

#endif // Spectrum0StdMessage_h__
