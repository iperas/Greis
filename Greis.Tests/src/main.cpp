#include <clocale>
#include <locale>
#include <QtCore/QtCore>
#include <gtest/gtest.h>
#include "Common/Logger.h"
#include "Common/Path.h"

#include "tests.h"
#include "tests/EnvironmentTests.h"
#include "tests/MySqlSinkTests.h"
#include "tests/DataChunkTests.h"
#include "tests/MySqlSourceTests.h"
#include "tests/GreisBinarySerializerTests.h"
#include "tests/GreisMessageStreamTests.h"

using namespace Common;

int main(int argc, char **argv)
{
    std::setlocale(LC_ALL, "Russian_Russia.1251");
    std::locale::global(std::locale("Russian_Russia.1251"));

    QCoreApplication a(argc, argv);

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    //sLogger.Initialize(Path::Combine(Path::ApplicationDirPath(), "logger.config.xml"));
    sLogger.Initialize(5);
    sIniSettings.Initialize(Path::Combine(Path::ApplicationDirPath(), "config.test.ini"));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
