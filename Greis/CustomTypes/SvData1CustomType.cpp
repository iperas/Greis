#include "SvData1CustomType.h"
#include <cassert>

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
        _serializer.Deserialize(p_message, sizeof(_data) * 4, _data);
        p_message += sizeof(_data) * 4;
        
        assert(p_message - pc_message == p_length);
    }

    QByteArray SvData1CustomType::ToByteArray() const
    {
        QByteArray result;

        _serializer.Serialize(_fcn1, result);
        _serializer.Serialize(_cnt, result);
        _serializer.Serialize(_data, result);
        
        assert(result.size() == Size());
        return result;
    }
}
