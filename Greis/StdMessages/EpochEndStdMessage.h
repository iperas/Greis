#ifndef EpochEndStdMessage_h__
#define EpochEndStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class EpochEndStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(EpochEndStdMessage);

        EpochEndStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::EpochEnd; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _cs;
    };
}

#endif // EpochEndStdMessage_h__
