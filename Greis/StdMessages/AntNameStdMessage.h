#ifndef AntNameStdMessage_h__
#define AntNameStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class AntNameStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(AntNameStdMessage);

        AntNameStdMessage(const char* p_message, int p_length);
        AntNameStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::AntName; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
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
