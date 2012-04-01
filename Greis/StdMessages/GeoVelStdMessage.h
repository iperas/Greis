#ifndef GeoVelStdMessage_h__
#define GeoVelStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class GeoVelStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GeoVelStdMessage);

        GeoVelStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GeoVel; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Northing velocity [m/s]
        const Types::f4& Lat() const { return _lat; }
        Types::f4& Lat() { return _lat; }

        // Easting velocity [m/s]
        const Types::f4& Lon() const { return _lon; }
        Types::f4& Lon() { return _lon; }

        // Height velocity [m/s]
        const Types::f4& Alt() const { return _alt; }
        Types::f4& Alt() { return _alt; }

        // Velocity SEP [m/s]
        const Types::f4& PSigma() const { return _pSigma; }
        Types::f4& PSigma() { return _pSigma; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _lat;
        Types::f4 _lon;
        Types::f4 _alt;
        Types::f4 _pSigma;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // GeoVelStdMessage_h__
