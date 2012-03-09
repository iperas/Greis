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
#include "Util/NotImplementedException.h"
#include "Database/DataInserter.h"
#include "Database/DataBatchInserter.h"

using namespace Database;
using namespace Greis;

namespace Domain
{
    class MySqlSink
    {
    private:
        BitConverter _bitConverter;
        MetaInfo::Pointer_t _metaInfo;
        Connection* _connection;
        DatabaseHelper* _dbHelper;
        QMap<MessageMeta*, DataBatchInserter::Pointer_t> _msgInsertersMap;
        QMap<CustomTypeMeta*, DataBatchInserter::Pointer_t> _ctInsertersMap;
        DataBatchInserter::Pointer_t _epochInserter;
        QMap<CustomTypeMeta*, int> _ctAvailableId;
        int _lastEpochId;
        QStringList _unknownTypes;
        QMap<QString, MessageMeta::Pointer_t> _codeToMsgMap;
        QMap<QString, CustomTypeMeta::Pointer_t> _nameToCustomTypeMap;
        int _inserterBatchSize;
    public:
        SHARED_PTR_T(MySqlSink);

        MySqlSink(MetaInfo::Pointer_t metaInfo, Connection* connection, int inserterBatchSize = 10000)
        {
            _metaInfo = metaInfo;
            _connection = connection;
            _dbHelper = _connection->DbHelper();
            _inserterBatchSize = inserterBatchSize;

            foreach (MessageMeta::Pointer_t msg, _metaInfo->MessagesMeta)
            {
                foreach (MessageCode::Pointer_t code, msg->Codes)
                {
                    _codeToMsgMap[code->Code] = msg;
                }
            }

            foreach (CustomTypeMeta::Pointer_t ct, _metaInfo->CustomTypesMeta)
            {
                _nameToCustomTypeMap[ct->Name] = ct;
            }

            _lastEpochId = _dbHelper->ExecuteSingleValueQuery(QString("SELECT MAX(`id`) FROM `epoch`")).toInt();
            _epochInserter = DataBatchInserter::Pointer_t(new DataBatchInserter(
                "INSERT INTO `epoch` (id, dt) VALUES (?, ?)", 2, _connection, "epoch", _inserterBatchSize));
        }

        ~MySqlSink()
        {
            Flush();
        }

        void AddEpoch(QDateTime dateTime)
        {
            QVariantList data;
            data << ++_lastEpochId;
            //data << dateTime;
            data << dateTime.toMSecsSinceEpoch();
            _epochInserter->AddRow(data);
        }

        void AddMessage(StdMessage_t::Pointer_t msg, bool ignoreInvalidMessages = true)
        {
            // MessageMeta retrieving
            auto msgCodeStr = QString::fromAscii(msg->id().c_str(), 2);
            auto msgMeta = _codeToMsgMap.value(msgCodeStr, MessageMeta::Pointer_t());

            if (!msgMeta.get())
            {
                // Unknown message
                return;
            }

            if (!ignoreInvalidMessages)
            {
                validateMessage(msgMeta.get(), msg.get());
            }

            DataBatchInserter::Pointer_t inserter = getMsgInserter(msgMeta.get());
            
            int fillFieldsCount = msgMeta->GetFilledArrayFieldsSize(_metaInfo.get(), msg->bodySize());
            
            // Message code id finding
            auto msgCodeId = msgMeta->FindMessageCodeId(msg->message());
            if (msgCodeId == -1)
            {
                // Unknown message
                return;
            }

            try
            {
                const char* msgPtr = msg->body();
                QVariantList rowValues;
                rowValues.append(_lastEpochId);
                rowValues.append(msgCodeId);
                rowValues.append(msg->bodySize());
                serializeCustomType(msgMeta.get(), msgPtr, fillFieldsCount, rowValues);
                inserter->AddRow(rowValues);
            }
            catch (NotImplementedException& e)
            {
                sLogger.Warn(e.what());
            }
        }

        void serializeCustomType( CustomTypeMeta* msgMeta, const char* &dataPtr, int fillFieldsCount, QVariantList &sink ) 
        {
            foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
            {
                auto varType = varMeta->Type;
                if (varType == "a1")
                {
                    int typeSize = 1;
                    int fieldsCount;
                    if (varMeta->IsScalar())
                    {
                        fieldsCount = 1;
                    } else if (varMeta->IsLinearArray())
                    {
                        switch (varMeta->GetSizeForDimension(1))
                        {
                        case SizeSpecialValueClassifier::Dynamic:
                        case SizeSpecialValueClassifier::Fill:
                            fieldsCount = fillFieldsCount;
                            break;
                        default:
                            fieldsCount = varMeta->GetSizeForDimension(1);
                            break;
                        }
                    } else {
                        throw NotSupportedException("Character arrays with dimension more than linear are not supported.");
                    }
                    QString varStr;
                    while (fieldsCount-- > 0)
                    {
                        char a1 = _bitConverter.GetChar(dataPtr++);
                        varStr.append(QChar::fromAscii(a1));
                    }
                    sink.append(varStr);
                } else if (varType == "i1")
                {
                    int typeSize = 1;
                    if (varMeta->IsScalar())
                    {
                        char i1 = _bitConverter.GetChar(dataPtr++);
                        sink.append((int) i1);
                    } else 
                    {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else if (varType == "i2")
                {
                    int typeSize = 2;
                    if (varMeta->IsScalar())
                    {
                        short i2 = _bitConverter.GetShort(dataPtr);
                        dataPtr += typeSize;
                        sink.append((int) i2);
                    } else {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else if (varType == "i4")
                {
                    int typeSize = 4;
                    if (varMeta->IsScalar())
                    {
                        int i4 = _bitConverter.GetInt(dataPtr);
                        dataPtr += typeSize;
                        sink.append(i4);
                    } else {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else if (varType == "u1")
                {
                    int typeSize = 1;
                    if (varMeta->IsScalar())
                    {
                        unsigned char u1 = _bitConverter.GetUChar(dataPtr);
                        dataPtr += typeSize;
                        sink.append((unsigned int) u1);
                    } else {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else if (varType == "u2")
                {
                    int typeSize = 2;
                    if (varMeta->IsScalar())
                    {
                        unsigned short u2 = _bitConverter.GetUShort(dataPtr);
                        dataPtr += typeSize;
                        sink.append((unsigned int) u2);
                    } else {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else if (varType == "u4")
                {
                    int typeSize = 4;
                    if (varMeta->IsScalar())
                    {
                        unsigned int u4 = _bitConverter.GetUInt(dataPtr);
                        dataPtr += typeSize;
                        sink.append(u4);
                    } else {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else if (varType == "f4")
                {
                    int typeSize = 4;
                    if (varMeta->IsScalar())
                    {
                        float f4 = _bitConverter.GetFloat(dataPtr);
                        dataPtr += typeSize;
                        sink.append((double) f4);
                    } else {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else if (varType == "f8")
                {
                    int typeSize = 8;
                    if (varMeta->IsScalar())
                    {
                        double f8 = _bitConverter.GetDouble(dataPtr);
                        dataPtr += typeSize;
                        sink.append(f8);
                    } else {
                        QByteArray ba = getArrayValue(varMeta, dataPtr, fillFieldsCount, typeSize);
                        sink.append(ba);
                    }
                } else {
                    auto ct = _nameToCustomTypeMap[varType];
                    if (!ct.get())
                    {
                        if (!_unknownTypes.contains(varType))
                        {
                            sLogger.Warn(QString("Skipping unknown type `%1`...").arg(varType));
                            _unknownTypes.append(varType);
                        }
                        sink.append(QVariant(QVariant::UInt));
                    } else {
                        int typeSize = ct->Size;
                        BOOST_ASSERT(typeSize >= 0);

                        if (varMeta->IsScalar())
                        {
                            int id = handleCustomType(ct.get(), dataPtr);
                            dataPtr += typeSize;
                            sink.append(id);
                        } else {
                            int arraySize = getArraySizeInItems(varMeta, fillFieldsCount);
                            QByteArray ba;
                            while (arraySize-- > 0)
                            {
                                unsigned int id = handleCustomType(ct.get(), dataPtr);
                                dataPtr += typeSize;
                                char idBinary[4];
                                _bitConverter.ToByteArray(id, idBinary);
                                ba.append(idBinary, 4);
                            }
                            sink.append(ba);
                        }
                    }
                }
            }
        }

        void Flush()
        {
            foreach (DataBatchInserter::Pointer_t inserter, _msgInsertersMap)
            {
                inserter->Flush();
            }
        }

    private:
        

        // ‘ормирует данные и отправл€ет на ожидание вставки. ¬озвращает ID нового элемента.
        int handleCustomType(CustomTypeMeta* ct, const char* dataPtr)
        {
            auto inserter = getCtInserter(ct);
            int newId = _ctAvailableId[ct] + 1;

            int fillFieldsCount = -1;

            int typeSize = ct->Size;
            BOOST_ASSERT(typeSize >= 0);
            /*if (ct->Size == SizeSpecialValueClassifier::Fill)
            {
                fillFieldsCount = getFilledArrayFieldsSize(ct, msg->bodySize());
            }*/

            try
            {
                QVariantList rowValues;
                rowValues << newId;
                rowValues << _lastEpochId;
                rowValues << typeSize;
                serializeCustomType(ct, dataPtr, fillFieldsCount, rowValues);
                inserter->AddRow(rowValues);
            }
            catch (NotImplementedException& e)
            {
            }

            _ctAvailableId[ct] = newId;
            return newId;
        }

        int getArraySizeInItems(VariableMeta::Pointer_t varMeta, int fillFieldsCount)
        {
            int fieldsCount;
            switch (varMeta->GetSizeForDimension(1))
            {
            case SizeSpecialValueClassifier::Dynamic:
            case SizeSpecialValueClassifier::Fill:
                BOOST_ASSERT(fillFieldsCount >= 0);
                fieldsCount = fillFieldsCount;
                break;
            default:
                fieldsCount = varMeta->GetSizeForDimension(1);
                for (int i = 1; i < varMeta->GetDimensionsCount(); ++i)
                {
                    fieldsCount *= varMeta->GetSizeForDimension(i + 1);
                }
                break;
            }
            return fieldsCount;
        }

        // ¬ычисл€ет размер массива и копирует данные данного размера в результирующий массив
        QByteArray getArrayValue( VariableMeta::Pointer_t varMeta, const char* msgPtr, int fillFieldsCount, int typeSize ) 
        {
            int fieldsCount = getArraySizeInItems(varMeta, fillFieldsCount);
            QByteArray ba(msgPtr, fieldsCount * typeSize);
            msgPtr += fieldsCount * typeSize;
            return ba;
        }

        DataBatchInserter::Pointer_t getMsgInserter(MessageMeta* msgMeta)
        {
            DataBatchInserter::Pointer_t inserter;
            if ((inserter = _msgInsertersMap.value(msgMeta)).get())
            {
                return inserter;
            }

            inserter = createInserter(msgMeta, QStringList() << "idEpoch" << "idMessageCode" << "bodySize");
            _msgInsertersMap[msgMeta] = inserter;
            return inserter;
        }

        DataBatchInserter::Pointer_t getCtInserter(CustomTypeMeta* ctMeta)
        {
            DataBatchInserter::Pointer_t inserter;
            if ((inserter = _ctInsertersMap.value(ctMeta)).get())
            {
                return inserter;
            }

            inserter = createInserter(ctMeta, QStringList() << "id" << "idEpoch" << "bodySize");
            _ctInsertersMap[ctMeta] = inserter;

            int lastId = _dbHelper->ExecuteSingleValueQuery(QString("SELECT MAX(`id`) FROM `%1`").arg(ctMeta->TableName)).toInt();
            _ctAvailableId[ctMeta] = lastId + 1;

            return inserter;
        }

        // customFields - список дополнительных полей, идущих до полей данных в списке INSERT-команды
        DataBatchInserter::Pointer_t createInserter(CustomTypeMeta* msgMeta, const QStringList& customFields = QStringList())
        {
            DataBatchInserter::Pointer_t inserter;

            // Getting inserters for all fields
            QList<DataBatchInserter::Pointer_t> childInserters;
            childInserters.append(_epochInserter);
            foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
            {
                auto ct = _nameToCustomTypeMap[varMeta->Type];
                if (!ct.get())
                {
                    continue;
                }
                childInserters.append(getCtInserter(ct.get()));
            }

            QString insertCommand;
            if (customFields.empty())
            {
                insertCommand = QString("INSERT INTO `%1` (`%2`) VALUES ").arg(msgMeta->TableName);
            } else {
                QStringList customFieldsEscaped;
                foreach (QString f, customFields)
                {
                    customFieldsEscaped << QString("`%1`").arg(f);
                }
                QString customFieldsStr = customFieldsEscaped.join(", ");
                insertCommand = QString("INSERT INTO `%1` (%2, `%3`) VALUES ").arg(msgMeta->TableName).arg(customFieldsStr);
            }

            // Creating a new inserter
            QStringList columnNames;
            foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
            {
                columnNames.append(varMeta->GetColumnName());
            }
            auto columnNamesStr = columnNames.join("`, `");
            insertCommand = insertCommand.arg((columnNamesStr));

            int fieldsCount = msgMeta->Variables.count() + customFields.count();
            insertCommand.append("(?");
            for (int i = 0; i < fieldsCount - 1; ++i)
            {
                insertCommand.append(", ?");
            }
            insertCommand.append(")");
            inserter = DataBatchInserter::Pointer_t(new DataBatchInserter(insertCommand, fieldsCount, _connection, msgMeta->TableName, _inserterBatchSize));
            foreach (DataBatchInserter::Pointer_t ci, childInserters)
            {
                inserter->AddChild(ci);
            }
            return inserter;
        }

        void validateMessage(MessageMeta* msgMeta, StdMessage_t* msg)
        {
            if (msgMeta->Size >= 0)
            {
                if (msg->bodySize() != msgMeta->Size)
                {
                    throw Exception(QString("Invalid size for message '%1': expected %2, actual %3.").
                        arg(msgMeta->Name).arg(msgMeta->Size).arg(msg->bodySize()));
                }
            }
            switch (msgMeta->Validation->Id)
            {
            case ValidationClassifier::Checksum:
                if (!msg->validateChecksum8bin())
                {
                    throw Exception(QString("Invalid checksum for message '%1'.").arg(msgMeta->Name));
                }
                break;
            case ValidationClassifier::ChecksumAsHexAscii:
                if (!msg->validateChecksum8ascii())
                {
                    throw Exception(QString("Invalid checksum for message '%1'.").arg(msgMeta->Name));
                }
                break;
            case ValidationClassifier::Crc16:
                // TODO
                break;
            }
        }
    };
}

#endif // MySqlSink_h__