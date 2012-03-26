#ifndef RCPRc1StdMessage_h__
#define RCPRc1StdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class RCPRc1StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RCPRc1StdMessage);

        RCPRc1StdMessage(char* p_message, int p_length);

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

#endif // RCPRc1StdMessage_h__
