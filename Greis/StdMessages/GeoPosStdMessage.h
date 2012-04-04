#ifndef GeoPosStdMessage_h__
#define GeoPosStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class GeoPosStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GeoPosStdMessage);

        GeoPosStdMessage(const char* p_message, int p_length);
        GeoPosStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GeoPos; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Latitude [rad]
        const Types::f8& Lat() const { return _lat; }
        Types::f8& Lat() { return _lat; }

        // Longitude [rad]
        const Types::f8& Lon() const { return _lon; }
        Types::f8& Lon() { return _lon; }

        // Ellipsoidal height [m]
        const Types::f8& Alt() const { return _alt; }
        Types::f8& Alt() { return _alt; }

        // Position SEP [m]
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

        Types::f8 _lat;
        Types::f8 _lon;
        Types::f8 _alt;
        Types::f4 _pSigma;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // GeoPosStdMessage_h__
