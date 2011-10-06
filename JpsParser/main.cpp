#include <QtCore/QtCore>
#include <iostream>
#include <clocale>
#include <locale>
#include "Common/Exceptions/Exception.h"
#include "Common/Log/Log.h"
#include "Common/Settings/Settings.h"

#include "GreisMessage.h"
#include "GreisMessageStream.h"
#include "JpsFile.h"
#include "Common/Exceptions/FileException.h"
#include "DatabaseWriter.h"

#include <fstream>
#include <algorithm>

using namespace std;
using namespace Greis;

#include "Util/Logger.h"

void foo(void*)
{
    log4cxx::LoggerPtr logger = log4cxx::Logger::getRootLogger();
    for(int i=0;i<10;++i){
        LOG4CXX_DEBUG((logger),  L"debug" << L"other debug message");
        LOG4CXX_TRACE((logger),  L"trace");
        LOG4CXX_INFO((logger),  L"привет, мир!");
        LOG4CXX_WARN((logger),  L"WARN");
        LOG4CXX_ERROR((logger),  L"error");
        LOG4CXX_FATAL((logger),  L"FATAL");
    }
}

#include <windows.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian_Russia.OCP");	//иначе русский не будет нормально работать

    TCHAR selfName[MAX_PATH];
    HMODULE hModule = GetModuleHandle(NULL);
    GetModuleFileName(hModule, selfName, _countof(selfName));
    std::wstring configFile(selfName);
    configFile.append(L".logconfig");
    log4cxx::xml::DOMConfigurator::configure(configFile);

    log4cxx::xml::DOMConfigurator::configure(L"D:/Documents/svn_ifz_ipg/Projects/trunk/src/JpsParser/JpsParser/logger.config.xml");

    for(int i=0;i<10;++i){
        foo(NULL);
        //_beginthread(foo,0,NULL);
    }

    std::cin.get();

    return 0;

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

        sLog.Initialize(false, QCoreApplication::applicationDirPath() + "/converter.log");
        sSettings.Initialize(QCoreApplication::applicationDirPath() + "/config.ini");
        QStringList args = a.arguments();

        if (args.count() < 2)
        {
            sLog.addError(QString("Invalid command line arguments. Usage: JpsParser <input Jps file>"));
            return 1;
        }
        QString filename = args[1];

#ifdef _DEBUG
        {
            string log1;
            StdMessageStream stream(filename);
            Message_t::Pointer_t msg;
            while((msg = stream.Next(true)).get())
            {
                log1.append(boost::shared_dynamic_cast<StdMessage_t>(msg)->id() + " ");
            }
            std::ofstream fileLog("jpsTrace.txt");
            fileLog.write(log1.c_str(), log1.size());
            fileLog.close();
        }
#endif

        // ќткрытие и парсинг
        JpsFile_t::Pointer_t jpsFile(new JpsFile_t(filename));
        // «апись в базу
        /*Connection connection = Connection::FromSettings("Db");
        DatabaseWriter writer;
        writer.Connect(connection, "source1");
        writer.AddData(jpsFile);*/

#ifdef _DEBUG
        std::ofstream jps2("jps2.jps");
        jpsFile->toBinaryStream(jps2);
        jps2.close();
#endif

        //sLog.addInfo(QString("ќбработка успешно завершена."));
        system("PAUSE");
        return 0;
    }
    catch (Exception& e)
    {
        sLog.addError(e.what());
        return 1;
    }
}
