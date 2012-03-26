#ifndef GPSAlm0StdMessage_h__
#define GPSAlm0StdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class GPSAlm0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GPSAlm0StdMessage);

        GPSAlm0StdMessage(char* p_message, int p_length);

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

#endif // GPSAlm0StdMessage_h__
