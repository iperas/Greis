#ifndef SSStdMessage_h__
#define SSStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SSStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SSStdMessage);

        SSStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Smoothing correction [s*10-11]
        const std::vector<Types::i2>& Smooth() const { return _smooth; }
        std::vector<Types::i2>& Smooth() { return _smooth; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i2> _smooth;
        Types::u1 _cs;
    };
}

#endif // SSStdMessage_h__
