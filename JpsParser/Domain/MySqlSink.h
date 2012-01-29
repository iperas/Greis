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
        QMap<MessageMeta*, DataBatchInserter::Pointer_t> _insertersMap;

        QMap<QString, MessageMeta::Pointer_t> _codeToMsgMap;
        QMap<QString, CustomTypeMeta::Pointer_t> _nameToCustomTypeMap;
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

            foreach (CustomTypeMeta::Pointer_t ct, _metaInfo->CustomTypesMeta)
            {
                _nameToCustomTypeMap[ct->Name] = ct;
            }
        }

        ~MySqlSink()
        {
            Flush();
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

            if (!ignoreInvalidMessages)
            {
                validateMessage(msgMeta.get(), msg.get());
            }

            DataBatchInserter::Pointer_t inserter = getInserter(msgMeta.get());
            
            // Сделано приближение что не бывает смешанных динамических\статических массивов
            // и что динамические многомерные массивы равнозначны одномерным
            // fieldCount = (struct_size - static_fields_size) / (the_other_fields_size)
            int fillFieldsCount = -1;
            int fillFieldsTypeSize = 0;
            QMap<QString, int> simpleTypesSize;
            simpleTypesSize["a1"] = 1;
            simpleTypesSize["u1"] = 1;
            simpleTypesSize["u2"] = 2;
            simpleTypesSize["u4"] = 4;
            simpleTypesSize["i1"] = 1;
            simpleTypesSize["i2"] = 2;
            simpleTypesSize["i4"] = 4;
            simpleTypesSize["f4"] = 4;
            simpleTypesSize["f8"] = 8;
            if (msgMeta->Size == SizeSpecialValueClassifier::Fill)
            {
                int size = msg->bodySize();
                foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
                {
                    // typeSize computing
                    int typeSize;
                    if (simpleTypesSize.contains(varMeta->Type))
                    {
                        typeSize = simpleTypesSize[varMeta->Type];
                    } else {
                        CustomTypeMeta::Pointer_t varType;
                        foreach (CustomTypeMeta::Pointer_t ct, _metaInfo->CustomTypesMeta)
                        {
                            if (ct->Name == varMeta->Type)
                            {
                                varType = ct;
                                break;
                            }
                        }
                        if (!varType.get())
                        {
                            throw Exception(QString("Cannot find custom type definition for type `%1`.").arg(varMeta->Type));
                        }
                        if (varType->Size < 0)
                        {
                            throw Exception(QString("Fields with custom type of dynamic size is too complicated logic."));
                        }
                        typeSize = varType->Size;
                    }
                    // check for dynamic array fields
                    int dimCount = varMeta->GetDimensionsCount();
                    bool fillSize = false;
                    for (int i = 0; i < dimCount; ++i)
                    {
                        if (varMeta->GetSizeForDimension(i + 1) == SizeSpecialValueClassifier::Fill)
                        {
                            fillSize = true;
                        }
                    }
                    if (fillSize)
                    {
                        fillFieldsTypeSize += typeSize;
                        continue;
                    }
                    // static fields size computing
                    if (varMeta->IsScalar())
                    {
                        size -= typeSize;
                    } else {
                        int itemsCount = varMeta->GetSizeForDimension(1);
                        for (int i = 1; i < varMeta->GetDimensionsCount(); ++i)
                        {
                            itemsCount *= varMeta->GetSizeForDimension(i + 1);
                        }
                        size -= typeSize * itemsCount;
                    }
                }
                fillFieldsCount = size / fillFieldsTypeSize;
            }
            // values
            try
            {
                BitConverter bitConverter;
                const char* msgPtr = msg->body();
                QVariantList rowValues;
                rowValues.append(1);
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
                            throw NotSupportedException("Character arrays with dimension more than linear not supported.");
                        }
                        QString varStr;
                        while (fieldsCount-- > 0)
                        {
                            char a1 = bitConverter.GetChar(msgPtr++);
                            varStr.append(QChar::fromAscii(a1));
                        }
                        rowValues.append(varStr);
                    } else if (varType == "i1")
                    {
                        int typeSize = 1;
                        if (varMeta->IsScalar())
                        {
                            char i1 = bitConverter.GetChar(msgPtr++);
                            rowValues.append((int) i1);
                        } else 
                        {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else if (varType == "i2")
                    {
                        int typeSize = 2;
                        if (varMeta->IsScalar())
                        {
                            short i2 = bitConverter.GetShort(msgPtr);
                            msgPtr += typeSize;
                            rowValues.append((int) i2);
                        } else {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else if (varType == "i4")
                    {
                        int typeSize = 4;
                        if (varMeta->IsScalar())
                        {
                            int i4 = bitConverter.GetInt(msgPtr);
                            msgPtr += typeSize;
                            rowValues.append(i4);
                        } else {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else if (varType == "u1")
                    {
                        int typeSize = 1;
                        if (varMeta->IsScalar())
                        {
                            unsigned char u1 = bitConverter.GetUChar(msgPtr);
                            msgPtr += typeSize;
                            rowValues.append((unsigned int) u1);
                        } else {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else if (varType == "u2")
                    {
                        int typeSize = 2;
                        if (varMeta->IsScalar())
                        {
                            unsigned short u2 = bitConverter.GetUShort(msgPtr);
                            msgPtr += typeSize;
                            rowValues.append((unsigned int) u2);
                        } else {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else if (varType == "u4")
                    {
                        int typeSize = 4;
                        if (varMeta->IsScalar())
                        {
                            unsigned int u4 = bitConverter.GetUInt(msgPtr);
                            msgPtr += typeSize;
                            rowValues.append(u4);
                        } else {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else if (varType == "f4")
                    {
                        int typeSize = 4;
                        if (varMeta->IsScalar())
                        {
                            float f4 = bitConverter.GetFloat(msgPtr);
                            msgPtr += typeSize;
                            rowValues.append((double) f4);
                        } else {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else if (varType == "f8")
                    {
                        int typeSize = 8;
                        if (varMeta->IsScalar())
                        {
                            double f8 = bitConverter.GetDouble(msgPtr);
                            msgPtr += typeSize;
                            rowValues.append(f8);
                        } else {
                            QByteArray ba = getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            rowValues.append(ba);
                        }
                    } else {
                        auto ct = _nameToCustomTypeMap[varType];
                        if (!ct.get())
                        {
                            return;
                        }
                        int typeSize = ct->Size;
                        BOOST_ASSERT(typeSize >= 0);
                        // TODO
                        if (varMeta->IsScalar())
                        {
                            msgPtr += typeSize;
                            rowValues.append(QVariant(QVariant::UInt));
                        } else {
                            getArrayValue(varMeta, msgPtr, fillFieldsCount, typeSize);
                            QByteArray ba;
                            rowValues.append(ba);
                        }
                    }
                }
                inserter->AddRow(rowValues);
            }   
            catch (NotImplementedException& e)
            {
                
            }
        }

        void Flush()
        {
            foreach (DataBatchInserter::Pointer_t inserter, _insertersMap)
            {
                inserter->Flush();
            }
        }

        QByteArray getArrayValue( VariableMeta::Pointer_t varMeta, const char* msgPtr, int fillFieldsCount, int typeSize ) 
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
            QByteArray ba(msgPtr, fieldsCount * typeSize);
            msgPtr += fieldsCount * typeSize;
            return ba;
        }
    private:
        DataBatchInserter::Pointer_t getInserter(MessageMeta* msgMeta)
        {
            DataBatchInserter::Pointer_t inserter;
            if ((inserter = _insertersMap.value(msgMeta)).get())
            {
                return inserter;
            }

            QString insertCommand = QString("INSERT INTO `%1` (`idEpoch`, `%2`) VALUES ").arg(msgMeta->TableName);
            QStringList columnNames;
            foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
            {
                columnNames.append(varMeta->GetColumnName());
            }
            auto columnNamesStr = columnNames.join("`, `");
            insertCommand = insertCommand.arg((columnNamesStr));

            int variablesCount = msgMeta->Variables.count();
            insertCommand.append("(?");
            for (int i = 0; i < variablesCount; ++i)
            {
                insertCommand.append(", ?");
            }
            insertCommand.append(")");
            inserter = DataBatchInserter::Pointer_t(new DataBatchInserter(insertCommand, variablesCount + 1, _connection, 1000, msgMeta->TableName));
            _insertersMap[msgMeta] = inserter;
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