#include "NonStdTextMessage.h"
#include <boost/format.hpp>

using std::string;

namespace Greis
{
    NonStdTextMessage::NonStdTextMessage(char p_eom) : Message(EMessageKind::NonStdTextMessage)
    {
        _id = 0;
        _eom = p_eom;
    }

    NonStdTextMessage::NonStdTextMessage(char p_id, std::string p_body, char p_eom) 
        : Message(EMessageKind::NonStdTextMessage)
    {
        _id = p_id;
        _body = p_body;
        _eom = p_eom;
    }

    std::string NonStdTextMessage::ToString() const
    {
        string eomStr = _eom == '\r' ? "\\r" : (_eom == '\n' ? "\\n" : string(1, _eom));
        string ret = boost::str(boost::format(
            "<NonStdTextMessage id=0x%1$02X body_length=%2% eom='%3%'>%4%</NonStdTextMessage>") % (int)_id 
            % _body.size() % eomStr % _body);
        return ret;
    }

    bool NonStdTextMessage::Validate() const
    {
        if (_body.size() > 0 && (_id < MinIdValue || _id > MaxIdValue))
            return false;
        if (!IsEom(_eom))
            return false;
        return true;
    }
}
