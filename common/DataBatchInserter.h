#ifndef DataBatchInserter_h__
#define DataBatchInserter_h__

#include <QtCore/QtCore>
#include "Exception.h"
#include "Connection.h"
#include "DatabaseHelper.h"
#include "InvalidOperationException.h"
#include "SmartPtr.h"

namespace Common 
{
    class DataBatchInserter
    {
    public:
        SMART_PTR_T(DataBatchInserter);
        DataBatchInserter(const DataBatchInserter&) = delete;
        DataBatchInserter& operator=(const DataBatchInserter&) = delete;
    private:
        QString _insertQuery;
        QString _tableName;
        int _rowsAdded;
        int _batchSize;
        Connection::SharedPtr_t _connection;
        DatabaseHelper* _dbHelper;
        QVector<QVariantList> _boundValues;
        QList<DataBatchInserter::SharedPtr_t> _children;
    public:
        // insertQuery: "INSERT INTO <table name>(<column name>[, <column name>]) VALUES (?, ?, ?)"
        // connection: pointer to connection class
        DataBatchInserter(const QString& insertQuery, int boundColumnsCount, Connection::SharedPtr_t connection, 
                          const QString& tableName = "", int batchSize = 1000);

        ~DataBatchInserter();

        void AddChild(DataBatchInserter::SharedPtr_t child);

        const QList<DataBatchInserter::SharedPtr_t>& GetChildren() const { return _children; }

        void AddRow(const QList<QVariant>& values);
        void Clear();
        // execute all pending queries
        void Flush();

        // returns pending query
        inline const QString& InsertQuery() const
        {
            return _insertQuery;
        }
    };
}

#endif // DataBatchInserter_h__
