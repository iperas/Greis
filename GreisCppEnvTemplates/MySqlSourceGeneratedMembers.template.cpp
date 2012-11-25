#include "MySqlSource.h"
#include <vector>
#include "ProjectBase\SmartPtr.h"
#include "ProjectBase\Connection.h"
#include "ECustomTypeId.h"
#include "DataChunk.h"
#include "AllStdMessages.h"
#include "AllCustomTypes.h"

using namespace ProjectBase;

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
