#ifndef DatabaseWriter_h__
#define DatabaseWriter_h__

#include <QtCore/QtCore>
#include <QtSql/QtSql>
#include <memory>
#include "Common/Exceptions/DatabaseException.h"
#include "Common/Database/DatabaseHelper.h"
#include "Util/IniSettings.h"
#include "Util/Logger.h"
#include "Common/Database/DataInserter.h"
#include "Common/Database/Connection.h"
#include "JpsFile.h"

using Greis::JpsFile_t;

class DatabaseWriter
{
private:
    bool _connected;
    Connection _connection;
    DatabaseHelper* _dbHelper;
    QMap<QString,QString> _columnsMap;
    int _dataSourceId;
    QString _unixTimeColumn;
    QString _dataTable;
    double _maxDateTime;
public:
    DatabaseWriter()
    {
        _unixTimeColumn = "UT";
        _connected = false;
    }

    inline double MaxDateTime() const { return _maxDateTime; }

    void Connect(const Connection& ci, const QString& sourceName)
    {
        _connection = ci;
        _connection.Connect();
        _dbHelper = _connection.DbHelper();
        
        /* reading structure */
        // dataTable name
        _dataSourceId = _dbHelper->ExecuteSingleValueQuery(QString("SELECT Id FROM DataSource WHERE Name = '%1'").arg(sourceName)).toInt();
        _dataTable = _dbHelper->ExecuteSingleValueQuery(QString("SELECT DataTable FROM DataSource WHERE Id = %1").arg(_dataSourceId)).toString();
        // columns mapping
        QSqlQuery query = _dbHelper->ExecuteQuery(QString("SELECT RawDataColumnName, DataTableColumnName FROM Channel WHERE DataSourceId = %1").arg(_dataSourceId));
        while(query.next())
        {
            QString rawDataColumn = query.value(0).toString();
            QString tableColumn = query.value(1).toString();
            _columnsMap[rawDataColumn] = tableColumn;
        }
        // maxDateTime
        _maxDateTime = 0;
        if (_dbHelper->ExecuteSingleValueQuery(QString("SELECT COUNT(*) FROM %2").arg(_dataTable)).toInt() > 0)
        {
            _maxDateTime = _dbHelper->ExecuteSingleValueQuery(QString("SELECT MAX(%1) FROM %2").
                arg(_columnsMap[_unixTimeColumn]).arg(_dataTable)).toDouble();
        }

        _connected = true;
    }

    void AddData(JpsFile_t::Pointer_t jpsFile)
    {
        sLogger.Info(QString("Добавление данных из источника '%1' в базу данных...").arg(jpsFile->filename()));
        /*QVector<QString> insertingColumns;
        QVector<int> insertingIndexes;
        int unixTimeColumnIndex;

        // если нечего добавлять, выход
        if (table->Rows.count() == 0)
        {
            sLog.addWarning(QString("В источнике '%1' нет строк для добавления.").arg(table->Name));
            return;
        }
        if (table->Rows.first().count() == 0)
        {
            sLog.addWarning(QString("В источнике '%1' нет стобцов.").arg(table->Name));
            return;
        }

        // Определение столбцов
        int index = 0;
        foreach(string rawDataColumnStr, table->Columns)
        {
            QString rawDataColumn = QString::fromStdString(rawDataColumnStr);
            if (!_columnsMap.contains(rawDataColumn))
            {
                sLog.addWarning(QString("Столбец исходных данных %1 источника '%2' не найден в описании источника.").arg(rawDataColumn).arg(table->Name));
            } else {
                if (rawDataColumn == _unixTimeColumn)
                {
                    unixTimeColumnIndex = index;
                }
                insertingColumns.push_back(_columnsMap[rawDataColumn]);
                insertingIndexes.push_back(index++);
            }
        }

        // Выход если их нет
        if (insertingColumns.count() == 0)
        {
            sLog.addWarning(QString("В источнике '%1' не найдено столбцов с данными для добавления.").arg(table->Name));
            return;
        }

        // шаблон для инсерта
        QString insertTemplate(QString("INSERT INTO %1(").arg(_dataTable));
        foreach(QString colHeader, insertingColumns)
        {
            insertTemplate.append(colHeader);
            insertTemplate.append(", ");
        }
        insertTemplate.remove(insertTemplate.count() - 2, 2);
        insertTemplate.append(") VALUES ");

        DataInserter dataInserter(insertTemplate, &_connection);

        // выборка по времени
        int rowsCountInDb = _dbHelper->ExecuteSingleValueQuery(QString("SELECT count(*) FROM %1").arg(_dataTable)).toInt();
        bool truncateEnabled = rowsCountInDb > 0; // таблица не пуста, требуется игнорировать входные данные, если они внутри интервала базы
        double startTimeInDb;
        double endTimeInDb;
        if (truncateEnabled)
        {
            startTimeInDb = _dbHelper->ExecuteSingleValueQuery(QString("SELECT min(%1) FROM %2").arg(_columnsMap.value(_unixTimeColumn)).arg(_dataTable)).toDouble();
            endTimeInDb = _dbHelper->ExecuteSingleValueQuery(QString("SELECT max(%1) FROM %2").arg(_columnsMap.value(_unixTimeColumn)).arg(_dataTable)).toDouble();
        }
        for(QVector< QVector<double> >::const_iterator row = table->Rows.constBegin(); row != table->Rows.constEnd(); ++row)
        {
            double rowTime = (*row)[unixTimeColumnIndex];
            // -----------************---------- <- данные в базе
            // --------------------+------------ <- строка из базы
            if (truncateEnabled && rowTime <= endTimeInDb && rowTime >= startTimeInDb)
            {
                continue;
            }

            QString insertDataLine("(");
            insertDataLine.reserve(500);
            for (QVector<int>::iterator value = insertingIndexes.begin(); value != insertingIndexes.end(); ++value)
            {
                insertDataLine.append(QString("%1, ").arg((*row)[*value], 0, 'f'));
            }
            insertDataLine.remove(insertDataLine.count() - 2, 2);
            insertDataLine.append(")");
            
            dataInserter.AddRow(insertDataLine);
        }
        dataInserter.Flush();*/
        sLogger.Info(QString("...завершено."));
    }
};

#endif // DatabaseWriter_h__