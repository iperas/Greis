#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class PhCorrStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PhCorrStdMessage);

        PhCorrStdMessage(const char* p_message, int p_length);
        PhCorrStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PhCorr; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Correction [cycles * 1024]
        const std::vector<Types::i2>& Phc() const { return _phc; }
        std::vector<Types::i2>& Phc() { return _phc; }

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

        std::vector<Types::i2> _phc;
        Types::u1 _mode;
        Types::u1 _cs;
    };
}
