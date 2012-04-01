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
            jpsFile->_body.push_back(std::move(epoch));
        }

        /*const string messageCodeRT("~~");
            const string messageCodeRD("RD");
            _filename = aFilename;
            _header.clear();
            _body.clear();
            int epochCounter = 0;
            StdMessageStream stream(aFilename, true);
            Message_t::SharedPtr_t msg;

            QDateTime dateTime;
            dateTime.setTimeSpec(Qt::UTC);
            // before ~~(RT)
            while((msg = stream.Next()).get())
            {
                if (msg->type() == UnknownStdMessage)
                {
                    auto stdMsg = dynamic_pointer_cast<StdMessage_t>(msg);
                    if (stdMsg->id() == messageCodeRT)
                    {
                        handleRTMessage(stdMsg.get(), dateTime);
                        break;
                    }
                    if (stdMsg->id() == messageCodeRD)
                    {
                        handleRDMessage(stdMsg.get(), dateTime);
                    }
                }
                _header.push_back(msg);
            }
            // epoch contains PM ? header : body
            Epoch epoch;
            if (msg.get())
            {
                epoch.Messages.push_back(msg);
            }
            // main parsing loop
            bool headerParsed = false;
            while((msg = stream.Next(true)).get())
            {
                if (msg->type() == UnknownStdMessage)
                {
                    auto stdMsg = dynamic_pointer_cast<StdMessage_t>(msg);
                    if (stdMsg->id() == messageCodeRT)
                    {
                        epoch.DateTime = dateTime;
                        handleRTMessage(stdMsg.get(), dateTime);
                        // push in previous epoch
                        bool isHeader = false;
                        /*if (!headerParsed) // Commented: Есть предположение, что параметры приемника должны идти наряду с обычными сообщениями.
                        {
                            foreach(Message_t::SharedPtr_t em, epoch.Messages)
                            {
                                if (em->type() == UnknownStdMessage && boost::shared_dynamic_cast<StdMessage_t>(em)->id() == "PM")
                                {
                                    isHeader = true;
                                }
                            }
                            headerParsed = true;
                            }* /
                        if (isHeader)
                        {
                            std::copy(epoch.Messages.begin(), epoch.Messages.end(), std::back_inserter(_header));
                        } else {
                            _body.push_back(epoch);
                            if (++epochCounter % 3000 == 0)
                            {
                                sLogger.Info(QString("+3000 epochs found (%1 total)...").arg(epochCounter));
                            }
                        }
                        epoch.Messages.clear();
                    }
                    if (stdMsg->id() == messageCodeRD)
                    {
                        handleRDMessage(stdMsg.get(), dateTime);
                    }
                }
                epoch.Messages.push_back(msg);
            }
            // last Epoch
            if (epoch.Messages.size() > 0)
            {
                _body.push_back(epoch);
            }
            //sLog.addInfo(QString("В файле '%1' выделено %2 эпох.").arg(aFilename).arg(_body.size()));*/

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
