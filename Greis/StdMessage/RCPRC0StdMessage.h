#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class RCPRC0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RCPRC0StdMessage);

        RCPRC0StdMessage(const char* p_message, int p_length);
        RCPRC0StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RCPRC0; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // cp / FLn - prRC [s]
        const std::vector<Types::f4>& Rcp() const { return _rcp; }
        std::vector<Types::f4>& Rcp() { return _rcp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::f4> _rcp;
        Types::u1 _cs;
    };
}
