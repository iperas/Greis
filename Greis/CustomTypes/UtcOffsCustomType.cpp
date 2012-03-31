#include "UtcOffsCustomType.h"
#include <cassert>

namespace Greis
{
    UtcOffsCustomType::UtcOffsCustomType( const char* pc_message, int p_length ) 
        : _size(p_length)
    {
        char* p_message = const_cast<char*>(pc_message);
    
        _serializer.Deserialize(p_message, _a0);
        p_message += sizeof(_a0);
        _serializer.Deserialize(p_message, _a1);
        p_message += sizeof(_a1);
        _serializer.Deserialize(p_message, _tot);
        p_message += sizeof(_tot);
        _serializer.Deserialize(p_message, _wnt);
        p_message += sizeof(_wnt);
        _serializer.Deserialize(p_message, _dtls);
        p_message += sizeof(_dtls);
        _serializer.Deserialize(p_message, _dn);
        p_message += sizeof(_dn);
        _serializer.Deserialize(p_message, _wnlsf);
        p_message += sizeof(_wnlsf);
        _serializer.Deserialize(p_message, _dtlsf);
        p_message += sizeof(_dtlsf);
        
        assert(p_message - pc_message == p_length);
    }

    QByteArray UtcOffsCustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_a0, result);
        _serializer.Serialize(_a1, result);
        _serializer.Serialize(_tot, result);
        _serializer.Serialize(_wnt, result);
        _serializer.Serialize(_dtls, result);
        _serializer.Serialize(_dn, result);
        _serializer.Serialize(_wnlsf, result);
        _serializer.Serialize(_dtlsf, result);
        
        assert(result.size() == Size());
        return result;
    }
}
