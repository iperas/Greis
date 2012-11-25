#pragma once

#include "MySqlSink.h"
#include "ProjectBase\Connection.h"
#include "ProjectBase\SmartPtr.h"
#include "DataChunk.h"

using namespace ProjectBase;

class ChainedSink
{
private:
    Greis::MySqlSink::UniquePtr_t _sink;
    std::unique_ptr<ChainedSink> _nextChainedSink;
    Connection::SharedPtr_t _connection;
public:
    SMART_PTR_T(ChainedSink);

    ChainedSink(Connection::SharedPtr_t connection, int inserterBatchSize, ChainedSink::UniquePtr_t nextSink)
        : _nextChainedSink(std::move(nextSink)), _connection(connection)
    {
        _connection->Connect();
        _sink = make_unique<Greis::MySqlSink>(connection.get(), inserterBatchSize);
    }

    bool Handle(Greis::DataChunk::UniquePtr_t dataChunk)
    {
        try
        {
            _connection->Database().transaction();

            for (auto it = dataChunk->Body().begin();
                 it != dataChunk->Body().end();
                 ++it)
            {
                _sink->AddEpoch((*it)->DateTime);
                for (auto msgIt = (*it)->Messages.begin();
                     msgIt != (*it)->Messages.end();
                     ++msgIt)
                {
                    _sink->AddMessage(msgIt->get());
                }
            }

            _connection->Database().commit();
        }
        catch (Exception& e)
        {
            _connection->Database().rollback();
            sLogger.Info("Transaction has been rolled back.");
            sLogger.Error(e.what());
            return false;
        }

        return _nextChainedSink->Handle(std::move(dataChunk));
    }

    void Flush()
    {
        _sink->Flush();
        _nextChainedSink->Flush();
    }
};