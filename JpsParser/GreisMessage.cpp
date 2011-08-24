#include "GreisMessage.h"

namespace Greis
{
    NULL_PTR_IMPL(Message_t);

    NULL_PTR_IMPL(NonStdTextMessage_t);

    NULL_PTR_IMPL(StdMessage_t);

    NULL_PTR_IMPL(JPStdMessage_t);
    const string JPStdMessage_t::javadGnssId = "RLOGF";
    const string JPStdMessage_t::javadGnssDescriptionFormat = "JPS $ReceiverName$ Receiver log-file";
}
