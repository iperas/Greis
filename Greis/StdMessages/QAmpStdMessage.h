#ifndef QAmpStdMessage_h__
#define QAmpStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class QAmpStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(QAmpStdMessage);

        QAmpStdMessage(const char* p_message, int p_length);
        QAmpStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::QAmp; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // (Q) amplitudes
        const std::vector<Types::i2>& Amp() const { return _amp; }
        std::vector<Types::i2>& Amp() { return _amp; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i2> _amp;
        Types::u1 _cs;
    };
}

#endif // QAmpStdMessage_h__
