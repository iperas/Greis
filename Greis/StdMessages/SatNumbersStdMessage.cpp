#include "SatNumbersStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    SatNumbersStdMessage::SatNumbersStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 1;

        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields, _osn);
        p_message += sizeof(std::vector<Types::u1>::value_type) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    SatNumbersStdMessage::SatNumbersStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string SatNumbersStdMessage::ToString() const
    {
        return toString("SatNumbersStdMessage");
    }
    
    bool SatNumbersStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void SatNumbersStdMessage::RecalculateChecksum()
    {
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray SatNumbersStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_osn, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
