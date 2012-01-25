#ifndef DatabaseException_h__
#define DatabaseException_h__

#include "Util/Exception.h"

namespace Database 
{
    class DatabaseException : public Util::Exception
    {
    public:
        DatabaseException(const QString& message) : Util::Exception(message)
        {
        }
    };
}

#endif // DatabaseException_h__