#include "QzssRawNavDataStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    QzssRawNavDataStdMessage::QzssRawNavDataStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        throw ProjectBase::NotImplementedException();
        
        assert(p_message - pc_message == p_length);
    }
    
    QzssRawNavDataStdMessage::QzssRawNavDataStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string QzssRawNavDataStdMessage::ToString() const
    {
        return toString("QzssRawNavDataStdMessage");
    }
    
    bool QzssRawNavDataStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void QzssRawNavDataStdMessage::RecalculateChecksum()
    {
        
    }

    QByteArray QzssRawNavDataStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_data, result);
        
        assert(result.size() == Size());
        return result;
    }
}
