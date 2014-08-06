#pragma once

#include <QtCore/QByteArray>
#include "Greis/StdMessage.h"
#include "Greis/EMessageId.h"

namespace Greis
{
    class REStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(REStdMessage);

        REStdMessage(const char* p_message, int p_length);
        REStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::RE; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Reply
        const std::string& Reply() const { return _reply; }
        std::string& Reply() { return _reply; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::string _reply;
    };
}
