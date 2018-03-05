#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class SSStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SSStdMessage);

        SSStdMessage(const char* p_message, int p_length);
        SSStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SS; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Smoothing correction [s*10-11]
        const std::vector<Types::i2>& Smooth() const { return _smooth; }
        std::vector<Types::i2>& Smooth() { return _smooth; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::i2> _smooth;
        Types::u1 _cs;
    };
}
