#ifndef FileIdStdMessage_h__
#define FileIdStdMessage_h__

#include <QtCore/QByteArray>
#include "StdMessage.h"
#include "EMessageId.h"

namespace Greis
{
    class FileIdStdMessage : public StdMessage
    {
    public:
        SMART_PTR_T(FileIdStdMessage);

        FileIdStdMessage(const char* p_message, int p_length);
        FileIdStdMessage(const std::string& p_id, int p_size);

        virtual std::string ToString() const;
        virtual std::string Id() const { return _id; }
        virtual EMessageId::Type IdNumber() const { return EMessageId::FileId; }
        virtual bool Validate() const;
        virtual int BodySize() const { return _bodySize; }
        virtual QByteArray ToByteArray() const;
        
        // File type identifier
        const std::string& IdField() const { return _idField; }
        std::string& IdField() { return _idField; }

        // Human-readable stream description
        const std::string& Description() const { return _description; }
        std::string& Description() { return _description; }
    private:
        std::string _id;
        int _bodySize;

        std::string _idField;
        std::string _description;
    };
}

#endif // FileIdStdMessage_h__
