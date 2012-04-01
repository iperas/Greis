#include "RotationMatrixAndVectorsStdMessage.h"
#include <cassert>

namespace Greis
{
    RotationMatrixAndVectorsStdMessage::RotationMatrixAndVectorsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, _time);
        p_message += sizeof(_time);
        _serializer.Deserialize(p_message, _q00);
        p_message += sizeof(_q00);
        _serializer.Deserialize(p_message, _q01);
        p_message += sizeof(_q01);
        _serializer.Deserialize(p_message, _q02);
        p_message += sizeof(_q02);
        _serializer.Deserialize(p_message, _q12);
        p_message += sizeof(_q12);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * 3, _rms);
        p_message += sizeof(std::vector<Types::f4>::value_type) * 3;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::u1>::value_type) * 3, _solType);
        p_message += sizeof(std::vector<Types::u1>::value_type) * 3;
        _serializer.Deserialize(p_message, _flag);
        p_message += sizeof(_flag);
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * 3, _bl0);
        p_message += sizeof(std::vector<Types::f4>::value_type) * 3;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * 3, _bl1);
        p_message += sizeof(std::vector<Types::f4>::value_type) * 3;
        _serializer.Deserialize(p_message, sizeof(std::vector<Types::f4>::value_type) * 3, _bl2);
        p_message += sizeof(std::vector<Types::f4>::value_type) * 3;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string RotationMatrixAndVectorsStdMessage::ToString() const
    {
        return toString("RotationMatrixAndVectorsStdMessage");
    }
    bool RotationMatrixAndVectorsStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Bin(message.data(), message.size());
    }

    QByteArray RotationMatrixAndVectorsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_time, result);
        _serializer.Serialize(_q00, result);
        _serializer.Serialize(_q01, result);
        _serializer.Serialize(_q02, result);
        _serializer.Serialize(_q12, result);
        _serializer.Serialize(_rms, result);
        _serializer.Serialize(_solType, result);
        _serializer.Serialize(_flag, result);
        _serializer.Serialize(_bl0, result);
        _serializer.Serialize(_bl1, result);
        _serializer.Serialize(_bl2, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
