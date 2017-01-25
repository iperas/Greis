#pragma once

#include <QtCore/QByteArray>
#include "Greis/CustomType.h"
#include "Greis/ECustomTypeId.h"

namespace Greis
{
    class SvData1CustomType : public CustomType
    {
    public:
        SMART_PTR_T(SvData1CustomType);

        SvData1CustomType(const char* p_message, int p_length);
        SvData1CustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::SvData1; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Frequency Channel Number plus 1(FCN+1)
        const Types::i1& Fcn1() const { return _fcn1; }
        Types::i1& Fcn1() { return _fcn1; }

        // Counter which is updated upon receiving a
        // string of a GLONASS sub-frame for given FCN.
        const Types::u1& Cnt() const { return _cnt; }
        Types::u1& Cnt() { return _cnt; }

        // GLONASS string contents. Every 4-bytes word contains
        // 25 LSB of the string of GLONASS sub-frame.
        const std::vector<Types::u4>& Data() const { return _data; }
        std::vector<Types::u4>& Data() { return _data; }
    private:
        int _size;
        bool _isCorrect;

        Types::i1 _fcn1;
        Types::u1 _cnt;
        std::vector<Types::u4> _data;
    };
}
