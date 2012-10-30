#include "${ClassName}.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"

namespace Greis
{
    ${ClassName}::${ClassName}( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        // ${DeserializationConstructorStub}

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    ${ClassName}::${ClassName}( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string ${ClassName}::ToString() const
    {
        return toString("${ClassName}");
    }
    
    bool ${ClassName}::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
            return false;
        }// ${ValidateStub}
    }
    
    void ${ClassName}::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        // ${RecalculateChecksumStub}
    }

    QByteArray ${ClassName}::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        assert(result.size() == Size());
        return result;
    }
}
