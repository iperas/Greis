#ifndef MetaInfo_h__
#define MetaInfo_h__

#include <QList>
#include "ProjectBase/Connection.h"
#include "ProjectBase/SmartPtr.h"
#include "ProjectBase/Exception.h"

using namespace ProjectBase;

namespace Domain
{
    class MetaInfo;

    struct ValidationClassifier
    {
        enum EValidationClassifier
        {
            None = 0,
            Checksum = 1,
            ChecksumAsHexAscii = 2,
            Crc16 = 3
        };
    };

    struct SizeSpecialValueClassifier
    {
        enum ESizeSpecialValueClassifier
        {
            Dynamic = -1,
            Fill = -2,
        };
    };

    class ClassifierItem
    {
    public:
        SMART_PTR_T(ClassifierItem);

        int Id;
        QString Name;
    };

    typedef ClassifierItem SizeSpecialValue;
    typedef ClassifierItem MessageValidation;
    typedef ClassifierItem MessageType;
    typedef ClassifierItem MessageKind;

    class MessageCode
    {
    public:
        SMART_PTR_T(MessageCode);

        int Id;
        QString Code;
    };

    class VariableMeta
    {
        QList<int> _sizesForDimensions;
    public:
        SMART_PTR_T(VariableMeta);

        VariableMeta(QList<int> sizesForDimensions)
        {
            _sizesForDimensions = sizesForDimensions;
        }

        int Id;
        QString Name;
        QString Type;
        QString RequiredValue;

        int GetDimensionsCount()
        {
            return _sizesForDimensions.count();
        }

        int GetSizeForDimension(int dimensionNumber)
        {
            return _sizesForDimensions.at(dimensionNumber - 1);
        }

        bool IsScalar()
        {
            return GetDimensionsCount() == 0;
        }

        bool IsLinearArray()
        {
            return GetDimensionsCount() == 1;
        }

        QString GetColumnName()
        {
            return Name.toLower() == "id" ? Name + "_sugar" : Name;
        }
    };

    class CustomTypeMeta
    {
    public:
        SMART_PTR_T(CustomTypeMeta);

        int Id;
        QString Name;
        int Size;

        QList<VariableMeta::SharedPtr_t> Variables;
        QString TableName;

        // Сделано приближение что не бывает смешанных динамических\статических массивов
        // и что динамические многомерные массивы равнозначны одномерным
        // fieldCount = (struct_size - static_fields_size) / (the_other_fields_size)
        int GetFilledArrayFieldsSize(MetaInfo* metaInfo, int msgBodySize);
    };

    class MessageMeta : public CustomTypeMeta
    {
    public:
        SMART_PTR_T(MessageMeta);

        QString Title;
        
        // Каким способом можно валидировать данное сообщение
        MessageValidation::SharedPtr_t Validation;
        // NonStandardTextMessage, StandardTextMessage итд
        MessageKind::SharedPtr_t Kind;
        // Альманахи, обычные сообщения
        MessageType::SharedPtr_t Type;

        QList<MessageCode::SharedPtr_t> Codes;

        int FindMessageCodeId(const char* code);

        QString FindMessageCodeCode(int id);
    };

    class MetaInfo
    {
    public:
        SMART_PTR_T(MetaInfo);

        MetaInfo()
        {
        }

        QList<MessageMeta::SharedPtr_t> MessagesMeta;
        QList<CustomTypeMeta::SharedPtr_t> CustomTypesMeta;

        QMap<int, SizeSpecialValue::SharedPtr_t> SizeSpecialValueClassifier;

        static MetaInfo::SharedPtr_t FromDatabase(Connection* connection);
    };
}

#endif // MetaInfo_h__