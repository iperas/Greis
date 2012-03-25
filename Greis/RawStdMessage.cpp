#include "RawStdMessage.h"
#include "GreisTypes.h"
#include "ChecksumComputer.h"
#include "boost/format.hpp"

using std::string;
using std::vector;
using namespace ProjectBase;

namespace Greis
{
    RawStdMessage::RawStdMessage(char* p_message, int p_length) : _message(p_length)
    {
        memcpy(&_message[0], p_message, p_length);
    }

    std::string RawStdMessage::ToString() const
    {
        return toString("RawStdMessage");
    }

    std::string RawStdMessage::toString(const std::string& tagName) const
    {
        string ret = boost::str(boost::format("<%1% id='%2%' body_length=%3%>%4%</%1%>") 
            % tagName % Id() % BodySize() % bodyToString());
        return ret;
    }

    std::string RawStdMessage::bodyToString() const
    {
        string ret;
        for (vector<char>::const_iterator it = _message.begin() + 5; it != _message.end(); ++it)
        {
            char ch = *it;
            if (isprint((unsigned char)ch))
            {
                ret.push_back(ch);
            }
            else
            {
                ret.append(boost::str(boost::format("{0x%1$02X}") % (unsigned int)(unsigned char)ch));
            }
        }
        return ret;
    }
}
