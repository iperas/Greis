#ifndef DataBatchInserter_h__
#define DataBatchInserter_h__

#include <QtCore/QtCore>
#include "Util/Exception.h"
#include "Util/Logger.h"
#include "Connection.h"
#include "DatabaseHelper.h"
#include "Util/InvalidOperationException.h"
#include "Util/SharedPtr.h"

using Util::InvalidOperationException;

namespace Database 
{
    class DataBatchInserter
    {
        QString _insertQuery;
        int _rowsAdded;
        int _batchSize;
        Connection* _connection;
        DatabaseHelper* _dbHelper;
        QVector<QVariantList> _boundValues;
    public:
        SHARED_PTR_T(DataBatchInserter);

        // insertQuery: "INSERT INTO <table name>(<column name>[, <column name>]) VALUES (?, ?, ?)"
        // connection: pointer to connection class
        DataBatchInserter(const QString& insertQuery, int boundColumnsCount, Connection* connection, int batchSize = 1000)
        {
            _insertQuery = insertQuery;
            _connection = connection;
            _dbHelper = _connection->DbHelper();
            _rowsAdded = 0;
            _batchSize = batchSize;
            _boundValues.resize(boundColumnsCount);
        }

        ~DataBatchInserter()
        {
            Flush();
        }

        void AddRow(const QList<QVariant>& values)
        {
            if (values.size() != _boundValues.size())
            {
                throw InvalidOperationException("Invalid elements count in `AddRow(values)` array.");
            }
            if (_rowsAdded > _batchSize)
            {
                Flush();
            }

            for (int i = 0; i < _boundValues.size(); ++i)
            {
                _boundValues[i].append(values.at(i));
            }
            _rowsAdded++;
        }

        // execute all pending queries
        void Flush()
        {
            if (_rowsAdded > 0)
            {
                QSqlQuery query = _dbHelper->ExecuteQuery("");
                query.prepare(_insertQuery);
                DatabaseHelper::ThrowIfError(query);
                foreach (QVariantList boundValue, _boundValues)
                {
                    query.addBindValue(boundValue);
                }
                query.execBatch();
                DatabaseHelper::ThrowIfError(query);

                sLogger.Info(QString("Добавлено %1 записей...").arg(_rowsAdded));
                _rowsAdded = 0;
                int size = _boundValues.size();
                _boundValues.clear();
                _boundValues.resize(size);
            }
        }

        // returns pending query
        inline const QString& InsertQuery() const
        {
            return _insertQuery;
        }
    };
}

#endif // DataBatchInserter_h__