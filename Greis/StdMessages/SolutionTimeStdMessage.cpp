#include "SolutionTimeStdMessage.h"
#include <cassert>

namespace Greis
{
    SolutionTimeStdMessage::SolutionTimeStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string SolutionTimeStdMessage::ToString() const
    {
        return toString("SolutionTimeStdMessage");
    }

    QByteArray SolutionTimeStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_time, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
