#ifndef ${ClassName}_h__
#define ${ClassName}_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"// ${includes}

namespace Greis
{
    class ${ClassName} : public StdMessage
    {
    public:
        SMART_PTR_T(${ClassName});

        ${ClassName}(const char* p_message, int p_length);
        ${ClassName}(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::${EMessageId}; }
        virtual bool Validate() const;
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
