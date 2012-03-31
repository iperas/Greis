#ifndef SolutionTimeStdMessage_h__
#define SolutionTimeStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SolutionTimeStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SolutionTimeStdMessage);

        SolutionTimeStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Solution time. Tr modulo 1 day (86400000 ms)[ms]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u4 _time;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // SolutionTimeStdMessage_h__