#ifndef IonoParams0StdMessage_h__
#define IonoParams0StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class IonoParams0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(IonoParams0StdMessage);

        IonoParams0StdMessage(const char* p_message, int p_length);
        IonoParams0StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::IonoParams0; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Time of week [s]
        const Types::u4& Tot() const { return _tot; }
        Types::u4& Tot() { return _tot; }

        // Week number (taken from the first subframe)
        // The coefficients of a cubic equation representing
        // the amplitude of the vertical delay
        const Types::u2& Wn() const { return _wn; }
        Types::u2& Wn() { return _wn; }

        // [s]
        const Types::f4& Alpha0() const { return _alpha0; }
        Types::f4& Alpha0() { return _alpha0; }

        // [s/semicircles]
        const Types::f4& Alpha1() const { return _alpha1; }
        Types::f4& Alpha1() { return _alpha1; }

        // [s/semicircles2]
        const Types::f4& Alpha2() const { return _alpha2; }
        Types::f4& Alpha2() { return _alpha2; }

        // [s/semicircles3]
        // The coefficients of a cubic equation representing
        // the period of the model
        const Types::f4& Alpha3() const { return _alpha3; }
        Types::f4& Alpha3() { return _alpha3; }

        // [s]
        const Types::f4& Beta0() const { return _beta0; }
        Types::f4& Beta0() { return _beta0; }

        // [s/semicircles]
        const Types::f4& Beta1() const { return _beta1; }
        Types::f4& Beta1() { return _beta1; }

        // [s/semicircles2]
        const Types::f4& Beta2() const { return _beta2; }
        Types::f4& Beta2() { return _beta2; }

        // [s/semicircles3]
        const Types::f4& Beta3() const { return _beta3; }
        Types::f4& Beta3() { return _beta3; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u4 _tot;
        Types::u2 _wn;
        Types::f4 _alpha0;
        Types::f4 _alpha1;
        Types::f4 _alpha2;
        Types::f4 _alpha3;
        Types::f4 _beta0;
        Types::f4 _beta1;
        Types::f4 _beta2;
        Types::f4 _beta3;
        Types::u1 _cs;
    };
}

#endif // IonoParams0StdMessage_h__
