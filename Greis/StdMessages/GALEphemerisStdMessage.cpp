#include "GALEphemerisStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    GALEphemerisStdMessage::GALEphemerisStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 122, _req);
        p_message += 122;
        _serializer.Deserialize(p_message, _bgdE1E5a);
        p_message += sizeof(_bgdE1E5a);
        _serializer.Deserialize(p_message, _bgdE1E5b);
        p_message += sizeof(_bgdE1E5b);
        _serializer.Deserialize(p_message, _ai0);
        p_message += sizeof(_ai0);
        _serializer.Deserialize(p_message, _ai1);
        p_message += sizeof(_ai1);
        _serializer.Deserialize(p_message, _ai2);
        p_message += sizeof(_ai2);
        _serializer.Deserialize(p_message, _sfi);
        p_message += sizeof(_sfi);
        _serializer.Deserialize(p_message, _navType);
        p_message += sizeof(_navType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }
    
    GALEphemerisStdMessage::GALEphemerisStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string GALEphemerisStdMessage::ToString() const
    {
        return toString("GALEphemerisStdMessage");
    }
    
    bool GALEphemerisStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }
    
    void GALEphemerisStdMessage::RecalculateChecksum()
    {
        auto message = ToByteArray();
        _cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
    }

    QByteArray GALEphemerisStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_req, result);
        _serializer.Serialize(_bgdE1E5a, result);
        _serializer.Serialize(_bgdE1E5b, result);
        _serializer.Serialize(_ai0, result);
        _serializer.Serialize(_ai1, result);
        _serializer.Serialize(_ai2, result);
        _serializer.Serialize(_sfi, result);
        _serializer.Serialize(_navType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
