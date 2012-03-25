#ifndef GreisException_h__
#define GreisException_h__

#include <QtCore/QString>
#include "ProjectBase/Exception.h"

namespace Greis
{
    class GreisException : public ProjectBase::Exception
    {
    public:
        GreisException(const QString& message) : ProjectBase::Exception(message)
        {
        }
    };
}

#endif // GreisException_h__