#ifndef TrackingTimeCAStdMessage_h__
#define TrackingTimeCAStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class TrackingTimeCAStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(TrackingTimeCAStdMessage);

        TrackingTimeCAStdMessage(const char* p_message, int p_length);
        TrackingTimeCAStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::TrackingTimeCA; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // tracking time [s]
        const std::vector<Types::u2>& Tt() const { return _tt; }
        std::vector<Types::u2>& Tt() { return _tt; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u2> _tt;
        Types::u1 _cs;
    };
}

#endif // TrackingTimeCAStdMessage_h__
