#ifndef Security1StdMessage_h__
#define Security1StdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class Security1StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(Security1StdMessage);

        Security1StdMessage(char* p_message, int p_length);

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

#endif // Security1StdMessage_h__
