#ifndef DatabaseException_h__
#define DatabaseException_h__

#include "Util/Exception.h"

class DatabaseException : public Exception
{
public:
    DatabaseException(const QString& message) : Exception(message)
    {
    }
};

#endif // DatabaseException_h__