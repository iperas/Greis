#include "MySqlSource.h"
#include <vector>
#include "ProjectBase\SmartPtr.h"
#include "ProjectBase\Connection.h"
#include "ECustomTypeId.h"
#include "JpsFile.h"
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
    
    JpsFile::UniquePtr_t MySqlSource::ReadRange( const QDateTime& from, const QDateTime& to )
    {
        _ctBuffer.clear();

        _from = from;
        _to = to;

        auto jpsFile = make_unique<JpsFile>();
        fillStandardJpsHeader(jpsFile.get());
        
        QMap<qulonglong, Epoch*> epochsByDateTime;

        GreisMysqlSerializer& serializer = _serializer;
        
        // ${HandleMessageStub}

        for (auto it = epochsByDateTime.begin(); it != epochsByDateTime.end(); ++it)
        {
            jpsFile->Body().push_back(Epoch::UniquePtr_t(it.value()));
        }
        return jpsFile;
    }
}
