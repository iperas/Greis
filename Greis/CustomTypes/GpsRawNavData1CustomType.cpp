#include "GpsRawNavData1CustomType.h"
#include "ProjectBase/Logger.h"
#include <cassert>

namespace Greis
{
    GpsRawNavData1CustomType::GpsRawNavData1CustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        int arraySizeInUniformFillFields = (Size() - 8) / 4;

        _serializer.Deserialize(p_message, _prn);
        p_message += sizeof(_prn);
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _type);
        p_message += sizeof(_type);
        _serializer.Deserialize(p_message, _len);
        p_message += sizeof(_len);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u4>::value_type) * arraySizeInUniformFillFields, _data);
        p_message += sizeof(std::vector<Types::u4>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GpsRawNavData1CustomType::GpsRawNavData1CustomType( int p_size ) 
        : _size(p_size)
    {
    }

    QByteArray GpsRawNavData1CustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_prn, result);
        _serializer.Serialize(_time, result);
        _serializer.Serialize(_type, result);
        _serializer.Serialize(_len, result);
        _serializer.Serialize(_data, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
