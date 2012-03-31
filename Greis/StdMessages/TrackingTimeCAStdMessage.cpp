#include "TrackingTimeCAStdMessage.h"
#include <cassert>

namespace Greis
{
    TrackingTimeCAStdMessage::TrackingTimeCAStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 2;

        _serializer.Deserialize(p_message, sizeof(_tt) * arraySizeInUniformFillFields, _tt);
        p_message += sizeof(_tt) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string TrackingTimeCAStdMessage::ToString() const
    {
        return toString("TrackingTimeCAStdMessage");
    }

    QByteArray TrackingTimeCAStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_tt, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
