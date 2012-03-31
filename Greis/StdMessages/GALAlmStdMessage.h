#ifndef GALAlmStdMessage_h__
#define GALAlmStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

#include "CustomTypes/GPSAlm1CustomType.h"

namespace Greis
{
    class GALAlmStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GALAlmStdMessage);

        GALAlmStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Without ‘cs’ field, gps.sv within the range [1…30]
        // GALILEO-Specific data
        const GPSAlm1CustomType::UniquePtr_t& Gps() const { return _gps; }
        GPSAlm1CustomType::UniquePtr_t& Gps() { return _gps; }

        // Issue of almanac data []
        const Types::i2& Iod() const { return _iod; }
        Types::i2& Iod() { return _iod; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        GPSAlm1CustomType::UniquePtr_t _gps;
        Types::i2 _iod;
        Types::u1 _cs;
    };
}

#endif // GALAlmStdMessage_h__
