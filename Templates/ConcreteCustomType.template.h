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
        ${ClassName}(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::${ECustomTypeId}; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // ${ClassFieldsAccessorsStub}
    private:
        int _size;
        bool _isCorrect;

        // ${ClassFieldsStub}
    };
}

#endif // ${ClassName}_h__
