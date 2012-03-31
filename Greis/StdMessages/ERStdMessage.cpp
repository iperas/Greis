#include "ERStdMessage.h"
#include <cassert>

namespace Greis
{
    ERStdMessage::ERStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 0) / 1;

        _serializer.Deserialize(p_message, sizeof(_error) * arraySizeInUniformFillFields, _error);
        p_message += sizeof(_error) * arraySizeInUniformFillFields;
        
        assert(p_message - pc_message == p_length);
    }

    std::string ERStdMessage::ToString() const
    {
        return toString("ERStdMessage");
    }

    QByteArray ERStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_error, result);
        
        assert(result.size() == Size());
        return result;
    }
}
