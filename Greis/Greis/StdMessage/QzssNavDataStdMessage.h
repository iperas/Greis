#ifndef QzssNavDataStdMessage_h__
#define QzssNavDataStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/GpsNavData1CustomType.h"

namespace Greis
{
    class QzssNavDataStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(QzssNavDataStdMessage);

        QzssNavDataStdMessage(const char* p_message, int p_length);
        QzssNavDataStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::QzssNavData; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // 
        const GpsNavData1CustomType::UniquePtr_t& Data() const { return _data; }
        GpsNavData1CustomType::UniquePtr_t& Data() { return _data; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        GpsNavData1CustomType::UniquePtr_t _data;
    };
}

#endif // QzssNavDataStdMessage_h__
