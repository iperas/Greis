#ifndef GreisMessageStream_h__
#define GreisMessageStream_h__

#include <QtCore/QtCore>
#include "Util/File.h"
#include "Util/Logger.h"
#include <string>
#include "GreisException.h"

using std::string;

namespace Greis
{
    class StdMessageStream
    {
    public:
        StdMessageStream(QString filename)
        {
            Open(filename);
        }

        bool HasNext()
        {
            return _file->peek(1).size() > 0;
        }

        Message_t::Pointer_t Next(bool skipInvalid = false, bool skipNonStd = true)
        {
NextLabel: // avoiding stack overflow in recursive call
            const int minNSTM = NonStdTextMessage_t::min_id;
            const int maxNSTM = NonStdTextMessage_t::max_id;
            const int minSM = StdMessage_t::min_id_char;
            const int maxSM = StdMessage_t::max_id_char;
            char id;
            Message_t::Pointer_t nullPtr = Message_t::null_ptr;
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
                    if (NonStdTextMessage_t::isEom(ch))
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
                    sLogger.Warn(QString("Unexpected end of file, readed %1 body bytes of non-standard text message, expected EOM.").arg(body.size()));
                    return nullPtr;
                }
                NonStdTextMessage_t::Pointer_t msg = NonStdTextMessage_t::Pointer_t(new NonStdTextMessage_t(id, body, eom));
                //sLog.addInfo(msg->toString());
                if (skipNonStd)
                    goto NextLabel;
                else
                    return msg;
            } else if (id == '\r' || id == '\n')
            {
                // Zero-length non-standard Text Message
                NonStdTextMessage_t::Pointer_t msg = NonStdTextMessage_t::Pointer_t(new NonStdTextMessage_t(id));
                _file->read(&id, 1);
                //sLog.addInfo(msg->toString());
                if (skipNonStd)
                    goto NextLabel;
                else
                    return msg;
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
                    QByteArray data = _file->read(msgLen + StdMsgHeaderLen);
                    if (data.size() != msgLen + StdMsgHeaderLen)
                    {
                        sLogger.Warn(QString("Unexpected end of file, readed %1 bytes of standard message, expected %2.")
                            .arg(data.size()).arg(msgLen + StdMsgHeaderLen));
                        return nullPtr;
                    }
                    StdMessage_t::Pointer_t msg = StdMessageFactory_t::Create(data.data(), msgLen + StdMsgHeaderLen);
                    if (skipInvalid && !msg->validate())
                    {
                        sLogger.Debug(QString("Invalid message. ") + QString("Skip this one and look forward."));
                        goto NextLabel;
                    }
                    //sLog.addInfo(msg->toString());
                    return msg;
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

    private:
        void Open(QString filename)
        {
            _filename = filename;
            _file = File::OpenReadBinary(_filename);
        }

    private:
        QString _filename;
        QFilePtr _file;
        static const int StdMsgHeaderLen = 5;
    };
}

#endif // GreisMessageStream_h__