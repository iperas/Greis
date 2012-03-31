#include "GloPhaseDelayStdMessage.h"
#include <cassert>

namespace Greis
{
    GloPhaseDelayStdMessage::GloPhaseDelayStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 9;

        _serializer.Deserialize(p_message, sizeof(_fcn) * arraySizeInUniformFillFields, _fcn);
        p_message += sizeof(_fcn) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, sizeof(_phase) * arraySizeInUniformFillFields, _phase);
        p_message += sizeof(_phase) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, sizeof(_range) * arraySizeInUniformFillFields, _range);
        p_message += sizeof(_range) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GloPhaseDelayStdMessage::ToString() const
    {
        return toString("GloPhaseDelayStdMessage");
    }

    QByteArray GloPhaseDelayStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_fcn, result);
        _serializer.Serialize(_phase, result);
        _serializer.Serialize(_range, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
