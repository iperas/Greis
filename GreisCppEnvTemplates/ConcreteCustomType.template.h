#ifndef ${ClassName}_h__
#define ${ClassName}_h__

#include "CustomType.h"
#include <QtCore/QByteArray>
#include "ECustomTypeId.h"// ${includes}

namespace Greis
{
    class ${ClassName} : public CustomType
    {
    public:
        SMART_PTR_T(${ClassName});

        ${ClassName}(const char* p_message, int p_length);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::${ECustomTypeId}; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }

        // ${ClassFieldsAccessorsStub}
    private:
        int _size;

        // ${ClassFieldsStub}
    };
}

#endif // ${ClassName}_h__
