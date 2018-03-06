#include "ParamsStdMessage.h"
#include <cassert>
#include "common/Logger.h"
#include "greis/ChecksumComputer.h"

namespace Greis
{
    ParamsStdMessage::ParamsStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        int arraySizeInUniformFillFields = (BodySize() - 0) / 1;

        _serializer.Deserialize(p_message, arraySizeInUniformFillFields, _params);
        p_message += arraySizeInUniformFillFields;

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    ParamsStdMessage::ParamsStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
        _isCorrect = true;
    }

    std::string ParamsStdMessage::ToString() const
    {
        return toString("ParamsStdMessage");
    }
    
    bool ParamsStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }

        return true;
    }
    
    void ParamsStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        
    }

    QByteArray ParamsStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_params, result);
        
        assert(result.size() == Size());
        return result;
    }
}
