#ifndef AntNameStdMessage_h__
#define AntNameStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class AntNameStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(AntNameStdMessage);

        AntNameStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Antenna names[a…z]
        const std::string& Name() const { return _name; }
        std::string& Name() { return _name; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::string _name;
        Types::u1 _cs;
    };
}

#endif // AntNameStdMessage_h__
