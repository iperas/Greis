#pragma once

#include <QtCore/QByteArray>
#include "greis/CustomType.h"
#include "greis/ECustomTypeId.h"

namespace Greis
{
    class ESICustomType : public CustomType
    {
    public:
        SMART_PTR_T(ESICustomType);

        ESICustomType(const char* p_message, int p_length);
        ESICustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::ESI; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Satellite system identifier (SSID)
        const Types::u1& Ssid() const { return _ssid; }
        Types::u1& Ssid() { return _ssid; }

        // Satellite identifier (SVID) inside system
        const Types::u1& Svid() const { return _svid; }
        Types::u1& Svid() { return _svid; }
    private:
        int _size;
        bool _isCorrect;

        Types::u1 _ssid;
        Types::u1 _svid;
    };
}
