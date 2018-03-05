#include "ExtSpecDataCustomType.h"
#include <cassert>
#include "Common/Logger.h"

namespace Greis
{
    ExtSpecDataCustomType::ExtSpecDataCustomType( const char* pc_message, int p_length )
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        /*throw Common::NotImplementedException();*/

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The custom type %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(IdNumber()).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    ExtSpecDataCustomType::ExtSpecDataCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray ExtSpecDataCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_spec, result);
        _serializer.Serialize(_agcmin, result);
        _serializer.Serialize(_agcmax, result);
        
        assert(result.size() == Size());
        return result;
    }
}
