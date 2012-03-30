#include "GreisBinarySerializer.h"

namespace Greis
{
    GreisBinarySerializer::GreisBinarySerializer( ProjectBase::BitConverter::EByteOrder byteOrder ) 
        : _bitConverter(byteOrder)
    {
    }
}