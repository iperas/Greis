#include "RawMeasStdMessage.h"
#include <cassert>

namespace Greis
{
    RawMeasStdMessage::RawMeasStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        throw ProjectBase::NotImplementedException();
        
        assert(p_message - pc_message == p_length);
    }
    
    RawMeasStdMessage::RawMeasStdMessage( const std::string& p_id, int p_bodySize ) 
        : _id(p_id), _bodySize(p_bodySize)
    {
    }

    std::string RawMeasStdMessage::ToString() const
    {
        return toString("RawMeasStdMessage");
    }
    bool RawMeasStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        return true;
    }

    QByteArray RawMeasStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_sample, result);
        _serializer.Serialize(_scale, result);
        _serializer.Serialize(_reftime, result);
        _serializer.Serialize(_clock, result);
        _serializer.Serialize(_flags, result);
        _serializer.Serialize(_svd, result);
        _serializer.Serialize(_crc16, result);
        
        assert(result.size() == Size());
        return result;
    }
}
