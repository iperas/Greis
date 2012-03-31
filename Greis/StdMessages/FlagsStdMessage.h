#ifndef FlagsStdMessage_h__
#define FlagsStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class FlagsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(FlagsStdMessage);

        FlagsStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Lock Loop Flags [bitfield]
        const std::vector<Types::u2>& Flags() const { return _flags; }
        std::vector<Types::u2>& Flags() { return _flags; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u2> _flags;
        Types::u1 _cs;
    };
}

#endif // FlagsStdMessage_h__
