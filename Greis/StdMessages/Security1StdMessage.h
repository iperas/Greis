#ifndef Security1StdMessage_h__
#define Security1StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class Security1StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(Security1StdMessage);

        Security1StdMessage(const char* p_message, int p_length);
        Security1StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Security1; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Opaque data
        const std::vector<Types::u1>& Data() const { return _data; }
        std::vector<Types::u1>& Data() { return _data; }

        // 16-bit CRC
        const Types::u2& Crc16() const { return _crc16; }
        Types::u2& Crc16() { return _crc16; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u1> _data;
        Types::u2 _crc16;
    };
}

#endif // Security1StdMessage_h__
