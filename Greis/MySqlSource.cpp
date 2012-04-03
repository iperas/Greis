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
    MySqlSource::MySqlSource( Connection* connection )
    {
        _connection = connection;
        _dbHelper = _connection->DbHelper();

        auto query = _dbHelper->ExecuteQuery("SELECT id, code FROM messageCode");
        while (query.next())
        {
            auto id = query.value(0).toInt();
            auto code = query.value(1).toString();
            std::string codeStr(code.toAscii(), code.size());
            _codes[id] = codeStr;
        }
    }

    MySqlSource::~MySqlSource()
    {
    }

    /*CustomType::UniquePtr_t MySqlSource::extractCustomType( ECustomTypeId::Type ctId, int dbId )
    {
        return CustomType::UniquePtr_t();
    }*/
}
