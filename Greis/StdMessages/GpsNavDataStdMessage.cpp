#include "GpsNavDataStdMessage.h"
#include <cassert>

namespace Greis
{
    GpsNavDataStdMessage::GpsNavDataStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 2) / 42;

        _serializer.Deserialize(p_message, _recSize);
        p_message += sizeof(_recSize);
        _serializer.Deserialize(p_message, 42 * arraySizeInUniformFillFields, 42, _dat);
        p_message += 42 * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GpsNavDataStdMessage::ToString() const
    {
        return toString("GpsNavDataStdMessage");
    }

    QByteArray GpsNavDataStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_recSize, result);
        _serializer.Serialize(_dat, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
