#ifndef MetaInfoReader_h__
#define MetaInfoReader_h__

#include "Database\Connection.h"
#include "MetaInfo.h"
#include "Util\SharedPtr.h"

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
            return loadVariables("customTypeVariableMeta", "idCustomTypeMeta");
        }

        QMap<int, QList<VariableMeta::Pointer_t> > loadMessageVariables()
        {
            return loadVariables("messageVariableMeta", "idMessageMeta");
        }

        QMap<int, QList<VariableMeta::Pointer_t> > loadVariables(const QString& tableName, const QString& idParentColumnName)
        {
            QMap<int, QList<VariableMeta::Pointer_t> > variablesMap;
            auto sqlQuery = _dbHelper->ExecuteQuery(QString("SELECT id, name, type, requiredValue, %1 FROM %2 ORDER BY id").arg(idParentColumnName).arg(tableName));
            while (sqlQuery.next())
            {
                auto id = sqlQuery.value(0).toInt();
                auto name = sqlQuery.value(1).toString();
                auto type = sqlQuery.value(2).toString();
                auto requiredValue = sqlQuery.value(3).toString();
                auto idParent = sqlQuery.value(4).toInt();

                QList<int> sizeForDimensions;
                auto sqlSubQuery = _dbHelper->ExecuteQuery(QString(
                    "SELECT size FROM customTypeVariableSizeForDimension WHERE idVariable = %1 ORDER BY dimensionNumber").arg(id));
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
}

#endif // MetaInfoReader_h__