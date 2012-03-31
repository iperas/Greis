#ifndef SatElevationStdMessage_h__
#define SatElevationStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class SatElevationStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SatElevationStdMessage);

        SatElevationStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Elevation angle [degrees] [-90…90)
        const std::vector<Types::i1>& Elev() const { return _elev; }
        std::vector<Types::i1>& Elev() { return _elev; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i1> _elev;
        Types::u1 _cs;
    };
}

#endif // SatElevationStdMessage_h__
