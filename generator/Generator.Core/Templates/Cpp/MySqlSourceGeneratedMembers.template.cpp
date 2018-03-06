#include <vector>
#include "common/SmartPtr.h"
#include "common/Connection.h"
#include "greis/MySqlSource.h"
#include "greis/ECustomTypeId.h"
#include "greis/DataChunk.h"
#include "greis/AllStdMessages.h"
#include "greis/AllCustomTypes.h"

using namespace Common;

namespace Greis
{
    void MySqlSource::constructCtQueriesAndHandlers()
    {
        GreisMysqlSerializer& serializer = _serializer;
        
        // ${ConstructCtQueriesAndHandlers}
    }

    void MySqlSource::constructMsgQueriesAndHandlers()
    {
        GreisMysqlSerializer& serializer = _serializer;

        // ${ConstructMsgQueriesAndHandlers}
    }
}
