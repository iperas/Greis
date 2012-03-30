#ifndef GpsUtcParamStdMessage_h__
#define GpsUtcParamStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

#include "CustomTypes/UtcOffsCustomType.h"

namespace Greis
{
    class GpsUtcParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GpsUtcParamStdMessage);

        GpsUtcParamStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
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

        UtcOffsCustomType::UniquePtr_t _utc;
        Types::u1 _cs;
    };
}

#endif // GpsUtcParamStdMessage_h__
