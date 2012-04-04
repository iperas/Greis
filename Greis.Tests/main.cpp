#include <QtCore/QtCore>
#include <clocale>
#include <locale>
#include <gtest/gtest.h>
#include "MySqlSourceTests.h"
#include "JpsFileTests.h"
#include "MySqlSinkTests.h"
#include "GreisBinarySerializerTests.h"
#include "GreisMessageStreamTests.h"
#include "ProjectBase/Logger.h"
#include "ProjectBase/Path.h"

using namespace ProjectBase;

int main(int argc, char **argv)
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
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
