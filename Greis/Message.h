#ifndef Message_h__
#define Message_h__

#include <string>
#include <boost/utility.hpp>
#include "ProjectBase/SmartPtr.h"
#include "EMessageKind.h"

namespace Greis
{
    class Message : boost::noncopyable
    {
    private:
        const EMessageKind::Type _kind;
    public:
        SMART_PTR_T(Message);

        Message(EMessageKind::Type p_kind) : _kind(p_kind)
        {
        }

        virtual std::string ToString() const = 0;
        virtual bool Validate() const = 0;

        inline EMessageKind::Type Kind() const { return _kind; }
    };
}

#endif // Message_h__
