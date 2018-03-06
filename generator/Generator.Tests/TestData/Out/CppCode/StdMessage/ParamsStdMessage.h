#pragma once

#include <QtCore/QByteArray>
#include "greis/StdMessage.h"
#include "greis/EMessageId.h"

namespace Greis
{
    class ParamsStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(ParamsStdMessage);

        ParamsStdMessage(const char* p_message, int p_length);
        ParamsStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::Params; }
        virtual bool Validate() const;
        virtual bool IsCorrect() const { return _isCorrect; }
        virtual void RecalculateChecksum();
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // Parameters descriptiona1 delim[2] = �,@�; // Checksum delimitera1 cs[2]; // Checksum formatted as hexadecimal 
        const std::string& Params() const { return _params; }
        std::string& Params() { return _params; }
    private:
        std::string _id;
        int _bodySize;
        bool _isCorrect;

        std::string _params;
    };
}
