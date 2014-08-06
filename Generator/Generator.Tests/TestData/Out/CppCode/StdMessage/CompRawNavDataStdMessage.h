#ifndef CompRawNavDataStdMessage_h__
#define CompRawNavDataStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class CompRawNavDataStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CompRawNavDataStdMessage);

        CompRawNavDataStdMessage(const char* p_message, int p_length);
        CompRawNavDataStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::CompRawNavData; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV PRN number
        const Types::u1& Prn() const { return _prn; }
        Types::u1& Prn() { return _prn; }

        // COMPASS Time of receiving of message [s]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Type of data: TBD
        const Types::u1& Type() const { return _type; }
        Types::u1& Type() { return _type; }

        // Length of the navigation data block ‘data’
        const Types::u1& Len() const { return _len; }
        Types::u1& Len() { return _len; }

        // Navigation data block
        const std::vector<Types::u4>& Data() const { return _data; }
        std::vector<Types::u4>& Data() { return _data; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u1 _prn;
        Types::u4 _time;
        Types::u1 _type;
        Types::u1 _len;
        std::vector<Types::u4> _data;
        Types::u1 _cs;
    };
}

#endif // CompRawNavDataStdMessage_h__
