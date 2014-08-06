#ifndef SvData2CustomType_h__
#define SvData2CustomType_h__

#include <QtCore/QByteArray>
#include "CustomType.h"
#include "ECustomTypeId.h"

#include "CustomType/HeaderCustomType.h"
#include "CustomType/SlotRecCustomType.h"

namespace Greis
{
    class SvData2CustomType : public CustomType
    {
    public:
        SMART_PTR_T(SvData2CustomType);

        SvData2CustomType(const char* p_message, int p_length);
        SvData2CustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::SvData2; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Header (see below)
        const HeaderCustomType::UniquePtr_t& Header() const { return _header; }
        HeaderCustomType::UniquePtr_t& Header() { return _header; }

        // Slot records (see below)
        const std::vector<SlotRecCustomType::UniquePtr_t>& Slot() const { return _slot; }
        std::vector<SlotRecCustomType::UniquePtr_t>& Slot() { return _slot; }
    private:
        int _size;
        bool _isCorrect;

        HeaderCustomType::UniquePtr_t _header;
        std::vector<SlotRecCustomType::UniquePtr_t> _slot;
    };
}

#endif // SvData2CustomType_h__
