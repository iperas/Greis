#ifndef GALEphemerisStdMessage_h__
#define GALEphemerisStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/GpsEphReqDataCustomType.h"

namespace Greis
{
    class GALEphemerisStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GALEphemerisStdMessage);

        GALEphemerisStdMessage(const char* p_message, int p_length);
        GALEphemerisStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GALEphemeris; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GPS required data, ‘req.sv’ within the range [1…30]
        // --- GALILEO-specific data block ---
        const GpsEphReqDataCustomType::UniquePtr_t& Req() const { return _req; }
        GpsEphReqDataCustomType::UniquePtr_t& Req() { return _req; }

        // broacast group delay E1 - E5A [s]
        const Types::f4& BgdE1E5a() const { return _bgdE1E5a; }
        Types::f4& BgdE1E5a() { return _bgdE1E5a; }

        // broacast group delay E1 - E5B [s]
        const Types::f4& BgdE1E5b() const { return _bgdE1E5b; }
        Types::f4& BgdE1E5b() { return _bgdE1E5b; }

        // Effective ionisation level 1-st order parameter []
        const Types::f4& Ai0() const { return _ai0; }
        Types::f4& Ai0() { return _ai0; }

        // Effective ionisation level 2-nd order parameter []
        const Types::f4& Ai1() const { return _ai1; }
        Types::f4& Ai1() { return _ai1; }

        // Effective ionisation level 3-rd order parameter []
        const Types::f4& Ai2() const { return _ai2; }
        Types::f4& Ai2() { return _ai2; }

        // Ionospheric disturbance flags [bitfield]
        const Types::u1& Sfi() const { return _sfi; }
        Types::u1& Sfi() { return _sfi; }

        // Type of navigation data:
        // 0 - GALILEO E1B(INAV)
        // 1 - GALILEO E5A(FNAV)
        // 3 - GIOVE E1B
        // 4 - GIOVE E5A
        // --- End of GALILEO-specific data block ---
        const Types::u1& NavType() const { return _navType; }
        Types::u1& NavType() { return _navType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        GpsEphReqDataCustomType::UniquePtr_t _req;
        Types::f4 _bgdE1E5a;
        Types::f4 _bgdE1E5b;
        Types::f4 _ai0;
        Types::f4 _ai1;
        Types::f4 _ai2;
        Types::u1 _sfi;
        Types::u1 _navType;
        Types::u1 _cs;
    };
}

#endif // GALEphemerisStdMessage_h__
