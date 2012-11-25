#include "DataChunk.h"
#include "FileBinaryStream.h"
#include "ProjectBase/SmartPtr.h"

using namespace ProjectBase;

namespace Greis
{
    DataChunk::UniquePtr_t DataChunk::FromFile(QString filename)
    {
        auto jpsFile = DataChunk::UniquePtr_t(new DataChunk());
        GreisMessageStream stream(std::make_shared<FileBinaryStream>(filename), false, false);
        
        // Collecting the head
        Message::UniquePtr_t msg;
        int index = 0;
        while((msg = stream.Next()).get())
        {
            if (msg->Kind() == EMessageKind::StdMessage)
            {
                auto stdMsg = dynamic_cast<StdMessage*>(msg.get());
                if (stdMsg->IdNumber() == EMessageId::RcvTime)
                {
                    jpsFile->updateTimePart(dynamic_cast<RcvTimeStdMessage*>(stdMsg));
                    break;
                }
                if (stdMsg->IdNumber() == EMessageId::RcvDate)
                {
                    jpsFile->updateDatePart(dynamic_cast<RcvDateStdMessage*>(stdMsg));
                }
            }
            if (index++ < 6)
            {
                // Only first 6 messages are actually collected (JP, \r, \n, MF, \r, \n).
                // PM messages are ignored.
                jpsFile->_head.push_back(std::move(msg));
            }
        }
        // if the head collection was interrupted by a RcvTime message, move it to the first epoch
        if (msg.get())
        {
            jpsFile->_lastEpoch->Messages.push_back(std::move(msg));
        }
        // Collecting a body
        while((msg = stream.Next()).get())
        {
            jpsFile->AddMessage(std::move(msg));
        }
        // last Epoch
        if (jpsFile->_lastEpoch->Messages.size() > 0)
        {
            jpsFile->_lastEpoch->DateTime = jpsFile->_dateTime;
            jpsFile->_body.push_back(std::move(jpsFile->_lastEpoch));
        }

        sLogger.Info(QString("%1 epochs have been totally deserialized.").arg(jpsFile->_epochCounter));
        return jpsFile;
    }

    QByteArray DataChunk::ToByteArray() const
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

    void DataChunk::AddMessage( Message::UniquePtr_t msg )
    {
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
                        sLogger.Info(QString("3000 epochs deserialized. %1 total.").arg(_epochCounter));
                    }
                    _lastEpoch = make_unique<Epoch>();
                }

                updateTimePart(dynamic_cast<RcvTimeStdMessage*>(stdMsg));
            }
            if (stdMsg->IdNumber() == EMessageId::RcvDate)
            {
                updateDatePart(dynamic_cast<RcvDateStdMessage*>(stdMsg));
            }
        }
        _lastEpoch->Messages.push_back(std::move(msg));
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
