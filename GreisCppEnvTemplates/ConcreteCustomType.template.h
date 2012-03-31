#ifndef ${ClassName}_h__
#define ${ClassName}_h__

#include "CustomType.h"
#include <QtCore/QByteArray>// ${includes}

namespace Greis
{
    class ${ClassName} : public CustomType
    {
    public:
        SMART_PTR_T(${ClassName});

        ${ClassName}(const char* p_message, int p_length);

        virtual QByteArray ToByteArray() const;
        virtual int Size() const;

        // ${ClassFieldsAccessorsStub}
    private:
        int _size;

        // ${ClassFieldsStub}
    };
}

#endif // ${ClassName}_h__
