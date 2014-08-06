#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class NavStatusStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(NavStatusStdMessage);

        NavStatusStdMessage(const char* p_message, int p_length);
        NavStatusStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::NavStatus; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Navigation Status
        const std::vector<Types::u1>& Ns() const { return _ns; }
        std::vector<Types::u1>& Ns() { return _ns; }

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

        std::vector<Types::u1> _ns;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}
