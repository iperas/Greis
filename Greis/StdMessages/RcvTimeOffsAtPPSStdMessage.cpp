#include "RcvTimeOffsAtPPSStdMessage.h"
#include <cassert>

namespace Greis
{
    RcvTimeOffsAtPPSStdMessage::RcvTimeOffsAtPPSStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _offs);
        p_message += sizeof(_offs);
        _serializer.Deserialize(p_message, _timeScale);
        p_message += sizeof(_timeScale);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string RcvTimeOffsAtPPSStdMessage::ToString() const
    {
        return toString("RcvTimeOffsAtPPSStdMessage");
    }
    bool RcvTimeOffsAtPPSStdMessage::Validate() const
    {
        if (!Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray RcvTimeOffsAtPPSStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_offs, result);
        _serializer.Serialize(_timeScale, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
