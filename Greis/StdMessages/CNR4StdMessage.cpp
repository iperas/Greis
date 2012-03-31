#include "CNR4StdMessage.h"
#include <cassert>

namespace Greis
{
    CNR4StdMessage::CNR4StdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 1;

        _serializer.Deserialize(p_message, sizeof(_cnrX4) * arraySizeInUniformFillFields, _cnrX4);
        p_message += sizeof(_cnrX4) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string CNR4StdMessage::ToString() const
    {
        return toString("CNR4StdMessage");
    }

    QByteArray CNR4StdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_cnrX4, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
