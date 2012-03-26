#ifndef SCPStdMessage_h__
#define SCPStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class SCPStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SCPStdMessage);

        SCPStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
    private:
        std::string _id;
        int _bodySize;

        // ${stub}
    };
}

#endif // SCPStdMessage_h__
