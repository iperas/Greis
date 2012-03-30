#ifndef SvData2CustomType_h__
#define SvData2CustomType_h__

#include "CustomType.h"
#include <QtCore/QByteArray>

#include "CustomTypes/HeaderCustomType.h"
#include "CustomTypes/SlotRecCustomType.h"

namespace Greis
{
    class SvData2CustomType : public CustomType
    {
    public:
        SMART_PTR_T(SvData2CustomType);

        SvData2CustomType(char* p_message, int p_length);

        virtual QByteArray ToByteArray() const;
        virtual int Size() const;

        // Header (see below)
        const HeaderCustomType::UniquePtr_t& Header() const { return _header; }
        HeaderCustomType::UniquePtr_t& Header() { return _header; }

        // Slot records (see below)
        const std::vector<SlotRecCustomType::UniquePtr_t>& Slot() const { return _slot; }
        std::vector<SlotRecCustomType::UniquePtr_t>& Slot() { return _slot; }
    private:
        int _size;

        HeaderCustomType::UniquePtr_t _header;
        std::vector<SlotRecCustomType::UniquePtr_t> _slot;
    };
}

#endif // SvData2CustomType_h__
