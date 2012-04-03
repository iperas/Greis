#ifndef BaseInfoStdMessage_h__
#define BaseInfoStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class BaseInfoStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(BaseInfoStdMessage);

        BaseInfoStdMessage(const char* p_message, int p_length);
        BaseInfoStdMessage(const std::string& p_id, int p_bodySize);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::BaseInfo; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ECEF coordinates [m]
        const Types::f8& X() const { return _x; }
        Types::f8& X() { return _x; }

        // ECEF coordinates [m]
        const Types::f8& Y() const { return _y; }
        Types::f8& Y() { return _y; }

        // ECEF coordinates [m]
        const Types::f8& Z() const { return _z; }
        Types::f8& Z() { return _z; }

        // Reference station ID
        const Types::u2& IdField() const { return _idField; }
        Types::u2& IdField() { return _idField; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f8 _x;
        Types::f8 _y;
        Types::f8 _z;
        Types::u2 _idField;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // BaseInfoStdMessage_h__
