#ifndef WaasUtcParamStdMessage_h__
#define WaasUtcParamStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

#include "UtcOffsCustomType.h"

namespace Greis
{
    class WaasUtcParamStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(WaasUtcParamStdMessage);

        WaasUtcParamStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // WAAS to UTC time offset parameters
        const UtcOffsCustomType& Utc() const { return _utc; }
        UtcOffsCustomType& Utc() { return _utc; }

        // UTC Standard Identifier[]
        const Types::i1& Utcsi() const { return _utcsi; }
        Types::i1& Utcsi() { return _utcsi; }

        // Reference time of week [s]
        const Types::u4& Tow() const { return _tow; }
        Types::u4& Tow() { return _tow; }

        // Reference week number []
        const Types::u2& Wn() const { return _wn; }
        Types::u2& Wn() { return _wn; }

        // Flags, reserved (always 0)
        const Types::u1& Flags() const { return _flags; }
        Types::u1& Flags() { return _flags; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        UtcOffsCustomType _utc;
        Types::i1 _utcsi;
        Types::u4 _tow;
        Types::u2 _wn;
        Types::u1 _flags;
        Types::u1 _cs;
    };
}

#endif // WaasUtcParamStdMessage_h__
