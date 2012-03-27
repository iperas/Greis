#ifndef WrapperStdMessage_h__
#define WrapperStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class WrapperStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(WrapperStdMessage);

        WrapperStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
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
