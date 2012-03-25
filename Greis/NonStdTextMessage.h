#ifndef NonStdTextMessage_h__
#define NonStdTextMessage_h__

#include "Message.h"

namespace Greis
{
    class NonStdTextMessage : public Message
    {
    public:
        SMART_PTR_T(NonStdTextMessage);

        // Zero-length non-standard Text Message
        NonStdTextMessage(char p_eom);

        // Non-standard Text Message
        NonStdTextMessage(char p_id, std::string p_body, char p_eom);

        virtual std::string ToString() const;
        virtual bool Validate() const;

        inline const char Id() const { return _id; }
        inline const std::string& Body() const { return _body; }
        inline const char Eom() const { return _eom; }

        inline static bool IsEom(char ch) { return ch == '\r' || ch == '\n'; }

        static const char MinIdValue = 33;
        static const char MaxIdValue = 47;
    private:
        char _id;
        std::string _body;
        char _eom;
    };
}

#endif // NonStdTextMessage_h__
