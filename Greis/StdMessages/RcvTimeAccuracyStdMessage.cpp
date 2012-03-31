#include "RcvTimeAccuracyStdMessage.h"
#include <cassert>

namespace Greis
{
    RcvTimeAccuracyStdMessage::RcvTimeAccuracyStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _acc);
        p_message += sizeof(_acc);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string RcvTimeAccuracyStdMessage::ToString() const
    {
        return toString("RcvTimeAccuracyStdMessage");
    }

    QByteArray RcvTimeAccuracyStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_acc, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
