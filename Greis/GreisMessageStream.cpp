#include "GreisMessageStream.h"
#include "ProjectBase/SmartPtr.h"
#include "StdMessageFactory.h"
#include <string>

using std::string;
using namespace ProjectBase;

namespace Greis
{
    GreisMessageStream::GreisMessageStream(QString filename, bool skipInvalid, bool handleStdOnly)
    {
        _file = File::OpenReadBinary(filename);
        _skipInvalid = skipInvalid;
        _handleStdOnly = handleStdOnly;
    }

    bool GreisMessageStream::HasNext()
    {
        return _file->peek(1).size() > 0;
    }

    Message::UniquePtr_t GreisMessageStream::Next()
    {
NextLabel: // avoiding stack overflow in recursive call
        const int minNSTM = NonStdTextMessage::MinIdValue;
        const int maxNSTM = NonStdTextMessage::MaxIdValue;
        const int minSM = StdMessage::MinIdValue;
        const int maxSM = StdMessage::MaxIdValue;
        char id;
        Message::UniquePtr_t nullPtr;
        int readed = _file->peek(&id, 1);

        if (readed == 0)
        {
            // End of file
            return nullPtr;
        }

        if (id >= minNSTM && id <= maxNSTM)
        {
            // Non-standard Text Message
            _file->read(&id, 1);
            char ch;
            char eom = 0;
            string body;
            while (_file->read(&ch, 1) == 1)
            {
                if (NonStdTextMessage::IsEom(ch))
                {
                    // end of message
                    eom = ch;
                    break;
                }
                body.push_back(ch);
            }
            if (eom == 0)
            {
                // Файл закончился до появления eom символа
                sLogger.Warn(QString(
                    "Unexpected end of file, readed %1 body bytes of non-standard text message, expected EOM.").
                    arg(body.size()));
                return nullPtr;
            }
            auto msg = make_unique<NonStdTextMessage>(id, body, eom);
            //sLog.addInfo(msg->toString());
            if (_handleStdOnly)
            {
                goto NextLabel;
            }
            else
            {
                return std::move(msg);
            }
        } else if (id == '\r' || id == '\n')
        {
            // Zero-length non-standard Text Message
            auto msg = make_unique<NonStdTextMessage>(id);
            _file->read(&id, 1);
            //sLog.addInfo(msg->toString());
            if (_handleStdOnly)
                goto NextLabel;
            else
                return std::move(msg);
        } else {
            QByteArray header = _file->peek(5);
            if (header.size() == 5)
            {
                // Standard Message
                // message id check
                char id0 = header[0];
                char id1 = header[1];
                if (id0 < minSM || id0 > maxSM || id1 < minSM || id1 > maxSM)
                {
                    _file->read(1);
                    sLogger.Debug(QString("1 byte skipped."));
                    goto NextLabel; // Пробуем всё сначала, пропустив мусор из файла
                }
                // message len
                QString msgLenStr = QString::fromAscii(header.data() + 2, 3);
                bool good;
                int msgLen = msgLenStr.toUInt(&good, 16);
                if (!good)
                {
                    throw GreisException(QString("Invalid Length field in StdMessage header: '%1'.").arg(msgLenStr));
                }
                // message data
                QByteArray data = _file->read(msgLen + StdMessage::HeadSize());
                if (data.size() != msgLen + StdMessage::HeadSize())
                {
                    sLogger.Warn(QString("Unexpected end of file, readed %1 bytes of standard message, expected %2.")
                        .arg(data.size()).arg(msgLen + StdMessage::HeadSize()));
                    return nullPtr;
                }
                auto msg = StdMessageFactory::Create(data.data(), msgLen + StdMessage::HeadSize());
                if (!msg->Validate())
                {
                    if (_skipInvalid)
                    {
                        sLogger.Debug(QString("Invalid message. ") + QString("Skip this one and look further."));
                        goto NextLabel;
                    } else {
                        throw GreisException(QString("Invalid message."));
                    }
                }
                //sLog.addInfo(msg->toString());
                return std::move(msg);
            } else {
                // Данные еще есть, но это не Greis-сообщение
                _file->read(1);
                sLogger.Debug(QString("Unexpected end of file. ") +
                    QString("Cannot read whole standard message header, readed: %1, expected: 1. Skip 1 byte and try to find Non-standard Text Message.")
                    .arg(header.size()));
                goto NextLabel; // Пробуем всё сначала, пропустив мусор из файла
            }
        }
    }
}
