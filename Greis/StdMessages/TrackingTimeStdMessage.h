#ifndef TrackingTimeStdMessage_h__
#define TrackingTimeStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class TrackingTimeStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(TrackingTimeStdMessage);

        TrackingTimeStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // tracking time [s]
        const Types::u4& Tt() const { return _tt; }
        Types::u4& Tt() { return _tt; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u4 _tt;
        Types::u1 _cs;
    };
}

#endif // TrackingTimeStdMessage_h__
