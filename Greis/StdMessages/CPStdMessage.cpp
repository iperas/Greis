#include "CPStdMessage.h"
#include <cassert>

namespace Greis
{
    CPStdMessage::CPStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 1) / 8;

        _serializer.Deserialize(p_message, sizeof(_cp) * arraySizeInUniformFillFields, _cp);
        p_message += sizeof(_cp) * arraySizeInUniformFillFields;
        _serializer.Deserialize(p_message, _cs);
        p_message += sizeof(_cs);
        
        assert(p_message - pc_message == p_length);
    }

    std::string CPStdMessage::ToString() const
    {
        return toString("CPStdMessage");
    }

    QByteArray CPStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_cp, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}