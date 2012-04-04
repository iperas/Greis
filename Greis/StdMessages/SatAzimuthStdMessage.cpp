#include "SatAzimuthStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    SatAzimuthStdMessage::SatAzimuthStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 1;

        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields, _azim);
        p_message += sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    SatAzimuthStdMessage::SatAzimuthStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string SatAzimuthStdMessage::ToString() const
    {
        return toString("SatAzimuthStdMessage");
    }
    
    bool SatAzimuthStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void SatAzimuthStdMessage::RecalculateChecksum()
    {
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
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
