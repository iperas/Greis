#ifndef PosCompTimeStdMessage_h__
#define PosCompTimeStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class PosCompTimeStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PosCompTimeStdMessage);

        PosCompTimeStdMessage(const char* p_message, int p_length);
        PosCompTimeStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PosCompTime; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Continuous position computation time [s]
        const Types::u4& Pt() const { return _pt; }
        Types::u4& Pt() { return _pt; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u4 _pt;
        Types::u1 _cs;
    };
}

#endif // PosCompTimeStdMessage_h__
