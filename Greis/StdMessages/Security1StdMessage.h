#ifndef Security1StdMessage_h__
#define Security1StdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class Security1StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(Security1StdMessage);

        Security1StdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
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
