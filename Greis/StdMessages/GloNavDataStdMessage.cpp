#include "GloNavDataStdMessage.h"
#include <cassert>

namespace Greis
{
    GloNavDataStdMessage::GloNavDataStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 2) / 18;

        _serializer.Deserialize(p_message, _recSize);
        p_message += sizeof(_recSize);
        _serializer.Deserialize(p_message, 18 * arraySizeInUniformFillFields, 18, _dat);
        p_message += 18 * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    GloNavDataStdMessage::GloNavDataStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string GloNavDataStdMessage::ToString() const
    {
        return toString("GloNavDataStdMessage");
    }
    bool GloNavDataStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray GloNavDataStdMessage::ToByteArray() const
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
