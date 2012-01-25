#include "MetaInfo.h"
#include "MetaInfoReader.h"

namespace Domain
{
    MetaInfo::Pointer_t MetaInfo::FromDatabase(Connection* connection)
    {
        return MetaInfoReader(connection).Load();
    }
}
