#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class RangeResidualStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RangeResidualStdMessage);

        RangeResidualStdMessage(const char* p_message, int p_length);
        RangeResidualStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RangeResidual; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Range residual [m]
        const std::vector<Types::f4>& Res() const { return _res; }
        std::vector<Types::f4>& Res() { return _res; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::vector<Types::f4> _res;
        Types::u1 _cs;
    };
}
