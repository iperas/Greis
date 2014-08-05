#ifndef QzssIonoParamsStdMessage_h__
#define QzssIonoParamsStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/IonoParams1CustomType.h"

namespace Greis
{
    class QzssIonoParamsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(QzssIonoParamsStdMessage);

        QzssIonoParamsStdMessage(const char* p_message, int p_length);
        QzssIonoParamsStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::QzssIonoParams; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // 
        const IonoParams1CustomType::UniquePtr_t& Par() const { return _par; }
        IonoParams1CustomType::UniquePtr_t& Par() { return _par; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        IonoParams1CustomType::UniquePtr_t _par;
    };
}

#endif // QzssIonoParamsStdMessage_h__
