#include "MySqlSink.h"
#include "ProjectBase\Connection.h"

using namespace ProjectBase;

namespace Greis
{
    void MySqlSink::construct()
    {
        _lastEpochId = _dbHelper->ExecuteSingleValueQuery(QString("SELECT MAX(`id`) FROM `epoch`")).toInt();
        _epochInserter = DataBatchInserter::SharedPtr_t(new DataBatchInserter(
            "INSERT INTO `epoch` (id, dt) VALUES (?, ?)", 2, _connection, "epoch", _inserterBatchSize));
    }

    MySqlSink::~MySqlSink()
    {
        Flush();
    }

    void MySqlSink::AddEpoch( QDateTime dateTime )
    {
        QVariantList data;
        data << ++_lastEpochId;
        data << dateTime.toMSecsSinceEpoch();
        _epochInserter->AddRow(data);
    }

    void MySqlSink::Flush()
    {
        foreach (DataBatchInserter::SharedPtr_t inserter, _msgInserters)
        {
            inserter->Flush();
        }
    }

    void MySqlSink::AddJpsFile( JpsFile* file )
    {
        for (auto epochIt = file->Body().cbegin(); epochIt != file->Body().cend(); ++epochIt)
        {
            AddEpoch((*epochIt)->DateTime);
            for (auto msgIt = (*epochIt)->Messages.cbegin(); msgIt != (*epochIt)->Messages.cend(); ++msgIt)
            {
                AddMessage(msgIt->get());
            }
        }
    }
}
