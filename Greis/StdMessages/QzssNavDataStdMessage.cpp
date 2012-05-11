#include "QzssNavDataStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    QzssNavDataStdMessage::QzssNavDataStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        throw ProjectBase::NotImplementedException();
        
        assert(p_message - pc_message == p_length);
    }
    
    QzssNavDataStdMessage::QzssNavDataStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string QzssNavDataStdMessage::ToString() const
    {
        return toString("QzssNavDataStdMessage");
    }
    
    bool QzssNavDataStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void QzssNavDataStdMessage::RecalculateChecksum()
    {
        
    }

    QByteArray QzssNavDataStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_data, result);
        
        assert(result.size() == Size());
        return result;
    }
}
