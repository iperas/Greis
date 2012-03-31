#include "PRStdMessage.h"
#include <cassert>

namespace Greis
{
    PRStdMessage::PRStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 8;

        _serializer.Deserialize(p_message, sizeof(_pr) * arraySizeInUniformFillFields, _pr);
        p_message += sizeof(_pr) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string PRStdMessage::ToString() const
    {
        return toString("PRStdMessage");
    }

    QByteArray PRStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_pr, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
