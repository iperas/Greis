#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class HeadAndPitchStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(HeadAndPitchStdMessage);

        HeadAndPitchStdMessage(const char* p_message, int p_length);
        HeadAndPitchStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::HeadAndPitch; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Heading of the baseline between the base and the
        // rover receiver [degrees] 
        const Types::f4& Heading() const { return _heading; }
        Types::f4& Heading() { return _heading; }

        // Pitch of the baseline between the base and the
        // rover receiver [degrees]
        const Types::f4& Pitch() const { return _pitch; }
        Types::f4& Pitch() { return _pitch; }

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

        Types::f4 _heading;
        Types::f4 _pitch;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}
