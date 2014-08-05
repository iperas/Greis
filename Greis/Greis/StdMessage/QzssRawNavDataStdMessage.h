#ifndef QzssRawNavDataStdMessage_h__
#define QzssRawNavDataStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomType/GpsRawNavData1CustomType.h"

namespace Greis
{
    class QzssRawNavDataStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(QzssRawNavDataStdMessage);

        QzssRawNavDataStdMessage(const char* p_message, int p_length);
        QzssRawNavDataStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::QzssRawNavData; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // 
        const GpsRawNavData1CustomType::UniquePtr_t& Data() const { return _data; }
        GpsRawNavData1CustomType::UniquePtr_t& Data() { return _data; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        GpsRawNavData1CustomType::UniquePtr_t _data;
    };
}

#endif // QzssRawNavDataStdMessage_h__
