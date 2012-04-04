#ifndef WrapperStdMessage_h__
#define WrapperStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class WrapperStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(WrapperStdMessage);

        WrapperStdMessage(const char* p_message, int p_length);
        WrapperStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Wrapper; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Source identifier
        const Types::u1& IdField() const { return _idField; }
        Types::u1& IdField() { return _idField; }

        // Data from the source
        const std::vector<Types::u1>& Data() const { return _data; }
        std::vector<Types::u1>& Data() { return _data; }

        // Checksum formatted as hexadecimal
        const std::string& Cs() const { return _cs; }
        std::string& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _idField;
        std::vector<Types::u1> _data;
        std::string _cs;
    };
}

#endif // WrapperStdMessage_h__
