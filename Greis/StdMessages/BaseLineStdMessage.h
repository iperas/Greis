#ifndef BaseLineStdMessage_h__
#define BaseLineStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class BaseLineStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(BaseLineStdMessage);

        BaseLineStdMessage(const char* p_message, int p_length);
        BaseLineStdMessage(const std::string& p_id, int p_bodySize);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::BaseLine; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Calculated baseline vector coordinates [m]
        const Types::f8& X() const { return _x; }
        Types::f8& X() { return _x; }

        // Calculated baseline vector coordinates [m]
        const Types::f8& Y() const { return _y; }
        Types::f8& Y() { return _y; }

        // Calculated baseline vector coordinates [m]
        const Types::f8& Z() const { return _z; }
        Types::f8& Z() { return _z; }

        // Baseline Spherical Error Probable (SEP) [m]
        const Types::f4& Sigma() const { return _sigma; }
        Types::f4& Sigma() { return _sigma; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // receiver time of the baseline estimate [s]
        const Types::i4& Time() const { return _time; }
        Types::i4& Time() { return _time; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f8 _x;
        Types::f8 _y;
        Types::f8 _z;
        Types::f4 _sigma;
        Types::u1 _solType;
        Types::i4 _time;
        Types::u1 _cs;
    };
}

#endif // BaseLineStdMessage_h__
