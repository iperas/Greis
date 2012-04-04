#include "ClkOffsCustomType.h"
#include <cassert>

namespace Greis
{
    ClkOffsCustomType::ClkOffsCustomType( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _word1);
        p_message += sizeof(_word1);
        _serializer.Deserialize(p_message, _word2);
        p_message += sizeof(_word2);
        
        assert(p_message - pc_message == p_length);
    }
    
    ClkOffsCustomType::ClkOffsCustomType( int p_size ) 
        : _size(p_size)
    {
    }

    QByteArray ClkOffsCustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_word1, result);
        _serializer.Serialize(_word2, result);
        
        assert(result.size() == Size());
        return result;
    }
}
