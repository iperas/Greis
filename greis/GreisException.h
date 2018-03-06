#ifndef GreisException_h__
#define GreisException_h__

#include <QtCore/QString>
#include "common/Exception.h"

namespace Greis
{
    class GreisException : public Common::Exception
    {
    public:
        GreisException(const QString& message) : Common::Exception(message)
        {
        }
    };
}

#endif // GreisException_h__