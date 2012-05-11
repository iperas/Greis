#ifndef PosVelVectorStdMessage_h__
#define PosVelVectorStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class PosVelVectorStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PosVelVectorStdMessage);

        PosVelVectorStdMessage(const char* p_message, int p_length);
        PosVelVectorStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PosVelVector; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Sample number []
        const Types::u2& Sample() const { return _sample; }
        Types::u2& Sample() { return _sample; }

        // [bitfield]:
        // 15…5: Difference between the raw measurement time
        // (available from either [rM] or [rE] message)
        // and the position time tag [-1024…1023], [5 ms]
        // 4…0: reserved
        const Types::u2& Delta() const { return _delta; }
        Types::u2& Delta() { return _delta; }

        // 32 MSB of Position X-component;
        const Types::u4& Word1() const { return _word1; }
        Types::u4& Word1() { return _word1; }

        // [bitfield]:
        // 31…24: 8 LSB of Position ECEF X-component [10-4 m]
        // or Latitude [10-11 radians]
        // or Grid (Local) X-component [10-4 m];
        // 23: 1 - indicates that Position is valid
        // 22…21: 0 – Position is given in ECEF system
        // 1 – Position is given in geodetic coordinates
        // (latitude, longitude, height above
        // ellipsoid)
        // 2 – Position is given in grid (or local)
        // coordinates
        // 3 – reserved
        // 20…16: Number of GPS SVs used in computation;
        // 15: 1 - indicates that Velocity is valid
        // 14…13: reserved
        // 12…8: Number of GLONASS SVs used in computation;
        // 7…4: Position computation mode
        // (see Table 4-3 on page 324);
        // 3…0: Velocity computation mode
        // (see Table 4-3 on page 324);
        const Types::u4& Word2() const { return _word2; }
        Types::u4& Word2() { return _word2; }

        // 31…0: 32 MSB of Position Y-component;
        const Types::u4& Word3() const { return _word3; }
        Types::u4& Word3() { return _word3; }

        // 31…24: 8 LSB of Position ECEF Y-component [10-4 m]
        // or Longitude [10-11 radians]
        // or Grid (Local) Y-component [10-4 m];
        // 23…15: PDOP * 10 [];
        // 14…0: RMS velocity error [0.001 meters];
        const Types::u4& Word4() const { return _word4; }
        Types::u4& Word4() { return _word4; }

        // 32 MSB of 40-bit ECEF position Z-component;
        const Types::u4& Word5() const { return _word5; }
        Types::u4& Word5() { return _word5; }

        // [bitfield]:
        // 31…24: 8 LSB of 40-bit position ECEF Z-component
        // or Height above ellipsoid [10-4 m];
        // 23…20: reserved;
        // 19…0: RMS Position error [0.001 m];
        const Types::u4& Word6() const { return _word6; }
        Types::u4& Word6() { return _word6; }

        // [bitfield]:
        // 31…4: velocity X-component [10-4 m/s]
        // or East component (if types 1 and 2 are
        // selected in bits 22…21 of the ‘word2’ field);
        // 3…2: reserved;
        // 1…0: 2 MSB of GREIS datum number (see note below);
        const Types::u4& Word7() const { return _word7; }
        Types::u4& Word7() { return _word7; }

        // [bitfield]:
        // 31…4: velocity Y-component [10-4 m/s]
        // or North component (if types 1 and 2 are
        // selected in bits 22…21 of the ‘word2’ field);
        // 3…0: bits 7…4 of datum number;
        const Types::u4& Word8() const { return _word8; }
        Types::u4& Word8() { return _word8; }

        // [bitfield]:
        // 31…4: velocity Z-component [10-4 m/s]
        // or North component (if types 1 and 2 are
        // selected in bits 22…21 of the ‘word2’ field);
        // 3…0: 4 LSB of GREIS datum number;
        const Types::u4& Word9() const { return _word9; }
        Types::u4& Word9() { return _word9; }

        // 16-bit CRC;
        const Types::u2& Crc16() const { return _crc16; }
        Types::u2& Crc16() { return _crc16; }
    private:
        std::string _id;
        int _bodySize;

        Types::u2 _sample;
        Types::u2 _delta;
        Types::u4 _word1;
        Types::u4 _word2;
        Types::u4 _word3;
        Types::u4 _word4;
        Types::u4 _word5;
        Types::u4 _word6;
        Types::u4 _word7;
        Types::u4 _word8;
        Types::u4 _word9;
        Types::u2 _crc16;
    };
}

#endif // PosVelVectorStdMessage_h__
