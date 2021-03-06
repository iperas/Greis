#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class SatNumbersStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SatNumbersStdMessage);

        SatNumbersStdMessage(const char* p_message, int p_length);
        SatNumbersStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SatNumbers; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GLONASS SV orbit slot number []
        const std::vector<Types::u1>& Osn() const { return _osn; }
        std::vector<Types::u1>& Osn() { return _osn; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::u1> _osn;
        Types::u1 _cs;
    };
}
