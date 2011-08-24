#ifndef DataInserter_h__
#define DataInserter_h__

#include <QtCore/QtCore>
#include "../Exceptions/Exception.h"
#include "../Log/Log.h"
#include "Connection.h"
#include "DatabaseHelper.h"

class DataInserter
{
    QString _resultInsertQuery;
    QString _insertTemplate;
    int _rowsAdded;
    Connection* _connection;
    DatabaseHelper* _dbHelper;
public:
    // insertTemplate: "INSERT INTO <table name>(<column name> [<column name>]) VALUES "
    // connection: pointer to connection class
    DataInserter(const QString& insertTemplate, Connection* connection)
    {
        _insertTemplate = insertTemplate;
        _resultInsertQuery = insertTemplate;
        _connection = connection;
        _dbHelper = _connection->DbHelper();
        _rowsAdded = 0;
    }

    // rowValueInBrackets: "(<value for col1> [<value for col #>])"
    void AddRow(const QString& rowValueInBrackets)
    {
        // Выполнение запроса если необходимо
        int resultLength = _resultInsertQuery.count() + rowValueInBrackets.count() + 10;
        if (resultLength > _connection->MaxAllowedPacket())
        {
            Flush();
        }

        if (_rowsAdded == 0)
        {
            _resultInsertQuery.append(" ");
        } else {
            _resultInsertQuery.append(", ");
        }
        _resultInsertQuery = _resultInsertQuery.append(rowValueInBrackets);
        _rowsAdded++;
    }

    // execute all pending queries
    void Flush()
    {
        if (_rowsAdded > 0)
        {
            _dbHelper->ExecuteQuery(ResultQuery());
            _resultInsertQuery = _insertTemplate;
            sLog.addInfo(QString("Добавлено %1 записей...").arg(_rowsAdded));
            _rowsAdded = 0;
        }
    }

    // returns pending query. Throws exception if now row was added till last flush.
    const QString& ResultQuery() const
    {
        if (_rowsAdded == 0)
        {
            throw Exception(QString("Невозможно построить запрос для шаблона %1. Не вставлено ниодной строки.").arg(_resultInsertQuery));
        }

        return _resultInsertQuery;
    }
};

#endif // DataInserter_h__