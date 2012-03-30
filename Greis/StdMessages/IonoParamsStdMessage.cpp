#include "IonoParamsStdMessage.h"

namespace Greis
{
    IonoParamsStdMessage::IonoParamsStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${DeserializationConstructorStub}
    }

    std::string IonoParamsStdMessage::ToString() const
    {
        return toString("IonoParamsStdMessage");
    }

    QByteArray IonoParamsStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${ToByteArrayStub}
        
        return result;
    }
}
