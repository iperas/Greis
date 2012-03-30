#ifndef ${ClassName}_h__
#define ${ClassName}_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>// ${includes}

namespace Greis
{
    class ${ClassName} : public StdMessage
    {
    public:
        SMART_PTR_T(${ClassName});

        ${ClassName}(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ${ClassFieldsAccessorsStub}
    private:
        std::string _id;
        int _bodySize;

        // ${ClassFieldsStub}
    };
}

#endif // ${ClassName}_h__
