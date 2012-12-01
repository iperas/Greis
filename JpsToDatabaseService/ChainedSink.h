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
	int _inserterBatchSize;
	bool _isValid;
public:
    SMART_PTR_T(ChainedSink);

    ChainedSink(Connection::SharedPtr_t connection, int inserterBatchSize, ChainedSink::UniquePtr_t nextSink)
        : _nextChainedSink(std::move(nextSink)), _connection(connection), _inserterBatchSize(inserterBatchSize)
    {
		Connect();
    }

	bool Connect()
	{
		try
		{
			if (IsValid())
			{
				return _isValid = true;
			}

			_connection->Connect();
			_sink = make_unique<Greis::MySqlSink>(_connection.get(), _inserterBatchSize);
			return _isValid = true;
		}
		catch (DatabaseException& ex)
		{
			sLogger.Warn("An error occurred while connecting to a database: " + ex.what());
			return _isValid = false;
		}
		catch (...)
		{
			_isValid = false;
			throw;
		}
	}

	bool IsValid() const
	{
		return _isValid && _connection->Database().isOpen();
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

		if (_nextChainedSink.get())
		{
			try
			{
				if (_nextChainedSink->Connect())
				{
					_nextChainedSink->Handle(std::move(dataChunk));
				}
			}
			catch (DatabaseException& ex)
			{
				sLogger.Warn("An error occurred while adding a data chunk into the data center database: " + ex.what());
			}
		}

		return true;
    }

    void Flush()
	{
		_connection->Database().transaction();

        _sink->Flush();
		if (_nextChainedSink.get())
		{
			try
			{
				if (_nextChainedSink->Connect())
				{
					_nextChainedSink->Flush();
				}
			}
			catch (DatabaseException& ex)
			{
				sLogger.Warn("An error occurred while flushing the data into the data center database: " + ex.what());
			}
		}

		_connection->Database().commit();
    }
};