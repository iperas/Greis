#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class CNR2561StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CNR2561StdMessage);

        CNR2561StdMessage(const char* p_message, int p_length);
        CNR2561StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::CNR2561; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // C/N0 [(1/256)*dB*Hz]
        const std::vector<Types::u2>& CnrX256() const { return _cnrX256; }
        std::vector<Types::u2>& CnrX256() { return _cnrX256; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::u2> _cnrX256;
        Types::u1 _cs;
    };
}
