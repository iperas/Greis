#ifndef Spectrum1StdMessage_h__
#define Spectrum1StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomType/ExtSpecDataCustomType.h"

namespace Greis
{
    class Spectrum1StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(Spectrum1StdMessage);

        Spectrum1StdMessage(const char* p_message, int p_length);
        Spectrum1StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Spectrum1; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Current frequency [Hz*104]
        const Types::i2& CurrFrq() const { return _currFrq; }
        Types::i2& CurrFrq() { return _currFrq; }

        // Frequency of the last message [Hz*104]
        const Types::i2& FinalFrq() const { return _finalFrq; }
        Types::i2& FinalFrq() { return _finalFrq; }

        // Number of spectrums in this message
        const Types::u1& N() const { return _n; }
        Types::u1& N() { return _n; }

        // Number of spectrum blocks in this message
        const Types::u1& M() const { return _m; }
        Types::u1& M() { return _m; }

        // Extended spectrum data
        const std::vector<ExtSpecDataCustomType::UniquePtr_t>& S() const { return _s; }
        std::vector<ExtSpecDataCustomType::UniquePtr_t>& S() { return _s; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::i2 _currFrq;
        Types::i2 _finalFrq;
        Types::u1 _n;
        Types::u1 _m;
        std::vector<ExtSpecDataCustomType::UniquePtr_t> _s;
        Types::u1 _cs;
    };
}

#endif // Spectrum1StdMessage_h__
