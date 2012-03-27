#ifndef GPSTimeStdMessage_h__
#define GPSTimeStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class GPSTimeStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GPSTimeStdMessage);

        GPSTimeStdMessage(char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Time of week [ms]
        const Types::u4& Tow() const { return _tow; }
        Types::u4& Tow() { return _tow; }

        // GPS week number (modulo 1024) []
        const Types::u2& Wn() const { return _wn; }
        Types::u2& Wn() { return _wn; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u4 _tow;
        Types::u2 _wn;
        Types::u1 _cs;
    };
}

#endif // GPSTimeStdMessage_h__
