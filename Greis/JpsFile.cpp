#include "JpsFile.h"

using namespace ProjectBase;

namespace Greis
{
    JpsFile::UniquePtr_t JpsFile::FromFile(QString filename)
    {
        auto jpsFile = JpsFile::UniquePtr_t(new JpsFile());

        int epochCounter = 0;
        GreisMessageStream stream(filename, false, false);
        QDateTime dateTime;
        dateTime.setTimeSpec(Qt::UTC);

        // Collecting a head
        Message::UniquePtr_t msg;
        int index = 0;
        while((msg = stream.Next()).get())
        {
            if (msg->Kind() == EMessageKind::StdMessage)
            {
                auto stdMsg = dynamic_cast<StdMessage*>(msg.get());
                if (stdMsg->IdNumber() == EMessageId::RcvTime)
                {
                    updateTimePart(dynamic_cast<RcvTimeStdMessage*>(stdMsg), dateTime);
                    break;
                }
                if (stdMsg->IdNumber() == EMessageId::RcvDate)
                {
                    updateDatePart(dynamic_cast<RcvDateStdMessage*>(stdMsg), dateTime);
                }
            }
            if (index++ < 6)
            {
                // Only first 6 messages are actually collected (JP, \r, \n, MF, \r, \n).
                // PM messages are ignored.
                jpsFile->_head.push_back(std::move(msg));
            }
        }
        // if a head collection was interrupted by RcvTime message, move it to first epoch
        auto epoch = make_unique<Epoch>();
        if (msg.get())
        {
            epoch->Messages.push_back(std::move(msg));
        }
        // Collecting a body
        bool headerParsed = false;
        while((msg = stream.Next()).get())
        {
            if (msg->Kind() == EMessageKind::StdMessage)
            {
                auto stdMsg = dynamic_cast<StdMessage*>(msg.get());
                if (stdMsg->IdNumber() == EMessageId::RcvTime)
                {
                    // This message is a part of new epoch. 
                    // We should assign a dateTime value to current epoch and push it to the epochs container.
                    epoch->DateTime = dateTime;
                    jpsFile->_body.push_back(std::move(epoch));
                    // push in previous epoch
                    if (++epochCounter % 3000 == 0)
                    {
                        sLogger.Info(QString("3000 epochs deserialized. %1 total.").arg(epochCounter));
                    }
                    epoch = make_unique<Epoch>();

                    updateTimePart(dynamic_cast<RcvTimeStdMessage*>(stdMsg), dateTime);
                }
                if (stdMsg->IdNumber() == EMessageId::RcvDate)
                {
                    updateDatePart(dynamic_cast<RcvDateStdMessage*>(stdMsg), dateTime);
                }
            }
            epoch->Messages.push_back(std::move(msg));
        }
        // last Epoch
        if (epoch->Messages.size() > 0)
        {
            epoch->DateTime = dateTime;
            jpsFile->_body.push_back(std::move(epoch));
        }

        sLogger.Info(QString("%1 epochs have been totally deserialized.").arg(epochCounter));
        return jpsFile;
    }

    QByteArray JpsFile::ToByteArray() const
    {
        QByteArray result;
        for (auto it = _head.cbegin(); it != _head.cend(); ++it)
        {
            result.append((*it)->ToByteArray());
        }
        for (auto epochIt = _body.cbegin(); epochIt != _body.cend(); ++epochIt)
        {
            for (auto msgIt = (*epochIt)->Messages.cbegin(); msgIt != (*epochIt)->Messages.cend(); ++msgIt)
            {
                result.append((*msgIt)->ToByteArray());
            }
        }
        return result;
    }
}
