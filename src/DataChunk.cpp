#include "DataChunk.h"
#include "FileBinaryStream.h"
#include "Common/SmartPtr.h"

using namespace Common;

namespace Greis
{
    DataChunk::UniquePtr_t DataChunk::FromFile(QString filename, bool skipInvalid)
    {
        auto dataChunk = make_unique<DataChunk>();
        GreisMessageStream stream(std::make_shared<FileBinaryStream>(filename), skipInvalid, false);
        dataChunk->ReadHead(stream);
        dataChunk->ReadBody(stream);
        return dataChunk;
    }

    void DataChunk::ReadHead(GreisMessageStream& stream)
    {
        // Collecting the head
        Message::UniquePtr_t msg;
        while ((msg = stream.Next()).get())
        {
            if (msg->Kind() == EMessageKind::StdMessage)
            {
                auto stdMsg = dynamic_cast<StdMessage*>(msg.get());
                if (stdMsg->IdNumber() == EMessageId::RcvTime)
                {
                    this->updateTimePart(dynamic_cast<RcvTimeStdMessage*>(stdMsg));
                    break;
                }
                if (stdMsg->IdNumber() == EMessageId::RcvDate)
                {
                    this->updateDatePart(dynamic_cast<RcvDateStdMessage*>(stdMsg));
                }
            }

            // All messages go to _head until date and time is set
            this->_head.push_back(std::move(msg));
        }
        // if the head collection was interrupted by a RcvTime message, move it to the first epoch
        if (msg.get())
        {
            this->_lastEpoch->Messages.push_back(std::move(msg));
        }
    }

    bool DataChunk::ReadBody(GreisMessageStream& stream, int maxEpochCount)
    {
        int epochCount = 0;
        Message::UniquePtr_t msg;
        // Collecting body
        while ((msg = stream.Next()).get())
        {
            if (this->AddMessage(std::move(msg)))
            {
                epochCount++;
                if (maxEpochCount > 0 && epochCount >= maxEpochCount)
                {
                    return true;
                }
            }
        }
        // last Epoch
        if (this->_lastEpoch->Messages.size() > 0)
        {
            this->_lastEpoch->DateTime = this->_dateTime;
            this->_body.push_back(std::move(this->_lastEpoch));
        }

        sLogger.Trace(QString("%1 epochs have been deserialized.").arg(this->_body.size()));
        return false;
    }

    QByteArray DataChunk::ToByteArray() const
    {
        QByteArray result;
        for (const auto& msg : _head)
        {
            result.append(msg->ToByteArray());
        }
        for (const auto& epoch : _body)
        {
            for (const auto& msg : epoch->Messages)
            {
                result.append(msg->ToByteArray());
            }
        }
        return result;
    }

    bool DataChunk::AddMessage(Message::UniquePtr_t msg)
    {
        bool gotNewEpoch = false;
        if (msg->Kind() == EMessageKind::StdMessage)
        {
            auto stdMsg = dynamic_cast<StdMessage*>(msg.get());
            if (stdMsg->IdNumber() == EMessageId::RcvTime)
            {
                if (dateTimeIsSet())
                {
                    // This message is a part of a new epoch. 
                    // We should assign the dateTime value to the current epoch and push it to the epochs container.
                    _lastEpoch->DateTime = _dateTime;
                    _body.push_back(std::move(_lastEpoch));
                    // push in the previous epoch
                    if (++_epochCounter % 3000 == 0)
                    {
                        sLogger.Trace(QString("3000 epochs deserialized. %1 total.").arg(_body.size()));
                    }
                    _lastEpoch = make_unique<Epoch>();
                    gotNewEpoch = true;
                }

                updateTimePart(dynamic_cast<RcvTimeStdMessage*>(stdMsg));
            }
            if (stdMsg->IdNumber() == EMessageId::RcvDate)
            {
                updateDatePart(dynamic_cast<RcvDateStdMessage*>(stdMsg));
            }
        }
        _lastEpoch->Messages.push_back(std::move(msg));
        return gotNewEpoch;
    }

    DataChunk::DataChunk()
    {
        _dateTime.setTimeSpec(Qt::UTC);
        _epochCounter = 0;
        _dateIsSet = false;
        _timeIsSet = false;
        _lastEpoch = make_unique<Epoch>();
    }
}
