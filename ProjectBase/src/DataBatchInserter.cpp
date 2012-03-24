#include "DataBatchInserter.h"
#include "Logger.h"

namespace ProjectBase
{
    DataBatchInserter::DataBatchInserter(const QString& insertQuery, int boundColumnsCount, Connection* connection, 
                                         const QString& tableName, int batchSize)
    {
        _insertQuery = insertQuery;
        _connection = connection;
        _dbHelper = _connection->DbHelper();
        _rowsAdded = 0;
        _batchSize = batchSize;
        _boundValues.resize(boundColumnsCount);
        _tableName = tableName;
    }

    DataBatchInserter::~DataBatchInserter()
    {
        Flush();
    }

    void DataBatchInserter::AddChild(DataBatchInserter::SharedPtr_t child)
    {
        _children.push_back(child);
    }

    void DataBatchInserter::AddRow(const QList<QVariant>& values)
    {
        if (values.size() != _boundValues.size())
        {
            throw InvalidOperationException(
                QString("Invalid elements count in `AddRow(values)` array. Actual: %1. Expected: %2.").
                arg(values.size()).arg(_boundValues.size()));
        }
        if (_rowsAdded >= _batchSize)
        {
            Flush();
        }

        for (int i = 0; i < _boundValues.size(); ++i)
        {
            _boundValues[i].append(values.at(i));
        }
        _rowsAdded++;
    }

    void DataBatchInserter::Flush()
    {
        if (_rowsAdded > 0)
        {
            foreach (DataBatchInserter::SharedPtr_t child, _children)
            {
                child->Flush();
            }
            QSqlQuery query = _dbHelper->ExecuteQuery("");
            sLogger.Debug(_insertQuery);
            query.prepare(_insertQuery);
            DatabaseHelper::ThrowIfError(query);
            foreach (QVariantList boundValue, _boundValues)
            {
                query.addBindValue(boundValue);
            }
            query.execBatch();
            DatabaseHelper::ThrowIfError(query);

            if (_tableName.isEmpty() || _tableName.isNull())
            {
                sLogger.Info(QString("%1 records has been added.").arg(_rowsAdded));
            } else {
                sLogger.Info(QString("%1 records has been added into `%2`.").arg(_rowsAdded).arg(_tableName));
            }
            _rowsAdded = 0;
            int size = _boundValues.size();
            _boundValues.clear();
            _boundValues.resize(size);
        }
    }
}
