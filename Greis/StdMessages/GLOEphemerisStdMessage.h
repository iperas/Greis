#ifndef GLOEphemerisStdMessage_h__
#define GLOEphemerisStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class GLOEphemerisStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GLOEphemerisStdMessage);

        GLOEphemerisStdMessage(char* p_message, int p_length);

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

#endif // GLOEphemerisStdMessage_h__
