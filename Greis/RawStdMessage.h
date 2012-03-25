#ifndef RawStdMessage_h__
#define RawStdMessage_h__

#include "StdMessage.h"

namespace Greis
{
    class RawStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RawStdMessage);

        RawStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;

        virtual std::string Id() const { return std::string(&_message[0], 2); }
        virtual int BodySize() const { return _message.size() - HeadSize(); }
        virtual const char* FullMessage() const { return &_message[0]; }

    private:
        std::string toString(const std::string& tagName) const;
        std::string bodyToString() const;

        std::vector<char> _message; // Id+Len+Body
    };
}

#endif // RawStdMessage_h__
