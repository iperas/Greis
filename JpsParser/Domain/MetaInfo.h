#ifndef MetaInfo_h__
#define MetaInfo_h__

#include <QList>
#include "Database/Connection.h"
#include "Util/SharedPtr.h"

using namespace Database;

namespace Domain
{
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
    };

    class MessageMeta
    {
    public:
        SHARED_PTR_T(MessageMeta);

        int Id;
        QString Name;
        QString Title;
        int Size;
        
        // Каким способом можно валидировать данное сообщение
        MessageValidation::Pointer_t Validation;
        // NonStandardTextMessage, StandardTextMessage итд
        MessageKind::Pointer_t Kind;
        // Альманахи, обычные сообщения
        MessageType::Pointer_t Type;

        QList<MessageCode::Pointer_t> Codes;
        QList<VariableMeta::Pointer_t> Variables;

        QString TableName;
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