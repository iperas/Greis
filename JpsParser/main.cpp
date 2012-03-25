#include <QtCore/QtCore>
#include <iostream>
#include <clocale>
#include <locale>
#include "ProjectBase/Exception.h"
#include "ProjectBase/IniSettings.h"

#include "GreisMessage.h"
#include "GreisMessageStream.h"
#include "JpsFile.h"
#include "ProjectBase/FileException.h"

#include <fstream>
#include <algorithm>

using namespace std;
using namespace Greis;

#include "ProjectBase/Logger.h"
#include "ProjectBase/Path.h"
#include "ProjectBase/BitConverter.h"
#include "ProjectBase/Connection.h"
#include "Domain/MetaInfo.h"
#include "Domain/MySqlSink.h"
#include "Domain/MetaInfoReader.h"

#include "ProjectBase/ProjectBase.h"

using namespace ProjectBase;
using namespace Domain;

int main(int argc, char *argv[])
{
    bool transactionStarted = false;
    bool wrapIntoTransaction;
    Connection::SharedPtr_t connection;
    try
    {
        std::setlocale(LC_ALL, "Russian_Russia.1251");
        std::locale::global(std::locale("Russian_Russia.1251"));

        QCoreApplication a(argc, argv);

        // кодеки
        QTextCodec* codec = QTextCodec::codecForName("UTF-8");
        QTextCodec* codecMs = QTextCodec::codecForName("Windows-1251");
        QTextCodec::setCodecForCStrings(codecMs);
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForTr(codec);

        // static init
        sLogger.Initialize(Path::Combine(Path::ApplicationDirPath(), "logger.config.xml"));
        sIniSettings.Initialize(Path::Combine(Path::ApplicationDirPath(), "config.ini"));
        QStringList args = a.arguments();

        if (args.count() < 2)
        {
            sLogger.Error(QString("Invalid command line arguments. Usage: JpsParser <input Jps file>"));
            return 1;
        }
        QString filename = args[1];

        // Загрузка мета-информации
        wrapIntoTransaction = sIniSettings.value("WrapIntoTransaction", false).toBool();
        int inserterBatchSize = sIniSettings.value("inserterBatchSize", 10000).toInt();
        connection = Connection::FromSettings("Db");
        connection->Connect();
        MetaInfo::SharedPtr_t metaInfo = MetaInfo::FromDatabase(connection.get());

        EpochsReader er(metaInfo, connection.get());
        auto range = er.Load(QDateTime(QDate(2011, 03, 22), QTime(0, 0, 0), Qt::LocalTime), QDateTime(QDate(2011, 03, 22), QTime(5, 0, 1), Qt::LocalTime));
        
        QFile file(Path::Combine(Path::ApplicationDirPath(), "test_output.jps"));
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        QDataStream out(&file);

        out.writeRawData("JP055RLOGF JPS ALPHA Receiver Log File                                                    \r\nMF009JP010109F", 106);
        file.flush();
        foreach (StdMessage_t::SharedPtr_t msg, range->EpochsByTime)
        {
            out.writeRawData("\r\n", 2);
            out.writeRawData(msg->message(), msg->fullSize());
            file.flush();
        }
        file.close();

        return 0;
        // Открытие JPS-файла и парсинг
        sLogger.Info(QString("Parsing of '%1'...").arg(filename));
        JpsFile_t::SharedPtr_t jpsFile(new JpsFile_t(filename));
        sLogger.Info(QString("Parsing completed."));
        sLogger.Info(QString("Inserting parsed data into `%1`...").arg(connection->DatabaseName));
        if (wrapIntoTransaction)
        {
            sLogger.Info("Starting a new transaction...");
            transactionStarted = connection->Database().transaction();
        }
        MySqlSink::SharedPtr_t sink(new MySqlSink(metaInfo, connection.get(), inserterBatchSize));
        jpsFile->toMySqlSink(sink);
        sink->Flush();
        if (wrapIntoTransaction && transactionStarted)
        {
            connection->Database().commit();
            sLogger.Info("The transaction has been committed.");
        }
        sLogger.Info(QString("Insertion completed."));
#ifdef _DEBUG
        system("PAUSE");
#endif
        return 0;
    }
    catch (Exception& e)
    {
        if (wrapIntoTransaction && transactionStarted)
        {
            connection->Database().rollback();
            sLogger.Info("The transaction has been rolled back.");
        }
        sLogger.Error(e.what());
        return 1;
    }
}
