#ifndef GloNavDataStdMessage_h__
#define GloNavDataStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

#include "CustomTypes/SvData1CustomType.h"

namespace Greis
{
    class GloNavDataStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GloNavDataStdMessage);

        GloNavDataStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Size of satellite data record (currently 18)
        const Types::u1& RecSize() const { return _recSize; }
        Types::u1& RecSize() { return _recSize; }

        // Satellite data. “N” can be derived from the
        // following expression:
        // N=([Message Length] - 2) / recSize)
        const std::vector<SvData1CustomType::UniquePtr_t>& Dat() const { return _dat; }
        std::vector<SvData1CustomType::UniquePtr_t>& Dat() { return _dat; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::u1 _recSize;
        std::vector<SvData1CustomType::UniquePtr_t> _dat;
        Types::u1 _cs;
    };
}

#endif // GloNavDataStdMessage_h__
