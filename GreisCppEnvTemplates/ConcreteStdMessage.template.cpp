#include "${ConcreteStdMessage}.h"

namespace Greis
{
    ${ConcreteStdMessage}::${ConcreteStdMessage}( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string ${ConcreteStdMessage}::ToString() const
    {
        return toString("${ConcreteStdMessage}");
    }

    QByteArray ${ConcreteStdMessage}::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
