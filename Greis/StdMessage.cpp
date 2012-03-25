#include "StdMessage.h"
#include "GreisTypes.h"
#include "ChecksumComputer.h"
#include "boost/format.hpp"

using std::string;
using std::vector;
using namespace ProjectBase;

namespace Greis
{
    StdMessage::StdMessage() : Message(EMessageKind::StdMessage)
    {
    }

    bool StdMessage::Validate() const
    {
        string aId = Id();
        if (aId[0] < MinIdValue || aId[0] > MaxIdValue || 
            aId[1] < MinIdValue || aId[1] > MaxIdValue)
            return false;
        return true;
    }

    bool StdMessage::validateChecksum8Ascii(char* p_message, int p_length)
    {
        // expected
        if (p_length < HeadSize() + 2)
        {
            throw Exception("Body too small.");
        }
        if (p_length == HeadSize() + 2)
        {
            return true;
        }
        bool bOk;
        Types::u1 expected = QString::fromAscii(p_message + p_length - 2, 2).toUInt(&bOk, 16);
        if (!bOk)
        {
            return false;
        }
        // actual
        Types::u1 actual = ChecksumComputer::ComputeCs8(p_message, p_length - 2);
        // check
        return expected == actual;
    }

    bool StdMessage::validateChecksum8Bin(char* p_message, int p_length)
    {
        // expected
        if (p_length < HeadSize() + 1)
        {
            throw Exception("Body too small.");
        }
        if (p_length == HeadSize() + 1)
        {
            return true;
        }
        Types::u1 expected = ((Types::u1*)p_message)[p_length - 1];
        // actual
        Types::u1 actual = ChecksumComputer::ComputeCs8(p_message, p_length - 1);
        // check
        return expected == actual;
    }
}
