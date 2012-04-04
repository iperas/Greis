#include "GALAlmStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    GALAlmStdMessage::GALAlmStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 46, _gps);
        p_message += 46;
        _serializer.Deserialize(p_message, _iod);
        p_message += sizeof(_iod);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    GALAlmStdMessage::GALAlmStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string GALAlmStdMessage::ToString() const
    {
        return toString("GALAlmStdMessage");
    }
    
    bool GALAlmStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void GALAlmStdMessage::RecalculateChecksum()
    {
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray GALAlmStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_gps, result);
        _serializer.Serialize(_iod, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
