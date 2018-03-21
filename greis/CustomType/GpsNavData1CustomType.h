#pragma once

#include <QtCore/QByteArray>
#include "greis/CustomType.h"
#include "greis/ECustomTypeId.h"

#include "greis/CustomType/SvData0CustomType.h"

namespace Greis
{
    class GpsNavData1CustomType : public CustomType
    {
    public:
        SMART_PTR_T(GpsNavData1CustomType);

        GpsNavData1CustomType(const char* p_message, int p_length);
        GpsNavData1CustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::GpsNavData1; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Size of satellite data record (currently 42)
        const Types::u1& RecSize() const { return _recSize; }
        Types::u1& RecSize() { return _recSize; }

        // Satellite data. “N” can be derived from the 
        // following expression:
        // N=([Message Length] - 2) / recSize) 
        const std::vector<SvData0CustomType::UniquePtr_t>& Dat() const { return _dat; }
        std::vector<SvData0CustomType::UniquePtr_t>& Dat() { return _dat; }

        // Checksum 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        int _size;
        bool _isCorrect;

        Types::u1 _recSize;
        std::vector<SvData0CustomType::UniquePtr_t> _dat;
        Types::u1 _cs;
    };
}
