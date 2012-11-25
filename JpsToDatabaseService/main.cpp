#include <QtCore/QtCore>
#include <clocale>
#include <locale>
#include "ProjectBase/Logger.h"
#include "ProjectBase/SmartPtr.h"
#include "ProjectBase/Path.h"
#include "ProjectBase/Connection.h"
#include "DataChunk.h"
#include "MySqlSink.h"
#include "SerialPortBinaryStream.h"
#include "ChainedSink.h"

using namespace ProjectBase;
using namespace Greis;

int main(int argc, char **argv)
{
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

        // Message adding loop
        std::string portName = sIniSettings.value("PortName", "COM1").toString().toStdString();
        unsigned int baudRate = sIniSettings.value("BaudRate", 9600).toUInt();
        int inserterBatchSize = sIniSettings.value("inserterBatchSize", 10000).toInt();
        int dataChunkSize = sIniSettings.value("dataChunkSize", 10000).toInt();
        
        auto serialPort = std::make_shared<SerialPortBinaryStream>(portName, baudRate);
        serialPort->write("em,,def");
        GreisMessageStream stream(serialPort, false, false);
        Message::UniquePtr_t msg;
        auto dataChunk = make_unique<DataChunk>();
        int msgCounter = 0;
        auto dataCenterConnection = Connection::FromSettings("DataCenterDatabase");
        auto localConnection = Connection::FromSettings("LocalDatabase");
        auto chainedSink = make_unique<ChainedSink>(dataCenterConnection, inserterBatchSize, nullptr);
        while((msg = stream.Next()).get())
        {
            dataChunk->AddMessage(std::move(msg));
            if (msgCounter++ > dataChunkSize)
            {
                chainedSink->Handle(std::move(dataChunk));
                dataChunk = make_unique<DataChunk>();
                msgCounter = 0;
            }
        }
        chainedSink->Flush();

        return 0;
    }
    catch (Exception& e)
    {
        sLogger.Error(e.what());
        return 1;
    }
}
