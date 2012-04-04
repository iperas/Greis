#include "ParamsStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    ParamsStdMessage::ParamsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 4) / 1;

        _serializer.Deserialize(p_message, arraySizeInUniformFillFields, _params);
        p_message += arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, 2, _delim);
        p_message += 2;
        _serializer.Deserialize(p_message, 2, _cs);
        p_message += 2;
        
        assert(p_message - pc_message == p_length);
    }
    
    ParamsStdMessage::ParamsStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string ParamsStdMessage::ToString() const
    {
        return toString("ParamsStdMessage");
    }
    
    bool ParamsStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Ascii(message.data(), message.size());
    }
    
    void ParamsStdMessage::RecalculateChecksum()
    {
        auto message = ToByteArray();
        auto cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
        auto ba = QString::number(cs, 16).toAscii();
        _cs[0] = ba[0]; _cs[1] = ba[1];
    }

    QByteArray ParamsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_params, result);
        _serializer.Serialize(_delim, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
