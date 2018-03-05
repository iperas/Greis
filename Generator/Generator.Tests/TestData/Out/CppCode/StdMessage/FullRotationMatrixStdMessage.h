#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class FullRotationMatrixStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(FullRotationMatrixStdMessage);

        FullRotationMatrixStdMessage(const char* p_message, int p_length);
        FullRotationMatrixStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::FullRotationMatrix; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // components of the rotation matrix Q []
        const Types::f4& Q00() const { return _q00; }
        Types::f4& Q00() { return _q00; }

        // components of the rotation matrix Q []
        const Types::f4& Q01() const { return _q01; }
        Types::f4& Q01() { return _q01; }

        // components of the rotation matrix Q []
        const Types::f4& Q02() const { return _q02; }
        Types::f4& Q02() { return _q02; }

        // components of the rotation matrix Q []
        const Types::f4& Q10() const { return _q10; }
        Types::f4& Q10() { return _q10; }

        // components of the rotation matrix Q []
        const Types::f4& Q11() const { return _q11; }
        Types::f4& Q11() { return _q11; }

        // components of the rotation matrix Q []
        const Types::f4& Q12() const { return _q12; }
        Types::f4& Q12() { return _q12; }

        // components of the rotation matrix Q []
        const Types::f4& Q20() const { return _q20; }
        Types::f4& Q20() { return _q20; }

        // components of the rotation matrix Q []
        const Types::f4& Q21() const { return _q21; }
        Types::f4& Q21() { return _q21; }

        // components of the rotation matrix Q []
        const Types::f4& Q22() const { return _q22; }
        Types::f4& Q22() { return _q22; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::f4 _q00;
        Types::f4 _q01;
        Types::f4 _q02;
        Types::f4 _q10;
        Types::f4 _q11;
        Types::f4 _q12;
        Types::f4 _q20;
        Types::f4 _q21;
        Types::f4 _q22;
        Types::u1 _cs;
    };
}
