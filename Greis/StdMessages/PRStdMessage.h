#ifndef PRStdMessage_h__
#define PRStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class PRStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PRStdMessage);

        PRStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Pseudorange, [s]
        const std::vector<Types::f8>& Pr() const { return _pr; }
        std::vector<Types::f8>& Pr() { return _pr; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::f8> _pr;
        Types::u1 _cs;
    };
}

#endif // PRStdMessage_h__
