#ifndef WAASEhemerisStdMessage_h__
#define WAASEhemerisStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class WAASEhemerisStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(WAASEhemerisStdMessage);

        WAASEhemerisStdMessage(const char* p_message, int p_length);
        WAASEhemerisStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::WAASEhemeris; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // WAAS SV PRN number within [120…138]
        const Types::u1& WaasPrn() const { return _waasPrn; }
        Types::u1& WaasPrn() { return _waasPrn; }

        // GPS SV PRN associated with WAAS SV
        const Types::u1& GpsPrn() const { return _gpsPrn; }
        Types::u1& GpsPrn() { return _gpsPrn; }

        // Issue of data
        const Types::u1& Iod() const { return _iod; }
        Types::u1& Iod() { return _iod; }

        // WAAS SV accuracy9
        const Types::u1& Acc() const { return _acc; }
        Types::u1& Acc() { return _acc; }

        // Reference time (seconds of the day)[s]
        const Types::u4& Tod() const { return _tod; }
        Types::u4& Tod() { return _tod; }

        // ECEF coordinates [m]
        const Types::f8& Xg() const { return _xg; }
        Types::f8& Xg() { return _xg; }

        // ECEF coordinates [m]
        const Types::f8& Yg() const { return _yg; }
        Types::f8& Yg() { return _yg; }

        // ECEF coordinates [m]
        const Types::f8& Zg() const { return _zg; }
        Types::f8& Zg() { return _zg; }

        // ECEF velocity [m/s]
        const Types::f4& Vxg() const { return _vxg; }
        Types::f4& Vxg() { return _vxg; }

        // ECEF velocity [m/s]
        const Types::f4& Vyg() const { return _vyg; }
        Types::f4& Vyg() { return _vyg; }

        // ECEF velocity [m/s]
        const Types::f4& Vzg() const { return _vzg; }
        Types::f4& Vzg() { return _vzg; }

        // ECEF acceleration [m/s^2]
        const Types::f4& Vvxg() const { return _vvxg; }
        Types::f4& Vvxg() { return _vvxg; }

        // ECEF acceleration [m/s^2]
        const Types::f4& Vvyg() const { return _vvyg; }
        Types::f4& Vvyg() { return _vvyg; }

        // ECEF acceleration [m/s^2]
        const Types::f4& Vvzg() const { return _vvzg; }
        Types::f4& Vvzg() { return _vvzg; }

        // WAAS SV clock offset factor ‘ao’ [s]
        const Types::f4& Agf0() const { return _agf0; }
        Types::f4& Agf0() { return _agf0; }

        // WAAS SV clock offset factor ‘a1’ [s/s]
        const Types::f4& Agf1() const { return _agf1; }
        Types::f4& Agf1() { return _agf1; }

        // Time of GPS week this ephemeris was
        // received at
        const Types::u4& Tow() const { return _tow; }
        Types::u4& Tow() { return _tow; }

        // GPS week this ephemeris was received at
        const Types::u2& Wn() const { return _wn; }
        Types::u2& Wn() { return _wn; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _waasPrn;
        Types::u1 _gpsPrn;
        Types::u1 _iod;
        Types::u1 _acc;
        Types::u4 _tod;
        Types::f8 _xg;
        Types::f8 _yg;
        Types::f8 _zg;
        Types::f4 _vxg;
        Types::f4 _vyg;
        Types::f4 _vzg;
        Types::f4 _vvxg;
        Types::f4 _vvyg;
        Types::f4 _vvzg;
        Types::f4 _agf0;
        Types::f4 _agf1;
        Types::u4 _tow;
        Types::u2 _wn;
        Types::u1 _cs;
    };
}

#endif // WAASEhemerisStdMessage_h__
