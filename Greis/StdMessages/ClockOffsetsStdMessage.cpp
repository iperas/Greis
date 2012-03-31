#include "ClockOffsetsStdMessage.h"
#include <cassert>

namespace Greis
{
    ClockOffsetsStdMessage::ClockOffsetsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 7) / 8;

        _serializer.Deserialize(p_message, _sample);
        p_message += sizeof(_sample);
        _serializer.Deserialize(p_message, _reserved);
        p_message += sizeof(_reserved);
        _serializer.Deserialize(p_message, _recSize);
        p_message += sizeof(_recSize);
        _serializer.Deserialize(p_message, 8 * arraySizeInUniformFillFields, 8, _Offs);
        p_message += 8 * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _crc16);
        p_message += sizeof(_crc16);
        
        assert(p_message - pc_message == p_length);
    }

    std::string ClockOffsetsStdMessage::ToString() const
    {
        return toString("ClockOffsetsStdMessage");
    }
    bool ClockOffsetsStdMessage::Validate() const
    {
        if (!Validate())
        {
            return false;
        }

        return true;
    }

    QByteArray ClockOffsetsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_sample, result);
        _serializer.Serialize(_reserved, result);
        _serializer.Serialize(_recSize, result);
        _serializer.Serialize(_Offs, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
