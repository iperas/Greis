#include "FileIdStdMessage.h"
#include <cassert>

namespace Greis
{
    FileIdStdMessage::FileIdStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, sizeof(_idField) * 5, _idField);
        p_message += sizeof(_idField) * 5;
        _serializer.Deserialize(p_message, sizeof(_description) * 80, _description);
        p_message += sizeof(_description) * 80;
        
        assert(p_message - pc_message == p_length);
    }

    std::string FileIdStdMessage::ToString() const
    {
        return toString("FileIdStdMessage");
    }

    QByteArray FileIdStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_idField, result);
        _serializer.Serialize(_description, result);
        
        assert(result.size() == Size());
        return result;
    }
}
