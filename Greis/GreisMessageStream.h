#ifndef GreisMessageStream_h__
#define GreisMessageStream_h__

#include <QtCore/QString>
#include <QtCore/QFile>
#include "ProjectBase/File.h"
#include "ProjectBase/Logger.h"
#include <string>
#include "GreisException.h"
#include "StdMessage.h"
#include "NonStdTextMessage.h"
#include "IBinaryStream.h"

namespace Greis
{
    class GreisMessageStream
    {
    public:
        GreisMessageStream(IBinaryStream::SharedPtr_t openedBinaryStream, bool skipInvalid = false, bool handleStdOnly = true);
        bool HasNext();
        Message::UniquePtr_t Next();

    private:
        IBinaryStream::SharedPtr_t _binaryStream;
        bool _skipInvalid;
        bool _handleStdOnly;
    };

    class GreisMessageStream2
    {
    public:
        GreisMessageStream2(QString filename, bool skipInvalid = false, bool handleStdOnly = true);
        bool HasNext();
        Message::UniquePtr_t Next();

    private:
        ProjectBase::QFilePtr _file;
        bool _skipInvalid;
        bool _handleStdOnly;
    };
}

#endif // GreisMessageStream_h__