#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class SvDelaysStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(SvDelaysStdMessage);

        SvDelaysStdMessage(const char* p_message, int p_length);
        SvDelaysStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::SvDelays; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // GLONASS FCN[-7…6]
        const Types::i1& Fcn() const { return _fcn; }
        Types::i1& Fcn() { return _fcn; }

        // Phase delay [cycles]
        const Types::f4& Phase() const { return _phase; }
        Types::f4& Phase() { return _phase; }

        // Range delay [s]
        const Types::f4& Range() const { return _range; }
        Types::f4& Range() { return _range; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        Types::i1 _fcn;
        Types::f4 _phase;
        Types::f4 _range;
    };
}
