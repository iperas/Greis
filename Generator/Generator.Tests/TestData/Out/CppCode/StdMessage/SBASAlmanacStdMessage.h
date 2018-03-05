#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class SBASAlmanacStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SBASAlmanacStdMessage);

        SBASAlmanacStdMessage(const char* p_message, int p_length);
        SBASAlmanacStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SBASAlmanac; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // SBAS SV PRN number within [120…142] 
        const Types::u1& WaasPrn() const { return _waasPrn; }
        Types::u1& WaasPrn() { return _waasPrn; }

        // 
        const Types::u1& GpsPrn() const { return _gpsPrn; }
        Types::u1& GpsPrn() { return _gpsPrn; }

        // 
        const Types::u1& IdField() const { return _idField; }
        Types::u1& IdField() { return _idField; }

        // 
        const Types::u1& HealthS() const { return _healthS; }
        Types::u1& HealthS() { return _healthS; }

        // 
        const Types::u4& Tod() const { return _tod; }
        Types::u4& Tod() { return _tod; }

        // 
        const Types::f8& Xg() const { return _xg; }
        Types::f8& Xg() { return _xg; }

        // 
        const Types::f8& Yg() const { return _yg; }
        Types::f8& Yg() { return _yg; }

        // 
        const Types::f8& Zg() const { return _zg; }
        Types::f8& Zg() { return _zg; }

        // 
        const Types::f4& Vxg() const { return _vxg; }
        Types::f4& Vxg() { return _vxg; }

        // 
        const Types::f4& Vyg() const { return _vyg; }
        Types::f4& Vyg() { return _vyg; }

        // 
        const Types::f4& Vzg() const { return _vzg; }
        Types::f4& Vzg() { return _vzg; }

        // 
        const Types::u4& Tow() const { return _tow; }
        Types::u4& Tow() { return _tow; }

        // 
        const Types::u2& Wn() const { return _wn; }
        Types::u2& Wn() { return _wn; }

        // 
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::u1 _waasPrn;
        Types::u1 _gpsPrn;
        Types::u1 _idField;
        Types::u1 _healthS;
        Types::u4 _tod;
        Types::f8 _xg;
        Types::f8 _yg;
        Types::f8 _zg;
        Types::f4 _vxg;
        Types::f4 _vyg;
        Types::f4 _vzg;
        Types::u4 _tow;
        Types::u2 _wn;
        Types::u1 _cs;
    };
}
