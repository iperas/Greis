#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

#include "greis/CustomType/GpsEphReqDataCustomType.h"
#include "greis/CustomType/GpsEphOptDataCustomType.h"

namespace Greis
{
    class GPSEphemeris0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GPSEphemeris0StdMessage);

        GPSEphemeris0StdMessage(const char* p_message, int p_length);
        GPSEphemeris0StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GPSEphemeris0; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Required data
        const GpsEphReqDataCustomType::UniquePtr_t& Req() const { return _req; }
        GpsEphReqDataCustomType::UniquePtr_t& Req() { return _req; }

        // Optional data. Present when length > 123.
        const GpsEphOptDataCustomType::UniquePtr_t& Opt() const { return _opt; }
        GpsEphOptDataCustomType::UniquePtr_t& Opt() { return _opt; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        GpsEphReqDataCustomType::UniquePtr_t _req;
        GpsEphOptDataCustomType::UniquePtr_t _opt;
        Types::u1 _cs;
    };
}
