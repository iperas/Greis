#ifndef RPRStdMessage_h__
#define RPRStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RPRStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RPRStdMessage);

        RPRStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // PR - CA/L1 PR, [s]
        const std::vector<Types::f4>& Rpr() const { return _rpr; }
        std::vector<Types::f4>& Rpr() { return _rpr; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::f4> _rpr;
        Types::u1 _cs;
    };
}

#endif // RPRStdMessage_h__
