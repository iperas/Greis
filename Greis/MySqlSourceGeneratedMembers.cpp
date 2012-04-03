#include "MySqlSource.h"
#include <vector>
#include "ProjectBase\SmartPtr.h"
#include "ProjectBase\Connection.h"
#include "ECustomTypeId.h"
#include "JpsFile.h"
#include "AllStdMessages.h"

using namespace ProjectBase;

namespace Greis
{
    JpsFile::UniquePtr_t MySqlSource::ReadRange( const QDateTime& from, const QDateTime& to )
    {
        _ctBuffer.clear();

        _from = from;
        _to = to;

        auto jpsFile = make_unique<JpsFile>();
        QMap<qulonglong, Epoch*> epochsByDateTime;

        // ${HandleMessageStub}
        handleMessage(QString("SELECT \
                              `id`, `idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, \
                              `sv`, `frqNum`, `cs` \
                              FROM `msg_gloephemeris` \
                              WHERE `unixTimeEpoch` BETWEEN %3 AND %4").
                              arg(_from.toMSecsSinceEpoch()).
                              arg(to.toMSecsSinceEpoch()), [] (const QSqlQuery& q, Message* msg) {},
                              epochsByDateTime);

        for (auto it = epochsByDateTime.begin(); it != epochsByDateTime.end(); ++it)
        {
            jpsFile->Body().push_back(Epoch::UniquePtr_t(it.value()));
        }
        return jpsFile;
    }
}
