#ifndef DataStructureException_h__
#define DataStructureException_h__

#include "Util/Exception.h"

class DataStructureException : public Exception
{
public:
    DataStructureException(const QString& message) : Exception(message)
    {
    }
};

#endif // DataStructureException_h__