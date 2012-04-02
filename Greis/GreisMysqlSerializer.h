#ifndef GreisMysqlSerializer_h__
#define GreisMysqlSerializer_h__

#include <QtCore/QByteArray>
#include <QtCore/QVariant>
#include <string>
#include <vector>
#include <cassert>
#include "GreisBinarySerializer.h"
#include "GreisTypes.h"

namespace Greis
{
    class GreisMysqlSerializer
    {
    public:
        GreisMysqlSerializer()
        {
        }

        // Serialization

        // Important limitations:
        // Custom Types are not serialized this way (nor scalar or vector).
        // Only linear vectors of Greis Types are supported.

        inline QVariant SerializeChar(Types::a1 val)
        {
            return QVariant(QChar::fromAscii(val));
        }

        inline QVariant Serialize(Types::u1 val)
        {
            return QVariant((unsigned int) val);
        }

        inline QVariant Serialize(Types::u2 val)
        {
            return QVariant((unsigned int) val);
        }

        inline QVariant Serialize(Types::u4 val)
        {
            return QVariant((unsigned int) val);
        }

        inline QVariant Serialize(Types::i1 val)
        {
            return QVariant((int) val);
        }

        inline QVariant Serialize(Types::i2 val)
        {
            return QVariant((int) val);
        }

        inline QVariant Serialize(Types::i4 val)
        {
            return QVariant((int) val);
        }

        inline QVariant Serialize(float val)
        {
            return QVariant(val);
        }

        inline QVariant Serialize(double val)
        {
            return QVariant(val);
        }

        inline QVariant Serialize(std::string val)
        {
            return QVariant(QString::fromAscii(val.c_str(), val.size()));
        }

        // vector of Greis types
        template<typename T>
        QVariant Serialize(const std::vector<T>& val)
        {
            static_assert(std::is_arithmetic<T>::value, "T is not a Greis type.");

            QByteArray ba;
            _binSerializer.Serialize(val, ba);
            return ba;
        }

        // Deserialization

        /*void Deserialize(const char* data, unsigned char& retVal)
        {
            retVal = *((unsigned char*)data);
        }

        void Deserialize(const char* data, unsigned short& retVal)
        {
            retVal = _bitConverter.GetUShort(data);
        }

        void Deserialize(const char* data, unsigned int& retVal)
        {
            retVal = _bitConverter.GetUInt(data);
        }

        void Deserialize(const char* data, char& retVal)
        {
            retVal = *data;
        }

        void Deserialize(const char* data, short& retVal)
        {
            retVal = _bitConverter.GetShort(data);
        }

        void Deserialize(const char* data, int& retVal)
        {
            retVal = _bitConverter.GetInt(data);
        }

        void Deserialize(const char* data, float& retVal)
        {
            retVal = _bitConverter.GetFloat(data);
        }

        void Deserialize(const char* data, double& retVal)
        {
            retVal = _bitConverter.GetDouble(data);
        }

        void Deserialize(const char* data, int length, std::string& retVal)
        {
            retVal = std::string(data, length);
        }

        template<typename T>
        void Deserialize(const char* data, int length, std::unique_ptr<T>& retVal)
        {
            retVal = ProjectBase::make_unique<T>(data, length);
        }

        // Deserialization for std::vector<Greis::Type>
        template<typename T>
        void Deserialize(const char* data, int length, std::vector<T>& retVal)
        {
            static_assert(std::is_arithmetic<T>::value, "T is not a Greis type.");
            int itemSize = sizeof(T);
            assert(length % itemSize == 0);
            retVal.clear();
            for (int i = 0; i < length; i += itemSize)
            {
                T val;
                Deserialize(data + i, val);
                retVal.push_back(std::move(val));
            }
        }

        // Deserialization for std::vector<std::string> is not possible

        // Deserialization for std::vector<CustomType::UniquePtr_t> && std::vector<std::vector<...>> 
        // (where ... is GreisType or vector)
        template<typename T>
        void Deserialize(const char* data, int length, int itemSize, std::vector<T>& retVal)
        {
            assert(length % itemSize == 0);
            retVal.clear();
            for (int i = 0; i < length; i += itemSize)
            {
                T val;
                Deserialize(data + i, itemSize, val);
                retVal.push_back(std::move(val));
            }
        }*/
    private:
        GreisBinarySerializer _binSerializer;
    };
}

#endif // GreisMysqlSerializer_h__
