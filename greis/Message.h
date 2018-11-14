#ifndef Message_h__
#define Message_h__

#include <QtCore/QByteArray>
#include "common/SmartPtr.h"
#include "EMessageKind.h"

namespace Greis
{
    class Message
    {
    private:
        const EMessageKind::Type _kind;
    public:
        SMART_PTR_T(Message);

        explicit Message(EMessageKind::Type p_kind) : _kind(p_kind)
        {
        }

        virtual ~Message()
        {
        }

        Message(const Message&) = delete;
        Message& operator=(const Message&) = delete;

        virtual std::string ToString() const = 0;
        virtual bool Validate() const = 0;
        virtual int Size() const = 0;
        virtual QByteArray ToByteArray() const = 0;

        inline EMessageKind::Type Kind() const { return _kind; }
    };
}

#endif // Message_h__
