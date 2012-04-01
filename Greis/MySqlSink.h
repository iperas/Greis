#ifndef MySqlSink_h__
#define MySqlSink_h__

#include <QList>
#include <QMap>
#include "ProjectBase/Connection.h"
#include "ProjectBase/SmartPtr.h"
#include "GreisMessage.h"
#include "ProjectBase/NotSupportedException.h"
#include "ProjectBase/NotImplementedException.h"
#include "ProjectBase/DataInserter.h"
#include "ProjectBase/DataBatchInserter.h"
#include "EMessageId.h"
#include "ECustomTypeId.h"

using namespace ProjectBase;

namespace Greis
{
    class MySqlSink
    {
    private:
        MetaInfo::SharedPtr_t _metaInfo;
        Connection* _connection;
        DatabaseHelper* _dbHelper;
        QMap<MessageMeta*, DataBatchInserter::SharedPtr_t> _msgInsertersMap;
        QMap<CustomTypeMeta*, DataBatchInserter::SharedPtr_t> _ctInsertersMap;
        DataBatchInserter::SharedPtr_t _epochInserter;
        QMap<CustomTypeMeta*, int> _ctAvailableId;
        int _lastEpochId;
        QStringList _unknownTypes;
        QMap<QString, MessageMeta::SharedPtr_t> _codeToMsgMap;
        QMap<QString, CustomTypeMeta::SharedPtr_t> _nameToCustomTypeMap;
        int _inserterBatchSize;
    public:
        SMART_PTR_T(MySqlSink);

        MySqlSink(MetaInfo::SharedPtr_t metaInfo, Connection* connection, int inserterBatchSize = 10000)
        {
            _metaInfo = metaInfo;
            _connection = connection;
            _dbHelper = _connection->DbHelper();
            _inserterBatchSize = inserterBatchSize;

            foreach (MessageMeta::SharedPtr_t msg, _metaInfo->MessagesMeta)
            {
                foreach (MessageCode::SharedPtr_t code, msg->Codes)
                {
                    _codeToMsgMap[code->Code] = msg;
                }
            }

            foreach (CustomTypeMeta::SharedPtr_t ct, _metaInfo->CustomTypesMeta)
            {
                _nameToCustomTypeMap[ct->Name] = ct;
            }

            _lastEpochId = _dbHelper->ExecuteSingleValueQuery(QString("SELECT MAX(`id`) FROM `epoch`")).toInt();
            _epochInserter = DataBatchInserter::SharedPtr_t(new DataBatchInserter(
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

        void AddMessage(StdMessage_t::SharedPtr_t msg, bool ignoreInvalidMessages = true)
        {
            // MessageMeta retrieving
            auto msgCodeStr = QString::fromAscii(msg->id().c_str(), 2);
            auto msgMeta = _codeToMsgMap.value(msgCodeStr, MessageMeta::SharedPtr_t());

            if (!msgMeta.get())
            {
                // Unknown message
                return;
            }

            if (!ignoreInvalidMessages)
            {
                validateMessage(msgMeta.get(), msg.get());
            }

            DataBatchInserter::SharedPtr_t inserter = getMsgInserter(msgMeta.get());
            
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
                serializeCustomType(msgMeta.get(), msgPtr, rowValues);
                inserter->AddRow(rowValues);
            }
            catch (NotImplementedException& e)
            {
                sLogger.Warn(e.what());
            }
        }

        void serializeCustomType( CustomTypeMeta* msgMeta, const char* &dataPtr, QVariantList &sink ) 
        {
            foreach (VariableMeta::SharedPtr_t varMeta, msgMeta->Variables)
            {
                auto varType = varMeta->Type;
                 {
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
            foreach (DataBatchInserter::SharedPtr_t inserter, _msgInsertersMap)
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

        DataBatchInserter::SharedPtr_t getMsgInserter(MessageMeta* msgMeta)
        {
            DataBatchInserter::SharedPtr_t inserter;
            if ((inserter = _msgInsertersMap.value(msgMeta)).get())
            {
                return inserter;
            }

            inserter = createInserter(msgMeta, QStringList() << "idEpoch" << "idMessageCode" << "bodySize");
            _msgInsertersMap[msgMeta] = inserter;
            return inserter;
        }

        DataBatchInserter::SharedPtr_t getCtInserter(CustomTypeMeta* ctMeta)
        {
            DataBatchInserter::SharedPtr_t inserter;
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
        DataBatchInserter::SharedPtr_t createInserter(CustomTypeMeta* msgMeta, const QStringList& customFields = QStringList())
        {
            DataBatchInserter::SharedPtr_t inserter;

            // Getting inserters for all fields
            QList<DataBatchInserter::SharedPtr_t> childInserters;
            childInserters.append(_epochInserter);
            foreach (VariableMeta::SharedPtr_t varMeta, msgMeta->Variables)
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
            foreach (VariableMeta::SharedPtr_t varMeta, msgMeta->Variables)
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
            inserter = DataBatchInserter::SharedPtr_t(new DataBatchInserter(insertCommand, fieldsCount, _connection, msgMeta->TableName, _inserterBatchSize));
            foreach (DataBatchInserter::SharedPtr_t ci, childInserters)
            {
                inserter->AddChild(ci);
            }
            return inserter;
        }
    };

    class MySqlSink2
    {
        QMap<EMessageId::Type, DataBatchInserter::SharedPtr_t> _stdMessagesInserters;
        QMap<ECustomTypeId::Type, DataBatchInserter::SharedPtr_t> _customTypesInserters;

        QMultiMap<EMessageId::Type, ECustomTypeId::Type> _msgDependencies;
        QMultiMap<ECustomTypeId::Type, ECustomTypeId::Type> _ctDependencies;
        QMap<EMessageId::Type, QString> _msgInsertStrings;
        QMap<ECustomTypeId::Type, QString> _ctInsertStrings;
    private:
        MySqlSink2()
        {
            // Standard messages dependencies
            _msgDependencies.insert(EMessageId::AngularVelocity, EMessageId::BaseInfo);
            _msgDependencies.insert(EMessageId::AngularVelocity, EMessageId::AntName);
            // Custom types dependencies
            _ctDependencies.insert(ECustomTypeId::Header, ECustomTypeId::Smooth);

            // Batch standard messages SQL-insert strings
            _msgInsertStrings[EMessageId::AngularVelocity] = "";
            // Batch custom types SQL-insert strings
            _ctInsertStrings[ECustomTypeId::Header] = "";
        }
    };
}

#endif // MySqlSink_h__