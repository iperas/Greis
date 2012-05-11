#ifndef GpsNavData0StdMessage_h__
#define GpsNavData0StdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

#include "CustomTypes/SvData0CustomType.h"

namespace Greis
{
    class GpsNavData0StdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GpsNavData0StdMessage);

        GpsNavData0StdMessage(const char* p_message, int p_length);
        GpsNavData0StdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::GpsNavData0; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Size of satellite data record (currently 42)
        const Types::u1& RecSize() const { return _recSize; }
        Types::u1& RecSize() { return _recSize; }

        // Satellite data. “N” can be derived from the
        // following expression:
        // N=([Message Length] - 2) / recSize)
        const std::vector<SvData0CustomType::UniquePtr_t>& Dat() const { return _dat; }
        std::vector<SvData0CustomType::UniquePtr_t>& Dat() { return _dat; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _recSize;
        std::vector<SvData0CustomType::UniquePtr_t> _dat;
        Types::u1 _cs;
    };
}

#endif // GpsNavData0StdMessage_h__
