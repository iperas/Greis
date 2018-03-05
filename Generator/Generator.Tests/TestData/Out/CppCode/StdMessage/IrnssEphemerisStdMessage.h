#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

#include "Greis/CustomType/GPSEphemeris1CustomType.h"

namespace Greis
{
    class IrnssEphemerisStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(IrnssEphemerisStdMessage);

        IrnssEphemerisStdMessage(const char* p_message, int p_length);
        IrnssEphemerisStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::IrnssEphemeris; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Without ‘cs’, ‘gps.sv’ within the range[1…7]
        const GPSEphemeris1CustomType::UniquePtr_t& Gps() const { return _gps; }
        GPSEphemeris1CustomType::UniquePtr_t& Gps() { return _gps; }

        // Signal type [bitfield]
        // 0 - L5 
        const Types::u1& NavType() const { return _navType; }
        Types::u1& NavType() { return _navType; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        GPSEphemeris1CustomType::UniquePtr_t _gps;
        Types::u1 _navType;
        Types::u1 _cs;
    };
}
