#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class FlagsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(FlagsStdMessage);

        FlagsStdMessage(const char* p_message, int p_length);
        FlagsStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Flags; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Lock Loop Flags [bitfield]
        const std::vector<Types::u2>& Flags() const { return _flags; }
        std::vector<Types::u2>& Flags() { return _flags; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::u2> _flags;
        Types::u1 _cs;
    };
}
