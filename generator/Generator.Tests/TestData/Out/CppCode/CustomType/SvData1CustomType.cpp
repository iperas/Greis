#include "SvData1CustomType.h"
#include <cassert>
#include "common/Logger.h"

namespace Greis
{
    SvData1CustomType::SvData1CustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _fcn1);
        p_message += sizeof(_fcn1);
        _serializer.Deserialize(p_message, _cnt);
        p_message += sizeof(_cnt);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u4>::value_type) * 4, _data);
        p_message += sizeof(std::vector<Types::u4>::value_type) * 4;

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    SvData1CustomType::SvData1CustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray SvData1CustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_fcn1, result);
        _serializer.Serialize(_cnt, result);
        _serializer.Serialize(_data, result);
        
        assert(result.size() == Size());
        return result;
    }
}
