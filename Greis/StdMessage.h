#ifndef StdMessage_h__
#define StdMessage_h__

#include <vector>
#include "Message.h"
#include "ProjectBase/InvalidOperationException.h"

namespace Greis
{
    class StdMessage : public Message
    {
    public:
        SMART_PTR_T(StdMessage);

        StdMessage();

        virtual std::string ToString() const = 0;
        virtual bool Validate() const;

        virtual std::string Id() const = 0;
        virtual int BodySize() const = 0;
        virtual const char* FullMessage() const = 0;

        inline static int HeadSize() { return _headSize; }
        inline int FullSize() const { return HeadSize() + BodySize(); }

        static const char MinIdValue = 48;
        static const char MaxIdValue = 126;

    protected:
        static bool validateChecksum8Ascii(char* p_message, int p_length);
        static bool validateChecksum8Bin(char* p_message, int p_length);

    protected:
        static const int _headSize = 5;
    };
}

#endif // StdMessage_h__
