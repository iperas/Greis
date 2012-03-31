#ifndef GloPhaseDelayStdMessage_h__
#define GloPhaseDelayStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class GloPhaseDelayStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(GloPhaseDelayStdMessage);

        GloPhaseDelayStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GLONASS FCN[-7…6]
        const std::vector<Types::i1>& Fcn() const { return _fcn; }
        std::vector<Types::i1>& Fcn() { return _fcn; }

        // Phase Delay, [cycles]
        const std::vector<Types::f4>& Phase() const { return _phase; }
        std::vector<Types::f4>& Phase() { return _phase; }

        // Range (reserved for future use)
        const std::vector<Types::f4>& Range() const { return _range; }
        std::vector<Types::f4>& Range() { return _range; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        std::vector<Types::i1> _fcn;
        std::vector<Types::f4> _phase;
        std::vector<Types::f4> _range;
        Types::u1 _cs;
    };
}

#endif // GloPhaseDelayStdMessage_h__
