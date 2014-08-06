#ifndef ClockOffsetsStdMessage_h__
#define ClockOffsetsStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/ClkOffsCustomType.h"

namespace Greis
{
    class ClockOffsetsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(ClockOffsetsStdMessage);

        ClockOffsetsStdMessage(const char* p_message, int p_length);
        ClockOffsetsStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::ClockOffsets; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Sample number []
        const Types::u2& Sample() const { return _sample; }
        Types::u2& Sample() { return _sample; }

        // Reserved for future extensions
        const Types::u2& Reserved() const { return _reserved; }
        Types::u2& Reserved() { return _reserved; }

        // Size of data block, in bytes, that corresponds to
        // the given satellite system (8 bytes currently);
        const Types::u1& RecSize() const { return _recSize; }
        Types::u1& RecSize() { return _recSize; }

        // Clock offsets (see below).
        // ‘N’ can be derived from the following expression:
        // N = (len - 7) / recSize, where ‘len’ is message body
        // length taken from message header
        const std::vector<ClkOffsCustomType::UniquePtr_t>& Offs() const { return _Offs; }
        std::vector<ClkOffsCustomType::UniquePtr_t>& Offs() { return _Offs; }

        // 16-bit CRC
        const Types::u2& Crc16() const { return _crc16; }
        Types::u2& Crc16() { return _crc16; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u2 _sample;
        Types::u2 _reserved;
        Types::u1 _recSize;
        std::vector<ClkOffsCustomType::UniquePtr_t> _Offs;
        Types::u2 _crc16;
    };
}

#endif // ClockOffsetsStdMessage_h__
