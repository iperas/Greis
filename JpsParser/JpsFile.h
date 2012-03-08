#ifndef JpsFile_h__
#define JpsFile_h__

#include "Util/Macro.h"
#include "GreisMessage.h"
#include "GreisMessageStream.h"
#include <list>
#include "Domain/MySqlSink.h"

using std::list;
using namespace Domain;

namespace Greis
{
    typedef vector<Message_t::Pointer_t> Messages_t;

    class Epoch_t
    {
    public:
        QDateTime DateTime;
        Messages_t Messages;
    };

    class JpsFile_t
    {
    public:
        SHARED_PTR_T(JpsFile_t);
        NULL_PTR_DECL;

        JpsFile_t(QString aFilename)
        {
            parse(aFilename);
        }

        inline const Messages_t& header() const { return _header; }
        inline const list<Epoch_t>& body() const { return _body; }
        inline QString filename() const { return _filename; }

        void toBinaryStream(std::ostream& out) const
        {
            foreach(Message_t::Pointer_t msg, header())
            {
                StdMessage_t::Pointer_t stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
                out.write(stdMsg->message(), stdMsg->fullSize());
                out.write("\0\n", 2);
            }
            foreach(Epoch_t epoch, body())
            {
                foreach(Message_t::Pointer_t msg, epoch.Messages)
                {
                    StdMessage_t::Pointer_t stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
                    out.write(stdMsg->message(), stdMsg->fullSize());
                    out.write("\0\n", 2);
                }
            }
            out.flush();
        }

        void toMySqlSink(MySqlSink::Pointer_t sink)
        {
            /*foreach(Message_t::Pointer_t msg, header())
            {
                StdMessage_t::Pointer_t stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
                sink->AddMessage(stdMsg, false);
            }*/
            foreach(Epoch_t epoch, body())
            {
                sink->AddEpoch(epoch.DateTime);
                foreach(Message_t::Pointer_t msg, epoch.Messages)
                {
                    StdMessage_t::Pointer_t stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
                    sink->AddMessage(stdMsg, false);
                }
            }
        }
    private:
        void parse(QString aFilename)
        {
            const string messageCodeRT("~~");
            const string messageCodeRD("RD");
            _filename = aFilename;
            _header.clear();
            _body.clear();
            int epochCounter = 0;
            StdMessageStream stream(aFilename);
            Message_t::Pointer_t msg;

            QDateTime dateTime;
            dateTime.setTimeSpec(Qt::UTC);
            // before ~~(RT)
            while((msg = stream.Next(true)).get())
            {
                if (msg->type() == UnknownStdMessage)
                {
                    auto stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
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
            Epoch_t epoch;
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
                    auto stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
                    if (stdMsg->id() == messageCodeRT)
                    {
                        epoch.DateTime = dateTime;
                        handleRTMessage(stdMsg.get(), dateTime);
                        // push in previous epoch
                        bool isHeader = false;
                        /*if (!headerParsed) // Commented: Есть предположение, что параметры приемника должны идти наряду с обычными сообщениями.
                        {
                            foreach(Message_t::Pointer_t em, epoch.Messages)
                            {
                                if (em->type() == UnknownStdMessage && boost::shared_dynamic_cast<StdMessage_t>(em)->id() == "PM")
                                {
                                    isHeader = true;
                                }
                            }
                            headerParsed = true;
                            }*/
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
            //sLog.addInfo(QString("В файле '%1' выделено %2 эпох.").arg(aFilename).arg(_body.size()));
        }

        inline void handleRTMessage( StdMessage_t* stdMsg, QDateTime &dateTime )
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
        }

        Messages_t _header;
        list<Epoch_t> _body;
        QString _filename;
        BitConverter _bitConverter;
    };
}

#endif // JpsFile_h__