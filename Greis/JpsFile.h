#ifndef JpsFile_h__
#define JpsFile_h__

#include "GreisMessageStream.h"
#include <vector>

namespace Greis
{
    class Epoch
    {
    public:
        QDateTime DateTime;
        std::vector<Message> Messages;
    };

    class JpsFile
    {
    public:
        SMART_PTR_T(JpsFile);

        static JpsFile::UniquePtr_t FromFile(QString filename)
        {
            auto jpsFile = make_unique<JpsFile::UniquePtr_t>();



            return jpsFile;
        }

        inline const std::vector<Message>& header() const { return _header; }
        inline const std::vector<Epoch>& body() const { return _body; }

        QByteArray toByteArray() const
        {
            QByteArray result;
            for (auto it = _header.cbegin(); it != _header.cend(); ++it)
            {
                result.append((*it)->ToByteArray());
            }
            for (auto epochIt = _body.cbegin(); epochIt != _body.cend(); ++epochIt)
            {
                for (auto msgIt = epochIt->Messages.cbegin(); msgIt != epochIt->Messages.cend(); ++msgIt)
                {
                    result.append((*msgIt)->ToByteArray());
                }
            }
        }
    private:
        JpsFile(QString aFilename)
        {
        }

        void parse(QString aFilename)
        {
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
        }

        /*inline void handleRTMessage( StdMessage_t* stdMsg, QDateTime &dateTime )
        {
            auto dataPtr = stdMsg->body();
            auto timeOfDay = _bitConverter.GetUInt(dataPtr);
            dateTime.setTime(QTime().addMSecs(timeOfDay));
        }

        inline void handleRDMessage( StdMessage_t* stdMsg, QDateTime &dateTime ) 
        {
            auto dataPtr = stdMsg->body();
            unsigned short year = _bitConverter.GetUShort(dataPtr);
            dataPtr += 2;
            unsigned short month = _bitConverter.GetUChar(dataPtr++);
            unsigned short day = _bitConverter.GetUChar(dataPtr++);
            dateTime.setDate(QDate(year, month, day));
        }*/

        std::vector<Message> _header;
        std::vector<Epoch> _body;
    };
}

#endif // JpsFile_h__