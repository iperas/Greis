#ifndef CNRStdMessage_h__
#define CNRStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class CNRStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CNRStdMessage);

        CNRStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // C/N0 [dB*Hz]
        const std::vector<Types::u1>& Cnr() const { return _cnr; }
        std::vector<Types::u1>& Cnr() { return _cnr; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u1> _cnr;
        Types::u1 _cs;
    };
}

#endif // CNRStdMessage_h__
