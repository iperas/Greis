#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class VelocityResidualStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(VelocityResidualStdMessage);

        VelocityResidualStdMessage(const char* p_message, int p_length);
        VelocityResidualStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::VelocityResidual; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Radial velocity residual [m] 
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
