#ifndef MySqlSink_h__
#define MySqlSink_h__

#include <QtCore/QList>
#include <QtCore/QMap>
#include "ProjectBase/Connection.h"
#include "ProjectBase/SmartPtr.h"
#include "ProjectBase/NotSupportedException.h"
#include "ProjectBase/NotImplementedException.h"
#include "ProjectBase/DataInserter.h"
#include "ProjectBase/DataBatchInserter.h"
#include "EMessageId.h"
#include "ECustomTypeId.h"
#include "JpsFile.h"
#include "GreisMysqlSerializer.h"
#include "CustomType.h"

using namespace ProjectBase;

namespace Greis
{
    class MySqlSink3
    {
    private:
        /*MetaInfo::SharedPtr_t _metaInfo;
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
        int _inserterBatchSize;*/
    public:

        /*void AddMessage(StdMessage_t::SharedPtr_t msg, bool ignoreInvalidMessages = true)
        {
            // MessageMeta retrieving
            auto msgCodeStr = QString::fromAscii(msg->id().c_str(), 2);
            auto msgMeta = _codeToMsgMap.value(msgCodeStr, MessageMeta::SharedPtr_t());

            if (!msgMeta.get())
            {
                // Unknown message
                return;
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
        */
    private:
        // Формирует данные и отправляет на ожидание вставки. Возвращает ID нового элемента.
        /*int handleCustomType(CustomTypeMeta* ct, const char* dataPtr)
        {
            auto inserter = getCtInserter(ct);
            int newId = _ctAvailableId[ct] + 1;

            int fillFieldsCount = -1;

            int typeSize = ct->Size;
            BOOST_ASSERT(typeSize >= 0);
            //if (ct->Size == SizeSpecialValueClassifier::Fill)
            //{
            //    fillFieldsCount = getFilledArrayFieldsSize(ct, msg->bodySize());
            //}

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
        }*/
    };

    class MySqlSink
    {
    public:
        SMART_PTR_T(MySqlSink);

        MySqlSink(Connection* connection, int inserterBatchSize = 10000);
        ~MySqlSink();

        void AddJpsFile(JpsFile* file);

        void AddEpoch(QDateTime dateTime);
        void AddMessage(Message* msg);

        void Flush();
    private:
        void construct();

        int addCustomType(CustomType* ct);

        // Serialize objects fields into QVariantList with calling addCustomType if needed.
        void serializeMessage(StdMessage* msg, QVariantList& out);
        void serializeCustomType(CustomType* ct, QVariantList& out);

        // Add vector of custom types and serialize it for standard message table field.
        template<typename T>
        inline QVariant addCustomTypesAndSerialize(const std::vector<T>& field)
        {
            std::vector<int> ids;
            for (auto it = field.cbegin(); it != field.cend(); ++it)
            {
                int idVal = addCustomType(it->get());
                ids.push_back(idVal);
            }
            return _serializer.SerializeIds(ids);
        }
    private:
        Connection* _connection;
        DatabaseHelper* _dbHelper;
        int _inserterBatchSize;

        QMap<EMessageId::Type, DataBatchInserter::SharedPtr_t> _msgInserters;
        QMap<ECustomTypeId::Type, DataBatchInserter::SharedPtr_t> _ctInserters;

        GreisMysqlSerializer _serializer;

        DataBatchInserter::SharedPtr_t _epochInserter;
        DataBatchInserter::SharedPtr_t _rawMessageInserter;
        int _lastEpochId;
        QDateTime _lastEpochDateTime;

        QMap<ECustomTypeId::Type, int> _ctCurrentMaxId;
        QMap<std::string, int> _codeIds;
    };
}

#endif // MySqlSink_h__