#include "IonoParamsStdMessage.h"
#include <cassert>

namespace Greis
{
    IonoParamsStdMessage::IonoParamsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _tot);
        p_message += sizeof(_tot);
        _serializer.Deserialize(p_message, _wn);
        p_message += sizeof(_wn);
        _serializer.Deserialize(p_message, _alpha0);
        p_message += sizeof(_alpha0);
        _serializer.Deserialize(p_message, _alpha1);
        p_message += sizeof(_alpha1);
        _serializer.Deserialize(p_message, _alpha2);
        p_message += sizeof(_alpha2);
        _serializer.Deserialize(p_message, _alpha3);
        p_message += sizeof(_alpha3);
        _serializer.Deserialize(p_message, _beta0);
        p_message += sizeof(_beta0);
        _serializer.Deserialize(p_message, _beta1);
        p_message += sizeof(_beta1);
        _serializer.Deserialize(p_message, _beta2);
        p_message += sizeof(_beta2);
        _serializer.Deserialize(p_message, _beta3);
        p_message += sizeof(_beta3);
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string IonoParamsStdMessage::ToString() const
    {
        return toString("IonoParamsStdMessage");
    }
    bool IonoParamsStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray IonoParamsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_tot, result);
        _serializer.Serialize(_wn, result);
        _serializer.Serialize(_alpha0, result);
        _serializer.Serialize(_alpha1, result);
        _serializer.Serialize(_alpha2, result);
        _serializer.Serialize(_alpha3, result);
        _serializer.Serialize(_beta0, result);
        _serializer.Serialize(_beta1, result);
        _serializer.Serialize(_beta2, result);
        _serializer.Serialize(_beta3, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
