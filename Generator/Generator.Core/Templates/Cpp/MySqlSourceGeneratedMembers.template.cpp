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
    
    DataChunk::UniquePtr_t MySqlSource::ReadRange( const QDateTime& from, const QDateTime& to )
    {
        _ctBuffer.clear();

        _from = from;
        _to = to;

        auto jpsFile = make_unique<DataChunk>();
        pushStandardJpsHeader(jpsFile.get());
        
        QMap<qulonglong, Epoch*> epochsByDateTime;

        GreisMysqlSerializer& serializer = _serializer;

        readRawStdMessages();
        
        // ${HandleMessageStub}

        insertRawMessage(epochsByDateTime);

        for (auto it = epochsByDateTime.begin(); it != epochsByDateTime.end(); ++it)
        {
            jpsFile->Body().push_back(Epoch::UniquePtr_t(it.value()));
        }
        return jpsFile;
    }
}
