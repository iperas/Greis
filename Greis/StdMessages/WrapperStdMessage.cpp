#include "WrapperStdMessage.h"
#include <cassert>

namespace Greis
{
    WrapperStdMessage::WrapperStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 3) / 1;

        _serializer.Deserialize(p_message, _idField);
        p_message += sizeof(_idField);
        _serializer.Deserialize(p_message, sizeof(_data) * arraySizeInUniformFillFields, _data);
        p_message += sizeof(_data) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, sizeof(_cs) * 2, _cs);
        p_message += sizeof(_cs) * 2;
        
        assert(p_message - pc_message == p_length);
    }

    std::string WrapperStdMessage::ToString() const
    {
        return toString("WrapperStdMessage");
    }

    QByteArray WrapperStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_idField, result);
        _serializer.Serialize(_data, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
