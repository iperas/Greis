#ifndef ERStdMessage_h__
#define ERStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class ERStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(ERStdMessage);

        ERStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Error description
        const std::string& Error() const { return _error; }
        std::string& Error() { return _error; }
    private:
        std::string _id;
        int _bodySize;

        std::string _error;
    };
}

#endif // ERStdMessage_h__
