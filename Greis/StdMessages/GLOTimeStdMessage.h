#ifndef GLOTimeStdMessage_h__
#define GLOTimeStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class GLOTimeStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GLOTimeStdMessage);

        GLOTimeStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GLOTime; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // time of day [ms]
        const Types::u4& Tod() const { return _tod; }
        Types::u4& Tod() { return _tod; }

        // GLONASS day number (modulo 4 years
        // starting from 1996) []
        const Types::u2& Dn() const { return _dn; }
        Types::u2& Dn() { return _dn; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u4 _tod;
        Types::u2 _dn;
        Types::u1 _cs;
    };
}

#endif // GLOTimeStdMessage_h__
