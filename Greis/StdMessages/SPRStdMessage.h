#ifndef SPRStdMessage_h__
#define SPRStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SPRStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SPRStdMessage);

        SPRStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // (PR[s] - Asys) * 1011
        const std::vector<Types::i4>& Spr() const { return _spr; }
        std::vector<Types::i4>& Spr() { return _spr; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i4> _spr;
        Types::u1 _cs;
    };
}

#endif // SPRStdMessage_h__
