#ifndef GLOAlmanacStdMessage_h__
#define GLOAlmanacStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class GLOAlmanacStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GLOAlmanacStdMessage);

        GLOAlmanacStdMessage(char* p_message, int p_length);

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

#endif // GLOAlmanacStdMessage_h__
