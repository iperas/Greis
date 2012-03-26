#ifndef EpochEndStdMessage_h__
#define EpochEndStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

// ${includes}

namespace Greis
{
    class EpochEndStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(EpochEndStdMessage);

        EpochEndStdMessage(char* p_message, int p_length);

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

#endif // EpochEndStdMessage_h__
