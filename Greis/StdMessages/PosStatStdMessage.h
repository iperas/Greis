#ifndef PosStatStdMessage_h__
#define PosStatStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class PosStatStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(PosStatStdMessage);

        PosStatStdMessage(const char* p_message, int p_length);
        PosStatStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::PosStat; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Number of GPS SVs locked
        const Types::u1& GpsLocked() const { return _gpsLocked; }
        Types::u1& GpsLocked() { return _gpsLocked; }

        // Number of GLONASS SVs locked
        const Types::u1& GloLocked() const { return _gloLocked; }
        Types::u1& GloLocked() { return _gloLocked; }

        // Number of GPS SVs available for positioning
        const Types::u1& GpsAvail() const { return _gpsAvail; }
        Types::u1& GpsAvail() { return _gpsAvail; }

        // Number of GLONASS SVs available for positioning
        const Types::u1& GloAvail() const { return _gloAvail; }
        Types::u1& GloAvail() { return _gloAvail; }

        // Number of GPS SVs used in positioning
        const Types::u1& GpsUsed() const { return _gpsUsed; }
        Types::u1& GpsUsed() { return _gpsUsed; }

        // Number of GLONASS SVs used in positioning
        const Types::u1& GloUsed() const { return _gloUsed; }
        Types::u1& GloUsed() { return _gloUsed; }

        // Ambiguity fixing progress indicator
        // controllable by RTK engine [%]
        const Types::u1& FixProg() const { return _fixProg; }
        Types::u1& FixProg() { return _fixProg; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _solType;
        Types::u1 _gpsLocked;
        Types::u1 _gloLocked;
        Types::u1 _gpsAvail;
        Types::u1 _gloAvail;
        Types::u1 _gpsUsed;
        Types::u1 _gloUsed;
        Types::u1 _fixProg;
        Types::u1 _cs;
    };
}

#endif // PosStatStdMessage_h__
