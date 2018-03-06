#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class CompRawNavDataStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(CompRawNavDataStdMessage);

        CompRawNavDataStdMessage(const char* p_message, int p_length);
        CompRawNavDataStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::CompRawNavData; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SV PRN number 
        const Types::u1& Prn() const { return _prn; }
        Types::u1& Prn() { return _prn; }

        // BeiDou Time of receiving of message [s] 
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Type of data:
        // 0 - B1 
        // 1 - B2 
        // 2 - B3 
        // 3 - B1 from GEO 
        // 4 - B2 from GEO 
        // 5 - B3 from GEO 
        // 6 - B1C 
        // 7 - B1-2 
        // 8 - B5A 
        // 9 - B5B 
        const Types::u1& Type() const { return _type; }
        Types::u1& Type() { return _type; }

        // Length of the navigation data block �data�u4 data[len]; // Navigation data blocki1 errCorr; // Error correctionsu1 cs; // Checksum 
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
