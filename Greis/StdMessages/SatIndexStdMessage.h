#ifndef SatIndexStdMessage_h__
#define SatIndexStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SatIndexStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SatIndexStdMessage);

        SatIndexStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // USI array []
        const std::vector<Types::u1>& Usi() const { return _usi; }
        std::vector<Types::u1>& Usi() { return _usi; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u1> _usi;
        Types::u1 _cs;
    };
}

#endif // SatIndexStdMessage_h__
