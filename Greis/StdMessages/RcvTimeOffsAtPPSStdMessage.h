#ifndef RcvTimeOffsAtPPSStdMessage_h__
#define RcvTimeOffsAtPPSStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class RcvTimeOffsAtPPSStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RcvTimeOffsAtPPSStdMessage);

        RcvTimeOffsAtPPSStdMessage(char* p_message, int p_length);

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

#endif // RcvTimeOffsAtPPSStdMessage_h__
