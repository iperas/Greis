#ifndef QZSSEphemerisStdMessage_h__
#define QZSSEphemerisStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/GPSEphemeris1CustomType.h"

namespace Greis
{
    class QZSSEphemerisStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(QZSSEphemerisStdMessage);

        QZSSEphemerisStdMessage(const char* p_message, int p_length);
        QZSSEphemerisStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::QZSSEphemeris; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Without ‘cs’, ‘gps.sv’ within the range[193…197]
        const GPSEphemeris1CustomType::UniquePtr_t& Gps() const { return _gps; }
        GPSEphemeris1CustomType::UniquePtr_t& Gps() { return _gps; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        GPSEphemeris1CustomType::UniquePtr_t _gps;
        Types::u1 _cs;
    };
}

#endif // QZSSEphemerisStdMessage_h__
