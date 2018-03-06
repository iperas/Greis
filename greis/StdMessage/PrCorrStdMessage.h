#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class PrCorrStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PrCorrStdMessage);

        PrCorrStdMessage(const char* p_message, int p_length);
        PrCorrStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PrCorr; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Correction [Seconds * 1e11]
        const std::vector<Types::i2>& Prc() const { return _prc; }
        std::vector<Types::i2>& Prc() { return _prc; }

        // Mode
        const Types::u1& Mode() const { return _mode; }
        Types::u1& Mode() { return _mode; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::i2> _prc;
        Types::u1 _mode;
        Types::u1 _cs;
    };
}
