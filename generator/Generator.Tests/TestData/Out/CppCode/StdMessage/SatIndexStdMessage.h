#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class SatIndexStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SatIndexStdMessage);

        SatIndexStdMessage(const char* p_message, int p_length);
        SatIndexStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SatIndex; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // USI array []
        const std::vector<Types::u1>& Usi() const { return _usi; }
        std::vector<Types::u1>& Usi() { return _usi; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::u1> _usi;
        Types::u1 _cs;
    };
}
