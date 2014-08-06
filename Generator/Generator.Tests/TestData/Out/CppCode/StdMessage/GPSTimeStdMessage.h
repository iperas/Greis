#ifndef GPSTimeStdMessage_h__
#define GPSTimeStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class GPSTimeStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GPSTimeStdMessage);

        GPSTimeStdMessage(const char* p_message, int p_length);
        GPSTimeStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GPSTime; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
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
        bool _isCorrect;

        Types::u4 _tow;
        Types::u2 _wn;
        Types::u1 _cs;
    };
}

#endif // GPSTimeStdMessage_h__
