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

        _serializer.Deserialize(p_message, sizeof(std::vector<Types::i1>::value_type) * arraySizeInUniformFillFields, _fcn);
        p_message += sizeof(std::vector<Types::i1>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * arraySizeInUniformFillFields, _phase);
        p_message += sizeof(std::vector<Types::f4>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * arraySizeInUniformFillFields, _range);
        p_message += sizeof(std::vector<Types::f4>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GloPhaseDelayStdMessage::ToString() const
    {
        return toString("GloPhaseDelayStdMessage");
    }
    bool GloPhaseDelayStdMessage::Validate() const
    {
        if (!Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
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
