#ifndef GALRawMessageStdMessage_h__
#define GALRawMessageStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class GALRawMessageStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GALRawMessageStdMessage);

        GALRawMessageStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV PRN number within the range [1…30]
        const Types::u1& Prn() const { return _prn; }
        Types::u1& Prn() { return _prn; }

        // Time of receiving of message [s]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Type of data:
        // 0 - GALILEO E1B(INAV)
        // 3 - GIOVE E1B
        const Types::u1& Type() const { return _type; }
        Types::u1& Type() { return _type; }

        // Length of the navigation data block ‘data’
        const Types::u1& Len() const { return _len; }
        Types::u1& Len() { return _len; }

        // Navigation data block
        const std::vector<Types::u1>& Data() const { return _data; }
        std::vector<Types::u1>& Data() { return _data; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _prn;
        Types::u4 _time;
        Types::u1 _type;
        Types::u1 _len;
        std::vector<Types::u1> _data;
        Types::u1 _cs;
    };
}

#endif // GALRawMessageStdMessage_h__
