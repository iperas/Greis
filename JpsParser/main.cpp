#include <QtCore/QtCore>
#include <iostream>
#include <clocale>
#include <locale>
#include "Util/Exception.h"
#include "Util/IniSettings.h"

#include "GreisMessage.h"
#include "GreisMessageStream.h"
#include "JpsFile.h"
#include "Util/FileException.h"
#include "DatabaseWriter.h"

#include <fstream>
#include <algorithm>

using namespace std;
using namespace Greis;

#include "Util/Logger.h"
#include "Util/Path.h"
#include "Util/BitConverter.h"
#include "Domain/MetaInfo.h"
#include "Domain/MySqlSink.h"

using namespace Util;
using namespace Domain;
using namespace Database;

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    // ## TESTS ##
    Tests::BitConverterTests bct;
    bct.TestLittleEndian();
#endif

    bool transactionStarted;
    bool wrapIntoTransaction;
    Connection connection;
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
        connection.Connect();
        MetaInfo::Pointer_t metaInfo = MetaInfo::FromDatabase(&connection);
        // Открытие JPS-файла и парсинг
        sLogger.Info(QString("Parsing of '%1'...").arg(filename));
        JpsFile_t::Pointer_t jpsFile(new JpsFile_t(filename));
        sLogger.Info(QString("Parsing completed."));
        sLogger.Info(QString("Inserting parsed data into `%1`...").arg(connection.DatabaseName));
        if (wrapIntoTransaction)
        {
            sLogger.Info("Starting a new transaction...");
            transactionStarted = connection.Database().transaction();
        }
        MySqlSink::Pointer_t sink(new MySqlSink(metaInfo, &connection, inserterBatchSize));
        jpsFile->toMySqlSink(sink);
        sink->Flush();
        if (wrapIntoTransaction && transactionStarted)
        {
            connection.Database().commit();
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
            connection.Database().rollback();
            sLogger.Info("The transaction has been rolled back.");
        }
        sLogger.Error(e.what());
        return 1;
    }
}
