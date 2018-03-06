#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class SolutionTimeStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SolutionTimeStdMessage);

        SolutionTimeStdMessage(const char* p_message, int p_length);
        SolutionTimeStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SolutionTime; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Solution time. Tr modulo 1 day (86400000 ms)[ms]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u4 _time;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}
