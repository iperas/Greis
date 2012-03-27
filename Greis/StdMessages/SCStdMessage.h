#ifndef SCStdMessage_h__
#define SCStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

#include "SmoothCustomType.h"

namespace Greis
{
    class SCStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SCStdMessage);

        SCStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // PR smoothing
        const std::vector<SmoothCustomType>& Smooth() const { return _smooth; }
        std::vector<SmoothCustomType>& Smooth() { return _smooth; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<SmoothCustomType> _smooth;
        Types::u1 _cs;
    };
}

#endif // SCStdMessage_h__
