#ifndef StdMessageFactory_h__
#define StdMessageFactory_h__

#include "StdMessage.h"
#include "RawStdMessage.h"

namespace Greis
{
    class StdMessageFactory
    {
    public:
        static StdMessage::UniquePtr_t Create(char* p_message, int p_length)
        {
            return StdMessage::UniquePtr_t(new RawStdMessage(p_message, p_length));
            /*EMessageType id = idToEnumMap(p_message);
            switch(id)
            {
            case JPStdMessage:
                return JPStdMessage_t::SharedPtr_t(new JPStdMessage_t(p_message, p_length));
            case MFStdMessage:
                return MFStdMessage_t::SharedPtr_t(new MFStdMessage_t(p_message, p_length));
            case RTStdMessage:
                return RTStdMessage_t::SharedPtr_t(new RTStdMessage_t(p_message, p_length));
            case UnknownStdMessage:
                return StdMessage_t::SharedPtr_t(new StdMessage_t(p_message, p_length));
            default:
                throw Exception("Invalid EMessageType value.");
            }*/
        }
    };
}

#endif // StdMessageFactory_h__
