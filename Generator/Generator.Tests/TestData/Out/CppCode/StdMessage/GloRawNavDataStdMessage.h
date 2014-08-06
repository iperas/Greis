#ifndef GloRawNavDataStdMessage_h__
#define GloRawNavDataStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class GloRawNavDataStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GloRawNavDataStdMessage);

        GloRawNavDataStdMessage(const char* p_message, int p_length);
        GloRawNavDataStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GloRawNavData; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV number
        const Types::u1& Num() const { return _num; }
        Types::u1& Num() { return _num; }

        // SV frequency code number
        const Types::i1& Fcn() const { return _fcn; }
        Types::i1& Fcn() { return _fcn; }

        // GLONASS time of receiving of message [s]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Type of data:
        // 0 - L1
        // 1 - L3
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
        bool _isCorrect;

        Types::u1 _num;
        Types::i1 _fcn;
        Types::u4 _time;
        Types::u1 _type;
        Types::u1 _len;
        std::vector<Types::u1> _data;
        Types::u1 _cs;
    };
}

#endif // GloRawNavDataStdMessage_h__
