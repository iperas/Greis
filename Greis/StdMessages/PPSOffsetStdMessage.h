#ifndef PPSOffsetStdMessage_h__
#define PPSOffsetStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class PPSOffsetStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PPSOffsetStdMessage);

        PPSOffsetStdMessage(const char* p_message, int p_length);
        PPSOffsetStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PPSOffset; }
        virtual bool Validate() const;
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
