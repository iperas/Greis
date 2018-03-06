#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class IrnssRawNavDataStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(IrnssRawNavDataStdMessage);

        IrnssRawNavDataStdMessage(const char* p_message, int p_length);
        IrnssRawNavDataStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::IrnssRawNavData; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV PRN number 
        const Types::u1& Prn() const { return _prn; }
        Types::u1& Prn() { return _prn; }

        // IRNSS time of receiving of message [s] 
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Type of data: 
        // 0 - L5 
        const Types::u1& Type() const { return _type; }
        Types::u1& Type() { return _type; }

        // Length of navigation data block �data�u4 data[len]; // Navigation data blocki1 errCorr; // Error correctionsu1 cs; // Checksum
        const Types::u1& Len() const { return _len; }
        Types::u1& Len() { return _len; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u1 _prn;
        Types::u4 _time;
        Types::u1 _type;
        Types::u1 _len;
    };
}
