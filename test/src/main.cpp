#include <QtCore/QtCore>
#include <clocale>
#include <locale>
#include <iostream>
#include "common/Logger.h"
#include "common/Path.h"
#include "common/Connection.h"
#include "greis/DataChunk.h"
#include "extras/SkyPeek.h"
#include "greis/FileBinaryStream.h"
#include "greis/ChecksumComputer.h"
#include "greis/StdMessage/RcvDateStdMessage.h"
#include "greis/StdMessage/EpochTimeStdMessage.h"
#include "greis/StdMessage/FileIdStdMessage.h"
#include "greis/StdMessage/MsgFmtStdMessage.h"
#include "greis/StdMessage/ParamsStdMessage.h"

using namespace Common;
using namespace Greis;


    int main(int argc, char** argv)
    {
        try {
                QCoreApplication a(argc, argv);
                QTextCodec* codec = QTextCodec::codecForName("UTF-8");
                QTextCodec::setCodecForLocale(codec);

                int LogLevel = 3;
                sLogger.Initialize(LogLevel);

                QStringList args = a.arguments();
                QRegExp rxIn("([\\/A-Za-z\\.0-9\\-\\_\\!\\~]+)");
                
                QString inFileName;
                bool skyPeekMode = true;

                if(rxIn.indexIn(args.at(args.size()-1)) != -1){
                    inFileName=rxIn.cap(1);
                } else {
                    throw 1;
                }

 
                auto skyPeek = make_unique<SkyPeek>();
                auto file = make_unique<DataChunk>();
                auto target = make_unique<DataChunk>();
                GreisMessageStream stream(std::make_shared<FileBinaryStream>(inFileName), true);
                file->ReadHead(stream);
                bool hasMore; int epochCounter = 0;
                std::cout << QString("{").toStdString();
                bool jsonT1SeparatorFlag = false;
                do
                {
                    hasMore = file->ReadBody(stream, 10);
                    for (auto& epoch : file->Body())
                    {
                        if(jsonT1SeparatorFlag){
                            std::cout << QString(",").toStdString();
                            std::cout << std::endl;
                        }
                        std::cout << QString("\"%1\":{").arg(epoch->DateTime.toString(Qt::ISODate)).toStdString();     
                                    for (auto& msg : epoch->Messages)
                                        {
                                            auto sMsg = static_cast<Greis::StdMessage*>(msg.get());
                                            skyPeek->AddMessage(msg.get());
                                        }
                                        std::cout << std::endl;
                                for (int i=0;i< skyPeek->SVs.size(); i++)
                                {
                                    SkyPeek::SV SV = skyPeek->SVs[i];
                                    std::cout << QString("\"%3\":{\"SSID\": %1, \"SVID\": %2, ").arg(SV.ESI.SSID).arg(SV.ESI.SVID).arg(SV.USI).toStdString();
                                    std::cout << QString("\"Asys\": %1, \"Ksys\": %2, ").arg(SV.Asys).arg(SV.Ksys).toStdString();
                                    std::cout << QString("\"PR\": {\"CA/L1\": %2, \"P/L1\": %3, ").arg(SV.Pseudorange[SkyPeek::Signals::caL1]).arg(SV.Pseudorange[SkyPeek::Signals::pL1]).toStdString();
                                    std::cout << QString("\"P/L2\": %1, \"CA/L2\": %2, \"P/L5\": %3}, ").arg(SV.Pseudorange[SkyPeek::Signals::pL2]).arg(SV.Pseudorange[SkyPeek::Signals::caL2]).arg(SV.Pseudorange[SkyPeek::Signals::L5]).toStdString();
                                    std::cout << QString("\"CP\":{\"CA/L1\": %1, \"P/L1\": %2, \"P/L2\": %3, ").arg(SV.CarrierPhase[SkyPeek::Signals::caL1]).arg(SV.CarrierPhase[SkyPeek::Signals::pL1]).arg(SV.CarrierPhase[SkyPeek::Signals::pL2]).toStdString();
                                    std::cout << QString("\"CA/L2\": %1, \"P/L5\": %2}, ").arg(SV.CarrierPhase[SkyPeek::Signals::caL2]).arg(SV.CarrierPhase[SkyPeek::Signals::L5]).toStdString();
                                    std::cout << QString("\"AZ\": %2, \"EL\": %1}").arg(SV.Elevation).arg(SV.Azimuth).toStdString();
                                    if (i<skyPeek->SVs.size()-1) std::cout << QString(",").toStdString();
                                    std::cout << std::endl;
                                }
                                
                                std::cout << QString("}").toStdString();
                                jsonT1SeparatorFlag = true;    
                            }
                            epochCounter++;
                    file->Body().clear();
                } while (hasMore);
                std::cout << QString("}").toStdString();
                return 0;
            }
            catch (Exception& e)
            {
                sLogger.Error("An error has occurred");
                sLogger.Error(e.what());
                return 1;
            }
}
