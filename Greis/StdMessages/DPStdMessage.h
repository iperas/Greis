#ifndef DPStdMessage_h__
#define DPStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class DPStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(DPStdMessage);

        DPStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // DP [Hz*10-4]
        const std::vector<Types::i4>& Dp() const { return _dp; }
        std::vector<Types::i4>& Dp() { return _dp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i4> _dp;
        Types::u1 _cs;
    };
}

#endif // DPStdMessage_h__