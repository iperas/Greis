#ifndef MetaInfo_h__
#define MetaInfo_h__

#include <QList>
#include "Database/Connection.h"
#include "Util/SharedPtr.h"

using namespace Database;

namespace Domain
{
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
        SHARED_PTR_T(ClassifierItem);

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
        SHARED_PTR_T(MessageCode);

        int Id;
        QString Code;
    };

    class VariableMeta
    {
        QList<int> _sizesForDimensions;
    public:
        SHARED_PTR_T(VariableMeta);

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
        SHARED_PTR_T(CustomTypeMeta);

        int Id;
        QString Name;
        int Size;

        QList<VariableMeta::Pointer_t> Variables;
        QString TableName;
    };

    class MessageMeta : public CustomTypeMeta
    {
    public:
        SHARED_PTR_T(MessageMeta);

        QString Title;
        
        // Каким способом можно валидировать данное сообщение
        MessageValidation::Pointer_t Validation;
        // NonStandardTextMessage, StandardTextMessage итд
        MessageKind::Pointer_t Kind;
        // Альманахи, обычные сообщения
        MessageType::Pointer_t Type;

        QList<MessageCode::Pointer_t> Codes;
    };

    class MetaInfo
    {
    public:
        SHARED_PTR_T(MetaInfo);

        MetaInfo()
        {
        }

        QList<MessageMeta::Pointer_t> MessagesMeta;
        QList<CustomTypeMeta::Pointer_t> CustomTypesMeta;

        QMap<int, SizeSpecialValue::Pointer_t> SizeSpecialValueClassifier;

        static MetaInfo::Pointer_t FromDatabase(Connection* connection);
    };
}

#endif // MetaInfo_h__