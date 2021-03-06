#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"// ${includes}

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
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ${ClassFieldsAccessorsStub}
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        // ${ClassFieldsStub}
    };
}
