#ifndef ExceptionHelper_h__
#define ExceptionHelper_h__

#include <QtCore/QtCore>
#include <QtSql/QtSql>

namespace Database 
{
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
                auto text = query.lastError().text();
                throw DatabaseException(text);
            }
        }

        inline QSqlQuery CreateQuery()
        {
            return QSqlQuery(_db);
        }

        inline QSqlQuery ExecuteQuery(const QString& queryString)
        {
            return ExecuteQuery(queryString, _db);
        }

        // Executing query with query string `queryString` and unnamed input bind values `bindValues`.
        inline QSqlQuery ExecuteQuery(const QString& queryString, const QList<QVariant>& bindValues)
        {
            return ExecuteQuery(queryString, bindValues, _db);
        }

        static QSqlQuery ExecuteQuery(const QString& queryString, QSqlDatabase db/* = QSqlDatabase()*/)
        {
            QSqlQuery query(queryString, db);
            ThrowIfError(query);
            return query;
        }

        // Executing query with database `db`, query string `queryString` and unnamed input bind values `bindValues`.
        static QSqlQuery ExecuteQuery(const QString& queryString, const QList<QVariant>& bindValues, QSqlDatabase db/* = QSqlDatabase()*/)
        {
            QSqlQuery query(db);
            query.prepare(queryString);
            ThrowIfError(query);
            foreach (QVariant val, bindValues)
            {
                query.addBindValue(val);
            }
            query.exec();
            ThrowIfError(query);
            return query;
        }

        inline QSqlQuery ExecuteSingleRowQuery(const QString& queryString)
        {
            return ExecuteSingleRowQuery(queryString, _db);
        }

        inline QSqlQuery ExecuteSingleRowQuery(const QString& queryString, const QList<QVariant>& bindValues)
        {
            return ExecuteSingleRowQuery(queryString, bindValues, _db);
        }

        static QSqlQuery ExecuteSingleRowQuery(const QString& queryString, QSqlDatabase db/* = QSqlDatabase()*/)
        {
            QSqlQuery query = ExecuteQuery(queryString, db);
            if (!query.next())
            {
                throw DatabaseException(QString("The query '%1' has returned 0 records. One record was expected.").arg(queryString));
            }
            return query;
        }

        static QSqlQuery ExecuteSingleRowQuery(const QString& queryString, const QList<QVariant>& bindValues, QSqlDatabase db/* = QSqlDatabase()*/)
        {
            QSqlQuery query = ExecuteQuery(queryString, bindValues, db);
            if (!query.next())
            {
                throw DatabaseException(QString("The query '%1' has returned 0 records. One record was expected.").arg(queryString));
            }
            return query;
        }

        inline QVariant ExecuteSingleValueQuery(const QString& queryString)
        {
            return ExecuteSingleValueQuery(queryString, _db);
        }

        inline QVariant ExecuteSingleValueQuery(const QString& queryString, const QList<QVariant>& bindValues)
        {
            return ExecuteSingleValueQuery(queryString, bindValues, _db);
        }

        static QVariant ExecuteSingleValueQuery(const QString& queryString, QSqlDatabase db/* = QSqlDatabase()*/)
        {
            QSqlQuery query = ExecuteSingleRowQuery(queryString, db);
            QVariant value = query.value(0);
            if (!value.isValid())
            {
                throw DatabaseException(QString("The query '%1' has returned invalid value for index 0.").arg(queryString));
            }
            return value;
        }

        static QVariant ExecuteSingleValueQuery(const QString& queryString, const QList<QVariant>& bindValues, QSqlDatabase db/* = QSqlDatabase()*/)
        {
            QSqlQuery query = ExecuteSingleRowQuery(queryString, bindValues, db);
            QVariant value = query.value(0);
            if (!value.isValid())
            {
                throw DatabaseException(QString("The query '%1' has returned invalid value for index 0.").arg(queryString));
            }
            return value;
        }
    };
}

#endif // ExceptionHelper_h__