#ifndef MetaInfoReader_h__
#define MetaInfoReader_h__

#include "Database\Connection.h"
#include "MetaInfo.h"
#include "Util\SharedPtr.h"
#include "JpsFile.h"

using namespace Database;

namespace Domain
{
    class MetaInfoReader
    {
    private:
        Connection *_connection;
        DatabaseHelper* _dbHelper;
    public:
        MetaInfoReader(Connection *connection)
        {
            _connection = connection;
            _dbHelper = _connection->DbHelper();
        }

        MetaInfo::Pointer_t Load()
        {
            auto sizeSpecialValueClassifier = loadClassifier("sizeSpecialValueClassifier");
            auto messageTypeClassifier = loadClassifier("messageTypeClassifier");
            auto messageValidationClassifier = loadClassifier("messageValidationClassifier");
            auto messageKindClassifier = loadClassifier("messageKindClassifier");

            auto customTypeVariables = loadCustomTypeVariables();
            auto messageVariables = loadMessageVariables();

            auto messagesMeta = loadMessagesMeta(messageValidationClassifier, messageKindClassifier, messageTypeClassifier, messageVariables);
            auto customTypesMeta = loadCustomTypesMeta(customTypeVariables);

            auto metaInfo = SHARED_PTR_NEW(MetaInfo);
            metaInfo->MessagesMeta = messagesMeta;
            metaInfo->CustomTypesMeta = customTypesMeta;
            metaInfo->SizeSpecialValueClassifier = sizeSpecialValueClassifier;

            return metaInfo;
        }

    private:
        QMap<int, ClassifierItem::Pointer_t> loadClassifier(const QString& tableName)
        {
            QMap<int, ClassifierItem::Pointer_t> classifierMap;
            auto sqlQuery = _dbHelper->ExecuteQuery(QString("SELECT id, name FROM %1").arg(tableName));
            while (sqlQuery.next())
            {
                auto id = sqlQuery.value(0).toInt();
                auto name = sqlQuery.value(1).toString();
                auto item = SHARED_PTR_NEW(ClassifierItem);
                item->Id = id;
                item->Name = name;
                classifierMap[id] = item;
            }
            return classifierMap;
        }

        QMap<int, QList<VariableMeta::Pointer_t> > loadCustomTypeVariables()
        {
            return loadVariables("customTypeVariableMeta", "customTypeVariableSizeForDimension", "idCustomTypeMeta");
        }

        QMap<int, QList<VariableMeta::Pointer_t> > loadMessageVariables()
        {
            return loadVariables("messageVariableMeta", "messageVariableSizeForDimension", "idMessageMeta");
        }

        QMap<int, QList<VariableMeta::Pointer_t> > loadVariables(const QString& tableName, const QString& sizeForDimensionTableName, const QString& idParentColumnName)
        {
            QMap<int, QList<VariableMeta::Pointer_t> > variablesMap;
            auto sqlQuery = _dbHelper->ExecuteQuery(QString("SELECT id, name, greisType, requiredValue, %1 FROM %2 ORDER BY id").arg(idParentColumnName).arg(tableName));
            while (sqlQuery.next())
            {
                auto id = sqlQuery.value(0).toInt();
                auto name = sqlQuery.value(1).toString();
                auto type = sqlQuery.value(2).toString();
                auto requiredValue = sqlQuery.value(3).toString();
                auto idParent = sqlQuery.value(4).toInt();

                QList<int> sizeForDimensions;
                auto sqlSubQuery = _dbHelper->ExecuteQuery(QString(
                    "SELECT size FROM %1 WHERE idVariable = %2 ORDER BY dimensionNumber").arg(sizeForDimensionTableName).arg(id));
                while (sqlSubQuery.next())
                {
                    sizeForDimensions.append(sqlSubQuery.value(0).toInt());
                }

                auto variable = VariableMeta::Pointer_t(new VariableMeta(sizeForDimensions));
                variable->Id = id;
                variable->Name = name;
                variable->Type = type;
                variable->RequiredValue = requiredValue;

                variablesMap[idParent].append(variable);
            }

            return variablesMap;
        }

        QList<MessageMeta::Pointer_t> loadMessagesMeta(const QMap<int, ClassifierItem::Pointer_t>& messageValidationClassifier, 
            const QMap<int, ClassifierItem::Pointer_t>& messageKindClassifier, 
            const QMap<int, ClassifierItem::Pointer_t>& messageTypeClassifier, 
            const QMap<int, QList<VariableMeta::Pointer_t>>& messageVariables)
        {
            QList<MessageMeta::Pointer_t> messagesMeta;
            auto sqlQuery = _dbHelper->ExecuteQuery("SELECT id, name, title, size, idValidation, idKind, idType, tableName FROM messageMeta");
            while (sqlQuery.next())
            {
                auto id = sqlQuery.value(0).toInt();
                auto name = sqlQuery.value(1).toString();
                auto title = sqlQuery.value(2).toString();
                auto size = sqlQuery.value(3).toInt();
                auto idValidation = sqlQuery.value(4).toInt();
                auto idKind = sqlQuery.value(5).toInt();
                auto idType = sqlQuery.value(6).toInt();
                auto tableName = sqlQuery.value(7).toString();

                QList<MessageCode::Pointer_t> codes;
                auto sqlSubQuery = _dbHelper->ExecuteQuery(QString(
                    "SELECT id, code FROM messageCode WHERE idMessageMeta = %1 ORDER BY id").arg(id));
                while (sqlSubQuery.next())
                {
                    auto code = SHARED_PTR_NEW(MessageCode);
                    code->Id = sqlSubQuery.value(0).toInt();
                    code->Code = sqlSubQuery.value(1).toString();
                    codes.append(code);
                }

                auto messageMeta = SHARED_PTR_NEW(MessageMeta);
                messageMeta->Id = id;
                messageMeta->Name = name;
                messageMeta->Title = title;
                messageMeta->Size = size;
                messageMeta->TableName = tableName;
                messageMeta->Validation = messageValidationClassifier[idValidation];
                messageMeta->Kind = messageKindClassifier[idKind];
                messageMeta->Type = messageTypeClassifier[idType];
                messageMeta->Variables = messageVariables[id];
                messageMeta->Codes = codes;

                messagesMeta.append(messageMeta);
            }
            return messagesMeta;
        }

        QList<CustomTypeMeta::Pointer_t> loadCustomTypesMeta(const QMap<int, QList<VariableMeta::Pointer_t>>& customTypeVariables)
        {
            QList<CustomTypeMeta::Pointer_t> customTypesMeta;
            auto sqlQuery = _dbHelper->ExecuteQuery("SELECT id, name, size, tableName FROM customTypeMeta");
            while (sqlQuery.next())
            {
                auto id = sqlQuery.value(0).toInt();
                auto name = sqlQuery.value(1).toString();
                auto size = sqlQuery.value(2).toInt();
                auto tableName = sqlQuery.value(3).toString();

                auto customTypeMeta = SHARED_PTR_NEW(CustomTypeMeta);
                customTypeMeta->Id = id;
                customTypeMeta->Name = name;
                customTypeMeta->Size = size;
                customTypeMeta->TableName = tableName;
                customTypeMeta->Variables = customTypeVariables[id];

                customTypesMeta.append(customTypeMeta);
            }
            return customTypesMeta;
        }
    };

    class EpochsRange_t
    {
    public:
        SHARED_PTR_T(EpochsRange_t);

        QList<Epoch_t> Epochs;
    };

    class MessagesSerializer
    {
        MetaInfo::Pointer_t _metaInfo;
    public:
        SHARED_PTR_T(MessagesSerializer);

        MessagesSerializer(MetaInfo::Pointer_t metaInfo)
        {
            _metaInfo = metaInfo;
        }


    };

    class EpochsReader
    {
    private:
        Connection *_connection;
        DatabaseHelper* _dbHelper;
        MetaInfo::Pointer_t _metaInfo;
        BitConverter _bitConverter;
        QMap<QString, CustomTypeMeta::Pointer_t> _nameToCustomTypeMap;
        QMap<int, QMap<int, QByteArray> > _loadedCustomTypes;
        int _idEpochFrom;
        int _idEpochTo;
        QDateTime _dateTimeFrom;
        QDateTime _dateTimeTo;
    public:
        EpochsReader(MetaInfo::Pointer_t metaInfo, Connection *connection)
        {
            _metaInfo = metaInfo;
            _connection = connection;
            _dbHelper = _connection->DbHelper();

            foreach (CustomTypeMeta::Pointer_t ct, _metaInfo->CustomTypesMeta)
            {
                _nameToCustomTypeMap[ct->Name] = ct;
            }
        }

        EpochsRange_t::Pointer_t Load(QDateTime dateTimeFrom, QDateTime dateTimeTo)
        {
            auto range = SHARED_PTR_NEW(EpochsRange_t);
            _dateTimeFrom = dateTimeFrom;
            _dateTimeTo = dateTimeTo;

            // Reading idEpochFrom
            /*auto queryStr = QString("SELECT `id` FROM `epoch` WHERE `dateTime` >= ? ORDER BY `dateTime` LIMIT 1");
            _idEpochFrom = _dbHelper->ExecuteSingleValueQuery(queryStr, QList<QVariant>() << dateTimeFrom).toInt();

            // Reading idEpochTo
            queryStr = QString("SELECT `id` FROM `epoch` WHERE `dateTime` <= ? ORDER BY `dateTime` DESC LIMIT 1");
            _idEpochTo = _dbHelper->ExecuteSingleValueQuery(queryStr, QList<QVariant>() << dateTimeTo).toInt();*/

            QMap<int, StdMessage_t::Pointer_t> idToCtMap;

            foreach (CustomTypeMeta::Pointer_t ctMeta, _metaInfo->MessagesMeta)
            {
                QString queryStr = createSelectString(ctMeta.get());
                auto query = _dbHelper->ExecuteQuery(queryStr);
                bool hitme = queryStr.contains(QString("msg_rcp_rc1"), Qt::CaseInsensitive);
                while (query.next())
                {
                    int id = query.value(0).toInt();

                    QVariantList fields;
                    for (int i = 1; i < query.size(); ++i)
                    {
                        fields.append(query.value(i));
                    }
                    QByteArray ba;

                    binarizeCustomType(ctMeta.get(), fields, ba);

                    auto msg = StdMessage_t::Pointer_t(new StdMessage_t(ba.data(), ba.size()));
                    idToCtMap[id] = msg;
                    idToCtMap[id + 666123] = hitme ? StdMessage_t::Pointer_t() : StdMessage_t::Pointer_t();
                }
            }

            // Cache clean up
            _loadedCustomTypes.clear();

            return range;
        }

    private:
        void binarizeCustomType( CustomTypeMeta* msgMeta, const QVariantList& fieldsSequence, QByteArray& sink ) 
        {
            QByteArray output;
            int colIndex = 1;
            foreach (VariableMeta::Pointer_t varMeta, msgMeta->Variables)
            {
                auto varType = varMeta->Type;
                if (varType == "a1")
                {
                    auto val = fieldsSequence.at(colIndex).toString().toAscii();
                    output.append(val);
                } else if (varType == "i1")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = (char) fieldsSequence.at(colIndex).toInt();
                        output.append(val);
                    } else 
                    {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else if (varType == "i2")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = (short) fieldsSequence.at(colIndex).toInt();
                        char binVal[2];
                        _bitConverter.ToByteArray(val, binVal);
                        output.append(binVal, 2);
                    } else {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else if (varType == "i4")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = fieldsSequence.at(colIndex).toInt();
                        char binVal[4];
                        _bitConverter.ToByteArray(val, binVal);
                        output.append(binVal, 4);
                    } else {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else if (varType == "u1")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = (unsigned char) fieldsSequence.at(colIndex).toUInt();
                        output.append((char*)&val, 1);
                    } else {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else if (varType == "u2")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = (unsigned short) fieldsSequence.at(colIndex).toUInt();
                        char binVal[2];
                        _bitConverter.ToByteArray(val, binVal);
                        output.append(binVal, 2);
                    } else {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else if (varType == "u4")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = fieldsSequence.at(colIndex).toUInt();
                        char binVal[4];
                        _bitConverter.ToByteArray(val, binVal);
                        output.append(binVal, 4);
                    } else {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else if (varType == "f4")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = fieldsSequence.at(colIndex).toFloat();
                        char binVal[4];
                        _bitConverter.ToByteArray(val, binVal);
                        output.append(binVal, 4);
                    } else {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else if (varType == "f8")
                {
                    if (varMeta->IsScalar())
                    {
                        auto val = fieldsSequence.at(colIndex).toDouble();
                        char binVal[8];
                        _bitConverter.ToByteArray(val, binVal);
                        output.append(binVal, 8);
                    } else {
                        auto val = fieldsSequence.at(colIndex).toByteArray();
                        output.append(val);
                    }
                } else {
                    auto ct = _nameToCustomTypeMap[varType];
                    if (!ct.get())
                    {
                        throw Exception(QString("EpochsReader: unknown type `%1`...").arg(varType));
                    } else {
                        int typeSize = ct->Size;
                        BOOST_ASSERT(typeSize >= 0);

                        QVector<int> ctIds;
                        if (varMeta->IsScalar())
                        {
                            int ctId = fieldsSequence.at(colIndex).toInt();
                            ctIds.append(ctId);
                        } else {
                            auto ba = fieldsSequence.at(colIndex).toByteArray();
                            const char* baRaw = ba.data();
                            
                            for (int baSize = ba.size(), pos = 0; baSize >= 4; baSize -= 4)
                            {
                                int ctId = (int) _bitConverter.GetUInt(baRaw+pos);
                                ctIds.append(ctId);
                            }
                        }

                        foreach (int ctId, ctIds)
                        {
                            handleCustomType(ct.get(), ctId, output);
                        }
                    }
                }
                colIndex++;
            }
            sink.append(output);
        }

        void handleCustomType(CustomTypeMeta* ctMeta, int ctId, QByteArray& sink )
        {
            decltype(_loadedCustomTypes.constBegin()) it;
            if ((it = _loadedCustomTypes.find(ctMeta->Id)) != _loadedCustomTypes.constEnd())
            {
                decltype(it->constBegin()) it2;
                if ((it2 = it->find(ctId)) != it->constEnd())
                {
                    // custom type found in cache
                    sink.append(it2.value());
                }
            }

            auto queryStr = createSelectString(ctMeta);
            auto query = _dbHelper->ExecuteQuery(queryStr);
            while (query.next())
            {
                int id = query.value(0).toInt();

                QVariantList fields;
                for (int i = 1; i < query.size(); ++i)
                {
                    fields.append(query.value(i));
                }
                QByteArray ba;

                binarizeCustomType(ctMeta, fields, ba);

                _loadedCustomTypes[ctMeta->Id][ctId] = ba;
                sink.append(ba);
            }
        }

        QString createSelectString(CustomTypeMeta* ctMeta)
        {
            QStringList columnsNames;
            foreach (VariableMeta::Pointer_t varMeta, ctMeta->Variables)
            {
                columnsNames.append(varMeta->GetColumnName());
            }
            auto columnsStr = columnsNames.join("`, `");
            /*auto queryStr = QString("SELECT `id`, `%1` FROM `%2` WHERE idEpoch >= %3 AND idEpoch <= %4")
                .arg(columnsStr)
                .arg(ctMeta->TableName)
                .arg(_idEpochFrom)
                .arg(_idEpochTo);
            auto queryStr = QString("SELECT `id`, `%1` FROM `%2` WHERE `idEpoch` IN (SELECT `id` FROM `epoch` WHERE `dt` BETWEEN TIMESTAMP('%1') AND TIMESTAMP('%2'))")
                .arg(columnsStr)
                .arg(ctMeta->TableName)
                .arg(_dateTimeFrom.toString("yyyy-MM-dd HH:mm:ss"))
                .arg(_dateTimeTo.toString("yyyy-MM-dd HH:mm:ss"));*/
            auto queryStr = QString("SELECT `id`, `%1` FROM `%2` WHERE `idEpoch` IN (SELECT `id` FROM `epoch` WHERE `dt` BETWEEN %3 AND %4)")
                .arg(columnsStr)
                .arg(ctMeta->TableName)
                .arg(_dateTimeFrom.toMSecsSinceEpoch())
                .arg(_dateTimeTo.toMSecsSinceEpoch());
            return queryStr;
        }
    };
}

#endif // MetaInfoReader_h__