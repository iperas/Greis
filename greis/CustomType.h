#ifndef CustomType_h__
#define CustomType_h__

#include <vector>
#include <QtCore/QByteArray>
#include "GreisTypes.h"
#include "common/SmartPtr.h"
#include "GreisBinarySerializer.h"
#include "common/NotImplementedException.h"
#include "ECustomTypeId.h"

namespace Greis
{
    class CustomType 
    {
    public:
        SMART_PTR_T(CustomType);
        CustomType() {};
        CustomType(const CustomType&) = delete;
        CustomType& operator=(const CustomType&) = delete;

        virtual ECustomTypeId::Type IdNumber() const = 0;
        virtual QByteArray ToByteArray() const = 0;
        virtual int Size() const = 0;
        virtual bool IsCorrect() const { return true; }
    protected:
        static GreisBinarySerializer _serializer;
    };
}

#endif // CustomType_h__
