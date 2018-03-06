#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class BandDelayStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(BandDelayStdMessage);

        BandDelayStdMessage(const char* p_message, int p_length);
        BandDelayStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::BandDelay; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // 0-gps1, 1-gps2, 2-gps5, 3-glo1, 4-glo2, 5-glo3
        const Types::i1& Band() const { return _band; }
        Types::i1& Band() { return _band; }

        // 0-ca, 1-p
        const Types::i1& Signal() const { return _signal; }
        Types::i1& Signal() { return _signal; }

        // Code delay [s] 
        const Types::f4& Delay() const { return _delay; }
        Types::f4& Delay() { return _delay; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::i1 _band;
        Types::i1 _signal;
        Types::f4 _delay;
    };
}
