#ifndef ParamsStdMessage_h__
#define ParamsStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class ParamsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(ParamsStdMessage);

        ParamsStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Parameters description
        const std::string& Params() const { return _params; }
        std::string& Params() { return _params; }

        // Checksum delimiter
        const std::string& Delim() const { return _delim; }
        std::string& Delim() { return _delim; }

        // Checksum formatted as hexadecimal
        const std::string& Cs() const { return _cs; }
        std::string& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::string _params;
        std::string _delim;
        std::string _cs;
    };
}

#endif // ParamsStdMessage_h__
