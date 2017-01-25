#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

#include "Greis/CustomType/GPSAlm1CustomType.h"

namespace Greis
{
    class QZSSAlmStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(QZSSAlmStdMessage);

        QZSSAlmStdMessage(const char* p_message, int p_length);
        QZSSAlmStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::QZSSAlm; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // ‘gps.sv’ within the range [193…197]
        const GPSAlm1CustomType::UniquePtr_t& Gps() const { return _gps; }
        GPSAlm1CustomType::UniquePtr_t& Gps() { return _gps; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        GPSAlm1CustomType::UniquePtr_t _gps;
    };
}
