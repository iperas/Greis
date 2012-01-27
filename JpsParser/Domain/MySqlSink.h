#ifndef MySqlSink_h__
#define MySqlSink_h__

#include <QList>
#include "Database/Connection.h"
#include "Util/SharedPtr.h"
#include "MetaInfo.h"
#include "GreisMessage.h"
#include "Util/BitConverter.h"
#include "Tests/BitConverter.Tests.h"
#include "Util/NotSupportedException.h"

using namespace Database;
using namespace Greis;

namespace Domain
{
    class SimpleGreisTypesReader
    {
    private:
        BitConverter* _bitConverter;
    public:
        SimpleGreisTypesReader(BitConverter* bitConverter)
        {
            _bitConverter = bitConverter;

            Tests::BitConverterTests bct;
            bct.TestLittleEndian();
        }
    };

    class MySqlSink
    {
    private:
        MetaInfo::Pointer_t _metaInfo;
        Connection* _connection;
        DatabaseHelper* _dbHelper;

        QMap<QString, MessageMeta::Pointer_t> _codeToMsgMap;
    public:
        SHARED_PTR_T(MySqlSink);

        MySqlSink(MetaInfo::Pointer_t metaInfo, Connection* connection)
        {
            _metaInfo = metaInfo;
            _connection = connection;
            _dbHelper = _connection->DbHelper();

            foreach (MessageMeta::Pointer_t msg, _metaInfo->MessagesMeta)
            {
                foreach (MessageCode::Pointer_t code, msg->Codes)
                {
                    _codeToMsgMap[code->Code] = msg;
                }
            }
        }

        void AddMessage(StdMessage_t::Pointer_t msg, bool ignoreInvalidMessages = true)
        {
            // MessageMeta retrieving
            auto msgCode = QString::fromAscii(msg->id().c_str(), 2);
            auto msgMeta = _codeToMsgMap.value(msgCode, MessageMeta::Pointer_t());

            if (!msgMeta.get())
            {
                // Unknown message
                return;
            }

            // Validation
            if (msgMeta->Size >= 0)
            {
                if (msg->bodySize() != msgMeta->Size && !ignoreInvalidMessages)
                {
                    throw Exception(QString("Invalid size for message '%1': expected %2, actual %3.").
                        arg(msgMeta->Name).arg(msgMeta->Size).arg(msg->bodySize()));
                }
            }
            switch (msgMeta->Validation->Id)
            {
            case ValidationClassifier::Checksum:
                if (!msg->validateChecksum8bin() && !ignoreInvalidMessages)
                {
                    throw Exception(QString("Invalid checksum for message '%1'.").arg(msgMeta->Name));
                }
                break;
            case ValidationClassifier::ChecksumAsHexAscii:
                if (!msg->validateChecksum8ascii() && !ignoreInvalidMessages)
                {
                    throw Exception(QString("Invalid checksum for message '%1'.").arg(msgMeta->Name));
                }
                break;
            case ValidationClassifier::Crc16:
                // TODO
                break;
            }

            // Message insert template
            QString insertTemplate = QString("INSERT INTO `%1` (`idEpoch`, `%2`) VALUES ").arg(msgMeta->TableName);
            QStringList columnNames;
            foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
            {
                columnNames.append(varMeta->GetColumnName());
            }

            // Message values string
            BitConverter bitConverter;
            const char* msgPtr = msg->body();
            QString valuesString("(%1");
            foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
            {
                auto varType = varMeta->Type;
                if (varType == "a1")
                {
                    if (varMeta->IsScalar())
                    {
                        char a1 = bitConverter.GetChar(msgPtr);
                        msgPtr += 1;
                    } else if (varMeta->IsLinearArray())
                    {
                        switch (varMeta->GetSizeForDimension(1))
                        {
                        case SizeSpecialValueClassifier::Dynamic:
                            // TODO
                            break;
                        default:
                            QString varStr;
                            auto strLen = varMeta->GetSizeForDimension(1);
                            while (strLen--)
                            {
                                char a1 = bitConverter.GetChar(msgPtr++);
                                varStr.append(QChar::fromAscii(a1));
                            }
                            break;
                        }
                    } else {
                        throw NotSupportedException("Character arrays with dimension more than linear not supported.");
                    }
                } else if (varType == "i1")
                {

                } else if (varType == "i2")
                {

                } else if (varType == "i4")
                {

                } else if (varType == "u1")
                {

                } else if (varType == "u2")
                {

                } else if (varType == "u4")
                {

                } else if (varType == "f4")
                {

                } else if (varType == "f8")
                {

                } else {
                    // Custom type
                }
            }

            //valuesTemplate.append(", '%%2'");

            auto columnNamesStr = columnNames.join("`, `");
            insertTemplate = insertTemplate.arg((columnNamesStr));

            //BitConverter bitConverter;
            //SimpleGreisTypesReader reader(&bitConverter);

        }
    };
}

#endif // MySqlSink_h__