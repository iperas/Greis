#include <QtCore/QtCore>
#include <clocale>
#include <locale>
#include "ProjectBase/Logger.h"
#include "ProjectBase/Path.h"
#include "ProjectBase/Connection.h"
#include "JpsFile.h"
#include "MySqlSink.h"
#include "SerialPortBinaryStream.h"

using namespace ProjectBase;
using namespace Greis;

int main(int argc, char **argv)
{
    bool wrapIntoTransaction;
    Connection::SharedPtr_t dataCenterConnection;
    Connection::SharedPtr_t localConnection;
    try
    {
        std::setlocale(LC_ALL, "Russian_Russia.1251");
        std::locale::global(std::locale("Russian_Russia.1251"));

        QCoreApplication a(argc, argv);

        QTextCodec* codec = QTextCodec::codecForName("UTF-8");
        QTextCodec* codecMs = QTextCodec::codecForName("Windows-1251");
        QTextCodec::setCodecForCStrings(codecMs);
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForTr(codec);

        sLogger.Initialize(Path::Combine(Path::ApplicationDirPath(), "logger.config.xml"));
        sIniSettings.Initialize(Path::Combine(Path::ApplicationDirPath(), "config.ini"));

        //---
        auto serialPort = make_unique<SerialPortBinaryStream>("COM1", 115200);

        // Connecting to database
        wrapIntoTransaction = sIniSettings.value("WrapIntoTransaction", false).toBool();
        int inserterBatchSize = sIniSettings.value("inserterBatchSize", 10000).toInt();
        dataCenterConnection = Connection::FromSettings("DataCenterDatabase");
        dataCenterConnection->Connect();

        auto args = a.arguments();
        args.pop_front();

        foreach (QString filename, args)
        {
            sLogger.Info(QString("Reading file `%1`...").arg(filename));
            auto file = JpsFile::FromFile(filename);

            sLogger.Info(QString("Writing data into database `%1`...").arg(dataCenterConnection->DatabaseName));
            if (wrapIntoTransaction)
            {
                sLogger.Info("Starting a new transaction...");
                dataCenterConnection->Database().transaction();
            }
            {
                auto sink = make_unique<MySqlSink>(dataCenterConnection.get(), inserterBatchSize);
                sink->AddJpsFile(file.get());
                sink->Flush();
            }
            if (wrapIntoTransaction)
            {
                dataCenterConnection->Database().commit();
                sLogger.Info("Transaction has been committed.");
            }
            sLogger.Info(QString("Data from `%1` has been successfully imported into database.").arg(filename));
        }
        return 0;
    }
    catch (Exception& e)
    {
        if (wrapIntoTransaction)
        {
            dataCenterConnection->Database().rollback();
            sLogger.Info("Transaction has been rolled back.");
        }
        sLogger.Error(e.what());
        return 1;
    }
}
