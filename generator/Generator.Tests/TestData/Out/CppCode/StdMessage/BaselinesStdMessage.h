#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class BaselinesStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(BaselinesStdMessage);

        BaselinesStdMessage(const char* p_message, int p_length);
        BaselinesStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Baselines; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // baseline vector M-S0 [m] 
        const std::vector<Types::f4>& Bl0() const { return _bl0; }
        std::vector<Types::f4>& Bl0() { return _bl0; }

        // baseline vector M-S1 [m] 
        const std::vector<Types::f4>& Bl1() const { return _bl1; }
        std::vector<Types::f4>& Bl1() { return _bl1; }

        // baseline vector M-S2 [m] 
        const std::vector<Types::f4>& Bl2() const { return _bl2; }
        std::vector<Types::f4>& Bl2() { return _bl2; }

        // estimated accuracies for baseline vectors [m]
        const std::vector<Types::f4>& Rms() const { return _rms; }
        std::vector<Types::f4>& Rms() { return _rms; }

        // solution types for baseline vectors
        const std::vector<Types::u1>& SolType() const { return _solType; }
        std::vector<Types::u1>& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::f4> _bl0;
        std::vector<Types::f4> _bl1;
        std::vector<Types::f4> _bl2;
        std::vector<Types::f4> _rms;
        std::vector<Types::u1> _solType;
        Types::u1 _cs;
    };
}
