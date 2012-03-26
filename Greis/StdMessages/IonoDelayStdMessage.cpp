#include "IonoDelayStdMessage.h"

namespace Greis
{
    IonoDelayStdMessage::IonoDelayStdMessage( char* p_message, int p_length ) 
        : _id(p_message, 2), _bodySize(p_length - HeadSize())
    {
        // ${stub}
    }

    std::string IonoDelayStdMessage::ToString() const
    {
        return toString("IonoDelayStdMessage");
    }

    QByteArray IonoDelayStdMessage::ToByteArray() const
    {
        QByteArray result;
        result.append(headToByteArray());

        // ${stub}
        
        return result;
    }
}
