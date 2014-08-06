#ifndef GpsRawNavData1CustomType_h__
#define GpsRawNavData1CustomType_h__

#include "CustomType.h"
#include <QtCore/QByteArray>
#include "ECustomTypeId.h"

namespace Greis
{
    class GpsRawNavData1CustomType : public CustomType
    {
    public:
        SMART_PTR_T(GpsRawNavData1CustomType);

        GpsRawNavData1CustomType(const char* p_message, int p_length);
        GpsRawNavData1CustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::GpsRawNavData1; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Pseudo-Range Number (PRN)
        const Types::u1& Prn() const { return _prn; }
        Types::u1& Prn() { return _prn; }

        // Time of receiving of message [s]
        const Types::u4& Time() const { return _time; }
        Types::u4& Time() { return _time; }

        // Type of data:
        // 0 - GPS L1 NAV
        // 1 - GPS L2C CNAV
        // 2 - GPS L5 CNAV
        // 3 - GPS L1C CNAV2
        const Types::u1& Type() const { return _type; }
        Types::u1& Type() { return _type; }

        // Length of the navigation data block ‘data’
        const Types::u1& Len() const { return _len; }
        Types::u1& Len() { return _len; }

        // Navigation data block
        const std::vector<Types::u4>& Data() const { return _data; }
        std::vector<Types::u4>& Data() { return _data; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        int _size;
        bool _isCorrect;

        Types::u1 _prn;
        Types::u4 _time;
        Types::u1 _type;
        Types::u1 _len;
        std::vector<Types::u4> _data;
        Types::u1 _cs;
    };
}

#endif // GpsRawNavData1CustomType_h__
