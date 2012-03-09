#include "MetaInfo.h"
#include "MetaInfoReader.h"
#include <algorithm>

using std::find_if;

namespace Domain
{
    MetaInfo::Pointer_t MetaInfo::FromDatabase(Connection* connection)
    {
        return MetaInfoReader(connection).Load();
    }

    int CustomTypeMeta::GetFilledArrayFieldsSize( MetaInfo* metaInfo, int msgBodySize )
    {
        if (Size != SizeSpecialValueClassifier::Fill)
        {
            return -1;
        }

        static QMap<QString, int> simpleTypesSize;
        simpleTypesSize["a1"] = 1;
        simpleTypesSize["u1"] = 1;
        simpleTypesSize["u2"] = 2;
        simpleTypesSize["u4"] = 4;
        simpleTypesSize["i1"] = 1;
        simpleTypesSize["i2"] = 2;
        simpleTypesSize["i4"] = 4;
        simpleTypesSize["f4"] = 4;
        simpleTypesSize["f8"] = 8;
        int fillFieldsTypeSize = 0;

        int size = msgBodySize;
        foreach (VariableMeta::Pointer_t varMeta, Variables)
        {
            // typeSize computing
            int typeSize;
            if (simpleTypesSize.contains(varMeta->Type))
            {
                typeSize = simpleTypesSize[varMeta->Type];
            } else {
                CustomTypeMeta::Pointer_t varType;
                foreach (CustomTypeMeta::Pointer_t ct, metaInfo->CustomTypesMeta)
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
        int fillFieldsCount = size / fillFieldsTypeSize;
        return fillFieldsCount;
    }

    int MessageMeta::FindMessageCodeId( const char* code )
    {
        auto it = find_if(Codes.constBegin(), Codes.constEnd(), 
            [code] (const MessageCode::Pointer_t& testMsgCode) -> bool
            {
                auto testCode = testMsgCode->Code.toAscii();
                return code[0] == testCode[0] && code[1] == testCode[1];
            });
        if (it == Codes.constEnd())
        {
            // Unknown code
            return -1;
        }
        auto msgCodeId = (*it)->Id;
        return msgCodeId;
    }

    QString MessageMeta::FindMessageCodeCode(int id)
    {
        auto it = find_if(Codes.constBegin(), Codes.constEnd(), 
            [id] (const MessageCode::Pointer_t& testMsgCode) -> bool
        {
            return testMsgCode->Id == id;
        });
        if (it == Codes.constEnd())
        {
            // Unknown code
            return QString::null;
        }
        auto msgCodeCode = (*it)->Code;
        return msgCodeCode;
    }
}
