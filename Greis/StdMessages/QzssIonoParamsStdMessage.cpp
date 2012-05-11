#include "QzssIonoParamsStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"

namespace Greis
{
    QzssIonoParamsStdMessage::QzssIonoParamsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 39, _par);
        p_message += 39;
        
        assert(p_message - pc_message == p_length);
    }
    
    QzssIonoParamsStdMessage::QzssIonoParamsStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string QzssIonoParamsStdMessage::ToString() const
    {
        return toString("QzssIonoParamsStdMessage");
    }
    
    bool QzssIonoParamsStdMessage::Validate() const
    {
        if (!StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void QzssIonoParamsStdMessage::RecalculateChecksum()
    {
        
    }

    QByteArray QzssIonoParamsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        _serializer.Serialize(_par, result);
        
        assert(result.size() == Size());
        return result;
    }
}
