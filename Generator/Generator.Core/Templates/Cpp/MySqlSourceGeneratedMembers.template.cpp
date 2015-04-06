#include <vector>
#include "Common/SmartPtr.h"
#include "Common/Connection.h"
#include "Greis/MySqlSource.h"
#include "Greis/ECustomTypeId.h"
#include "Greis/DataChunk.h"
#include "Greis/AllStdMessages.h"
#include "Greis/AllCustomTypes.h"

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
