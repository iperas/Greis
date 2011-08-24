#ifndef GreisException_h__
#define GreisException_h__

#include <QtCore/QtCore>
#include "Common/Exceptions/Exception.h"

namespace Greis
{
    class GreisException : public Exception
    {
    public:
        GreisException(const QString& message) : Exception(message)
        {
        }
    };
}

#endif // GreisException_h__