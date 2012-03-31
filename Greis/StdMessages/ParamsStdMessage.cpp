#include "ParamsStdMessage.h"
#include <cassert>

namespace Greis
{
    ParamsStdMessage::ParamsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 4) / 1;

        _serializer.Deserialize(p_message, sizeof(_params) * arraySizeInUniformFillFields, _params);
        p_message += sizeof(_params) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, sizeof(_delim) * 2, _delim);
        p_message += sizeof(_delim) * 2;
        _serializer.Deserialize(p_message, sizeof(_cs) * 2, _cs);
        p_message += sizeof(_cs) * 2;
        
        assert(p_message - pc_message == p_length);
    }

    std::string ParamsStdMessage::ToString() const
    {
        return toString("ParamsStdMessage");
    }

    QByteArray ParamsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_params, result);
        _serializer.Serialize(_delim, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
