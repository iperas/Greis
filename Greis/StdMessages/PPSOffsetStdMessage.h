#ifndef PPSOffsetStdMessage_h__
#define PPSOffsetStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class PPSOffsetStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PPSOffsetStdMessage);

        PPSOffsetStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // PPS offset in nanoseconds
        const Types::f4& Offs() const { return _offs; }
        Types::f4& Offs() { return _offs; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _offs;
        Types::u1 _cs;
    };
}

#endif // PPSOffsetStdMessage_h__
