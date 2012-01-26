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
    typedef vector<Message_t::Pointer_t> Epoch_t;

    class JpsFile_t
    {
    public:
        SHARED_PTR_T(JpsFile_t);
        NULL_PTR_DECL;

        JpsFile_t(QString aFilename)
        {
            parse(aFilename);
        }

        inline const Epoch_t& header() const { return _header; }
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
                foreach(Message_t::Pointer_t msg, epoch)
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
            foreach(Message_t::Pointer_t msg, header())
            {
                StdMessage_t::Pointer_t stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
                sink->AddMessage(stdMsg);
            }
            foreach(Epoch_t epoch, body())
            {
                foreach(Message_t::Pointer_t msg, epoch)
                {
                    StdMessage_t::Pointer_t stdMsg = boost::shared_dynamic_cast<StdMessage_t>(msg);
                    sink->AddMessage(stdMsg);
                }
            }
        }
    private:
        void parse(QString aFilename)
        {
            _filename = aFilename;
            _header.clear();
            _body.clear();
            StdMessageStream stream(aFilename);
            Message_t::Pointer_t msg;

            // before ~~(RT)
            while((msg = stream.Next(true)).get() && msg->type() != RTStdMessage)
            {
                _header.push_back(msg);
            }
            // epoch contains PM ? header : body
            vector<Message_t::Pointer_t> epoch;
            if (msg.get())
            {
                epoch.push_back(msg);
            }
            // main parsing loop
            bool headerParsed = false;
            while((msg = stream.Next(true)).get())
            {
                if (msg->type() == RTStdMessage)
                {
                    // push
                    bool isHeader = false;
                    if (!headerParsed)
                    {
                        foreach(Message_t::Pointer_t em, epoch)
                        {
                            if (em->type() == UnknownStdMessage && boost::shared_dynamic_cast<StdMessage_t>(em)->id() == "PM")
                            {
                                isHeader = true;
                            }
                        }
                        headerParsed = true;
                    }
                    if (isHeader)
                    {
                        std::copy(epoch.begin(), epoch.end(), std::back_inserter(_header));
                    } else {
                        _body.push_back(epoch);
                    }
                    epoch.clear();
                }
                epoch.push_back(msg);
            }
            // last Epoch
            if (epoch.size() > 0)
            {
                _body.push_back(epoch);
            }
            //sLog.addInfo(QString("В файле '%1' выделено %2 эпох.").arg(aFilename).arg(_body.size()));
        }

        Epoch_t _header;
        list<Epoch_t> _body;
        QString _filename;
    };
}

#endif // JpsFile_h__