#include "ExampleStdMessage.h"

namespace Greis
{
    ExampleStdMessage::ExampleStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string ExampleStdMessage::ToString() const
    {
        return toString("ExampleStdMessage");
    }

    QByteArray ExampleStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
