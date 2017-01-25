#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

#include "Greis/CustomType/GpsEphReqDataCustomType.h"

namespace Greis
{
    class BeiDouEphemerisStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(BeiDouEphemerisStdMessage);

        BeiDouEphemerisStdMessage(const char* p_message, int p_length);
        BeiDouEphemerisStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::BeiDouEphemeris; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GPS required data, ‘req.sv’ within the range [1…30]
        // --- BeiDou-specific data block ---
        const GpsEphReqDataCustomType::UniquePtr_t& Req() const { return _req; }
        GpsEphReqDataCustomType::UniquePtr_t& Req() { return _req; }

        // 
        const Types::f4& Tgd2() const { return _tgd2; }
        Types::f4& Tgd2() { return _tgd2; }

        // Type of navigation data
        // --- End of BeiDou-specific data block ---
        const Types::u1& NavType() const { return _navType; }
        Types::u1& NavType() { return _navType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        GpsEphReqDataCustomType::UniquePtr_t _req;
        Types::f4 _tgd2;
        Types::u1 _navType;
        Types::u1 _cs;
    };
}
