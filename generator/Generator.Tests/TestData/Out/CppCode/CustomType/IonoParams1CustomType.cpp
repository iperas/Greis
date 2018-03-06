#include "IonoParams1CustomType.h"
#include <cassert>
#include "common/Logger.h"

namespace Greis
{
    IonoParams1CustomType::IonoParams1CustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _tot);
        p_message += sizeof(_tot);
        _serializer.Deserialize(p_message, _wn);
        p_message += sizeof(_wn);
        _serializer.Deserialize(p_message, _alpha0);
        p_message += sizeof(_alpha0);
        _serializer.Deserialize(p_message, _alpha1);
        p_message += sizeof(_alpha1);
        _serializer.Deserialize(p_message, _alpha2);
        p_message += sizeof(_alpha2);
        _serializer.Deserialize(p_message, _alpha3);
        p_message += sizeof(_alpha3);
        _serializer.Deserialize(p_message, _beta0);
        p_message += sizeof(_beta0);
        _serializer.Deserialize(p_message, _beta1);
        p_message += sizeof(_beta1);
        _serializer.Deserialize(p_message, _beta2);
        p_message += sizeof(_beta2);
        _serializer.Deserialize(p_message, _beta3);
        p_message += sizeof(_beta3);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    IonoParams1CustomType::IonoParams1CustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray IonoParams1CustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_tot, result);
        _serializer.Serialize(_wn, result);
        _serializer.Serialize(_alpha0, result);
        _serializer.Serialize(_alpha1, result);
        _serializer.Serialize(_alpha2, result);
        _serializer.Serialize(_alpha3, result);
        _serializer.Serialize(_beta0, result);
        _serializer.Serialize(_beta1, result);
        _serializer.Serialize(_beta2, result);
        _serializer.Serialize(_beta3, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
