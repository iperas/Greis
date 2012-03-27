#ifndef CNR4StdMessage_h__
#define CNR4StdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class CNR4StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CNR4StdMessage);

        CNR4StdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
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
