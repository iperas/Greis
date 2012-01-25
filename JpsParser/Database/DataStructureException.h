#ifndef DataStructureException_h__
#define DataStructureException_h__

#include "Util/Exception.h"

namespace Database 
{
    class DataConsistencyException : public Exception
    {
    public:
        DataConsistencyException(const QString& message) : Exception(message)
        {
        }
    };
}

#endif // DataStructureException_h__