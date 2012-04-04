#ifndef RcvTimeOffsAtPPSStdMessage_h__
#define RcvTimeOffsAtPPSStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class RcvTimeOffsAtPPSStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RcvTimeOffsAtPPSStdMessage);

        RcvTimeOffsAtPPSStdMessage(const char* p_message, int p_length);
        RcvTimeOffsAtPPSStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RcvTimeOffsAtPPS; }
        virtual bool Validate() const;
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // [Tpps-Tr] offset[s]
        const Types::f8& Offs() const { return _offs; }
        Types::f8& Offs() { return _offs; }

        // time scale
        const Types::u1& TimeScale() const { return _timeScale; }
        Types::u1& TimeScale() { return _timeScale; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f8 _offs;
        Types::u1 _timeScale;
        Types::u1 _cs;
    };
}

#endif // RcvTimeOffsAtPPSStdMessage_h__
