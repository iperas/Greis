#ifndef REStdMessage_h__
#define REStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class REStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(REStdMessage);

        REStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Reply
        const std::string& Reply() const { return _reply; }
        std::string& Reply() { return _reply; }
    private:
        std::string _id;
        int _bodySize;

        std::string _reply;
    };
}

#endif // REStdMessage_h__
