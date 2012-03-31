#ifndef SatNumbersStdMessage_h__
#define SatNumbersStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SatNumbersStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SatNumbersStdMessage);

        SatNumbersStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GLONASS SV orbit slot number []
        const std::vector<Types::u1>& Osn() const { return _osn; }
        std::vector<Types::u1>& Osn() { return _osn; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u1> _osn;
        Types::u1 _cs;
    };
}

#endif // SatNumbersStdMessage_h__
