#include "GeoVelStdMessage.h"
#include <cassert>

namespace Greis
{
    GeoVelStdMessage::GeoVelStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _lat);
        p_message += sizeof(_lat);
        _serializer.Deserialize(p_message, _lon);
        p_message += sizeof(_lon);
        _serializer.Deserialize(p_message, _alt);
        p_message += sizeof(_alt);
        _serializer.Deserialize(p_message, _pSigma);
        p_message += sizeof(_pSigma);
        _serializer.Deserialize(p_message, _solType);
        p_message += sizeof(_solType);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string GeoVelStdMessage::ToString() const
    {
        return toString("GeoVelStdMessage");
    }

    QByteArray GeoVelStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_lat, result);
        _serializer.Serialize(_lon, result);
        _serializer.Serialize(_alt, result);
        _serializer.Serialize(_pSigma, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}