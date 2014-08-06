#ifndef GpsUtcParamStdMessage_h__
#define GpsUtcParamStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomType/UtcOffsCustomType.h"

namespace Greis
{
    class GpsUtcParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GpsUtcParamStdMessage);

        GpsUtcParamStdMessage(const char* p_message, int p_length);
        GpsUtcParamStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GpsUtcParam; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GPS UTC time offset parameters
        const UtcOffsCustomType::UniquePtr_t& Utc() const { return _utc; }
        UtcOffsCustomType::UniquePtr_t& Utc() { return _utc; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        UtcOffsCustomType::UniquePtr_t _utc;
        Types::u1 _cs;
    };
}

#endif // GpsUtcParamStdMessage_h__
