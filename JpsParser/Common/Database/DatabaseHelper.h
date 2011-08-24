#ifndef ExceptionHelper_h__
#define ExceptionHelper_h__

#include <QtCore/QtCore>
#include <QtSql/QtSql>

class DatabaseHelper
{
private:
    QSqlDatabase _db;
public:
    DatabaseHelper(const QSqlDatabase& db) : _db(db)
    {
    }

    static void ThrowIfError(const QSqlQuery& query)
    {
        if (query.lastError().isValid())
        {
            throw DatabaseException(query.lastError().text());
        }
    }

    inline QSqlQuery ExecuteQuery(const QString& queryString)
    {
        return ExecuteQuery(queryString, _db);
    }

    static QSqlQuery ExecuteQuery(const QString& queryString, QSqlDatabase db/* = QSqlDatabase()*/)
    {
        QSqlQuery query(queryString, db);
        ThrowIfError(query);
        return query;
    }

    inline QSqlQuery ExecuteSingleRowQuery(const QString& queryString)
    {
        return ExecuteSingleRowQuery(queryString, _db);
    }

    static QSqlQuery ExecuteSingleRowQuery(const QString& queryString, QSqlDatabase db/* = QSqlDatabase()*/)
    {
        QSqlQuery query = ExecuteQuery(queryString, db);
        if (!query.next())
        {
            throw DatabaseException(QString("Запрос '%1' вернул 0 записей. Ожидалась 1 запись.").arg(queryString));
        }
        return query;
    }

    inline QVariant ExecuteSingleValueQuery(const QString& queryString)
    {
        return ExecuteSingleValueQuery(queryString, _db);
    }

    static QVariant ExecuteSingleValueQuery(const QString& queryString, QSqlDatabase db/* = QSqlDatabase()*/)
    {
        QSqlQuery query = ExecuteSingleRowQuery(queryString, db);
        QVariant value = query.value(0);
        if (!value.isValid())
        {
            throw DatabaseException(QString("Запрос '%1' вернул некорректное значение для index = 0.").arg(queryString));
        }
        return value;
    }
};

#endif // ExceptionHelper_h__