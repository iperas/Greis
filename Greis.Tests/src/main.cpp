#include <clocale>
#include <locale>
#include <QtCore/QtCore>
#include <gtest/gtest.h>
#include "Common/Logger.h"
#include "Common/Path.h"

#include "tests.h"

using namespace Common;

int main(int argc, char **argv)
{
    QCoreApplication a(argc, argv);

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    //sLogger.Initialize(Path::Combine(Path::ApplicationDirPath(), "logger.config.xml"));
    sLogger.Initialize(5);
    sIniSettings.Initialize(Path::Combine(Path::ApplicationDirPath(), "config.test.ini"));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
