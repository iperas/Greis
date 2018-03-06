#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class DopsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(DopsStdMessage);

        DopsStdMessage(const char* p_message, int p_length);
        DopsStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Dops; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Horizontal dilution of precision (HDOP)[] 
        const Types::f4& Hdop() const { return _hdop; }
        Types::f4& Hdop() { return _hdop; }

        // Vertical dilution of precision (VDOP) [] 
        const Types::f4& Vdop() const { return _vdop; }
        Types::f4& Vdop() { return _vdop; }

        // Time dilution of precision (TDOP) []
        const Types::f4& Tdop() const { return _tdop; }
        Types::f4& Tdop() { return _tdop; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // East dilution of precision (eDOP) [] 
        const Types::f4& Edop() const { return _edop; }
        Types::f4& Edop() { return _edop; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::f4 _hdop;
        Types::f4 _vdop;
        Types::f4 _tdop;
        Types::u1 _solType;
        Types::f4 _edop;
        Types::u1 _cs;
    };
}
