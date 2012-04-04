#include "REStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    REStdMessage::REStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 0) / 1;

        _serializer.Deserialize(p_message, arraySizeInUniformFillFields, _reply);
        p_message += arraySizeInUniformFillFields;
        
        assert(p_message - pc_message == p_length);
    }
    
    REStdMessage::REStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string REStdMessage::ToString() const
    {
        return toString("REStdMessage");
    }
    
    bool REStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void REStdMessage::RecalculateChecksum()
    {
        
    }

    QByteArray REStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_reply, result);
        
        assert(result.size() == Size());
        return result;
    }
}
