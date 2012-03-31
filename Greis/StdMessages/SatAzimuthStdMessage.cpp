#include "SatAzimuthStdMessage.h"
#include <cassert>

namespace Greis
{
    SatAzimuthStdMessage::SatAzimuthStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 1;

        _serializer.Deserialize(p_message, sizeof(_azim) * arraySizeInUniformFillFields, _azim);
        p_message += sizeof(_azim) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string SatAzimuthStdMessage::ToString() const
    {
        return toString("SatAzimuthStdMessage");
    }

    QByteArray SatAzimuthStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_azim, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}