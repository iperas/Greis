#include "SpecDataCustomType.h"
#include <cassert>
#include "common/Logger.h"

namespace Greis
{
    SpecDataCustomType::SpecDataCustomType( const char* pc_message, int p_length )
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
    
    SpecDataCustomType::SpecDataCustomType( int p_size ) 
        : _size(p_size)
    {
        _isCorrect = true;
    }

    QByteArray SpecDataCustomType::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        _serializer.Serialize(_spec, result);
        
        assert(result.size() == Size());
        return result;
    }
}
