#include "SCStdMessage.h"
#include <cassert>

namespace Greis
{
    SCStdMessage::SCStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 6;

        _serializer.Deserialize(p_message, 6 * arraySizeInUniformFillFields, 6, _smooth);
        p_message += 6 * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string SCStdMessage::ToString() const
    {
        return toString("SCStdMessage");
    }

    QByteArray SCStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_smooth, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
