#ifndef CNR4StdMessage_h__
#define CNR4StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class CNR4StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CNR4StdMessage);

        CNR4StdMessage(const char* p_message, int p_length);
        CNR4StdMessage(const std::string& p_id, int p_bodySize);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::CNR4; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // C/N0 [0.25*dB*Hz]
        const std::vector<Types::u1>& CnrX4() const { return _cnrX4; }
        std::vector<Types::u1>& CnrX4() { return _cnrX4; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u1> _cnrX4;
        Types::u1 _cs;
    };
}

#endif // CNR4StdMessage_h__
