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
#include "FileBinaryStream.h"

using namespace ProjectBase;
using namespace Greis;

bool startLoop()
{
	SerialPortBinaryStream::SharedPtr_t serialPort;
	//FileBinaryStream::SharedPtr_t fs;
	ChainedSink::UniquePtr_t dataCenterSink;
	ChainedSink::UniquePtr_t localSink;
	try
	{
		std::string portName = sIniSettings.value("PortName", "COM3").toString().toStdString();
		unsigned int baudRate = sIniSettings.value("BaudRate", 1500000).toUInt();
		int inserterBatchSize = sIniSettings.value("inserterBatchSize", 250).toInt();
		int dataChunkSize = sIniSettings.value("dataChunkSize", 250).toInt();

		serialPort = std::make_shared<SerialPortBinaryStream>(portName, baudRate);
		serialPort->write("\nem,,def\n");

		/*auto file = ProjectBase::File::CreateBinary("serialPortData.jps");
		while (serialPort->serialPort().is_open())
		{
			char data[1024];
			int readc = boost::asio::read(serialPort->serialPort(), boost::asio::buffer(data, 1024));
			file->write(data, readc);
			file->flush();
		}
		file->close();*/
		/*char data1[1024];
		char data2[1024];
		char data3[1024];
		char data4[1024];
		char data5[1024];
		char data6[1024];
		serialPort->peek(data1, 5);
		serialPort->peek(data2, 3);
		bool a1 = memcmp(data1, data2, 3) == 0;
		serialPort->peek(data3, 10);
		bool a2 = memcmp(data3, data1, 5) == 0;
		serialPort->read(data4, 15);
		bool a3 = memcmp(data3, data4, 10) == 0;
		serialPort->peek(data5, 10);
		serialPort->peek(data6, 15);
		bool a4 = memcmp(data5, data6, 10) == 0;
		serialPort->peek(data1, 1);
		bool a5 = memcmp(data1, data5, 1) == 0;*/
		//fs = std::make_shared<FileBinaryStream>("serialPortData.jps");

		GreisMessageStream stream(serialPort, true, false);
		Message::UniquePtr_t msg;
		auto dataChunk = make_unique<DataChunk>();
		int msgCounter = 0;
		auto dataCenterConnection = Connection::FromSettings("DataCenterDatabase");
		auto localConnection = Connection::FromSettings("LocalDatabase");
		dataCenterSink = make_unique<ChainedSink>(dataCenterConnection, inserterBatchSize, nullptr);
		localSink = make_unique<ChainedSink>(localConnection, inserterBatchSize, std::move(dataCenterSink));
		while((msg = stream.Next()).get())
		{
			dataChunk->AddMessage(std::move(msg));
			if (msgCounter++ > dataChunkSize)
			{
				localSink->Handle(std::move(dataChunk));
				dataChunk = make_unique<DataChunk>();
				msgCounter = 0;
			}
		}

		localSink->Flush();
		return true;
	}
	catch (GreisException& ex)
	{
		sLogger.Error("An error has occurred: " + ex.what());

		//sLogger.Error(QString::number(fs->pos()));
		if (localSink.get())
		{
			localSink->Flush();
		}

		if (serialPort.get() && serialPort->isOpen())
		{
			serialPort->write("\ndm\n");
			serialPort->close();
		}

		return false;
	}
}

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

		sLogger.Debug("The following sqldrivers are available:");
		auto sqlDrivers = QSqlDatabase::drivers();
		for (auto it = sqlDrivers.begin(); it != sqlDrivers.end(); it++)
		{
			QString sqlDriverName = *it;
			sLogger.Debug(sqlDriverName);
		}

		while (!startLoop())
		{
			sLogger.Error("Reopening the device and attempting to receive data again.");
		}

        return 0;
    }
    catch (Exception& e)
    {
        sLogger.Error(e.what());
        return 1;
    }
}
