#ifndef RmsStdMessage_h__
#define RmsStdMessage_h__

#include "StdMessage.h"
#include <QtCore/QByteArray>

namespace Greis
{
    class RmsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(RmsStdMessage);

        RmsStdMessage(const char* p_message, int p_length);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Horizontal position RMS error[m]
        const Types::f4& Hpos() const { return _hpos; }
        Types::f4& Hpos() { return _hpos; }

        // Vertical position RMS error [m]
        const Types::f4& Vpos() const { return _vpos; }
        Types::f4& Vpos() { return _vpos; }

        // Horizontal velocity RMS error [m/s]
        const Types::f4& Hvel() const { return _hvel; }
        Types::f4& Hvel() { return _hvel; }

        // Vertical velocity RMS error [m/s]
        const Types::f4& Vvel() const { return _vvel; }
        Types::f4& Vvel() { return _vvel; }

        // Solution type
        const Types::u1& SolType() const { return _solType; }
        Types::u1& SolType() { return _solType; }

        // Checksum
        const Types::u1& Cs() const { return _cs; }
        Types::u1& Cs() { return _cs; }
    private:
        std::string _id;
        int _bodySize;

        Types::f4 _hpos;
        Types::f4 _vpos;
        Types::f4 _hvel;
        Types::f4 _vvel;
        Types::u1 _solType;
        Types::u1 _cs;
    };
}

#endif // RmsStdMessage_h__
