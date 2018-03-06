#include "GpsNavData1CustomType.h"
#include <cassert>
#include "common/Logger.h"

namespace Greis
{
    GpsNavData1CustomType::GpsNavData1CustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        int arraySizeInUniformFillFields = (Size() - 2) / 42;

        _serializer.Deserialize(p_message, _recSize);
        p_message += sizeof(_recSize);
        _serializer.Deserialize(p_message, 42 * arraySizeInUniformFillFields, 42, _dat);
        p_message += 42 * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GpsNavData1CustomType::GpsNavData1CustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray GpsNavData1CustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_recSize, result);
        _serializer.Serialize(_dat, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
