#include <gtest/gtest.h>
#include "MySqlSinkTests.h"
#include "JpsFileTests.h"
#include "GreisBinarySerializerTests.h"
#include "GreisMessageStreamTests.h"
#include "ProjectBase/Logger.h"
#include "ProjectBase/Path.h"
#include <QtCore/QtCore>

using namespace ProjectBase;

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    sLogger.Initialize(Path::Combine(Path::ApplicationDirPath(), "logger.config.xml"));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
