#ifndef RawStdMessage_h__
#define RawStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RawStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RawStdMessage);

        RawStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return std::string(_message.data(), 2); }
        virtual int BodySize() const { return _message.size() - HeadSize(); }
        virtual QByteArray ToByteArray() const { return _message; };

    private:
        QByteArray _message; // Id+Len+Body
    };
}

#endif // RawStdMessage_h__
