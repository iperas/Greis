#ifndef SatAzimuthStdMessage_h__
#define SatAzimuthStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SatAzimuthStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SatAzimuthStdMessage);

        SatAzimuthStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Azimuth angle [degrees*2] [0…180)
        const std::vector<Types::u1>& Azim() const { return _azim; }
        std::vector<Types::u1>& Azim() { return _azim; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::u1> _azim;
        Types::u1 _cs;
    };
}

#endif // SatAzimuthStdMessage_h__
