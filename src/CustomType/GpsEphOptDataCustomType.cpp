#include "GpsEphOptDataCustomType.h"
#include <cassert>
#include "common/Logger.h"

namespace Greis
{
    GpsEphOptDataCustomType::GpsEphOptDataCustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _navType);
        p_message += sizeof(_navType);
        _serializer.Deserialize(p_message, _lTope);
        p_message += sizeof(_lTope);
        _serializer.Deserialize(p_message, _lTopc);
        p_message += sizeof(_lTopc);
        _serializer.Deserialize(p_message, _dADot);
        p_message += sizeof(_dADot);
        _serializer.Deserialize(p_message, _fDelnDot);
        p_message += sizeof(_fDelnDot);
        _serializer.Deserialize(p_message, _cURAoe);
        p_message += sizeof(_cURAoe);
        _serializer.Deserialize(p_message, _cURAoc);
        p_message += sizeof(_cURAoc);
        _serializer.Deserialize(p_message, _cURAoc1);
        p_message += sizeof(_cURAoc1);
        _serializer.Deserialize(p_message, _cURAoc2);
        p_message += sizeof(_cURAoc2);
        _serializer.Deserialize(p_message, _fIscL1CA);
        p_message += sizeof(_fIscL1CA);
        _serializer.Deserialize(p_message, _fIscL2C);
        p_message += sizeof(_fIscL2C);
        if (Size() == 45)
        {
            // Optional Data Block
            _serializer.Deserialize(p_message, _fIscL5I5);
            p_message += sizeof(_fIscL5I5);
            _serializer.Deserialize(p_message, _fIscL5Q5);
            p_message += sizeof(_fIscL5Q5);
        }
        _serializer.Deserialize(p_message, _DAf0);
        p_message += sizeof(_DAf0);

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    GpsEphOptDataCustomType::GpsEphOptDataCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray GpsEphOptDataCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_navType, result);
        _serializer.Serialize(_lTope, result);
        _serializer.Serialize(_lTopc, result);
        _serializer.Serialize(_dADot, result);
        _serializer.Serialize(_fDelnDot, result);
        _serializer.Serialize(_cURAoe, result);
        _serializer.Serialize(_cURAoc, result);
        _serializer.Serialize(_cURAoc1, result);
        _serializer.Serialize(_cURAoc2, result);
        _serializer.Serialize(_fIscL1CA, result);
        _serializer.Serialize(_fIscL2C, result);
        if (Size() == 45)
        {
            // Optional Data Block
            _serializer.Serialize(_fIscL5I5, result);
            _serializer.Serialize(_fIscL5Q5, result);
        }
        _serializer.Serialize(_DAf0, result);
        
        assert(result.size() == Size());
        return result;
    }
}
