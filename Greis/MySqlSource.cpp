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

        constructCtQueriesAndHandlers();
    }

    MySqlSource::~MySqlSource()
    {
        for (auto it = _ctBuffer.begin(); it != _ctBuffer.end(); ++it)
        {
            for (auto jt = it->begin(); jt != it->end(); ++jt)
            {
                delete jt.value();
            }
        }
    }

    void MySqlSource::fillStandardJpsHeader( JpsFile* jpsFile )
    {
        auto fileId = make_unique<FileIdStdMessage>(
            "JP055RLOGF JPS ALPHA Receiver Log File                                                    ", 90);
        auto msgFmt = make_unique<MsgFmtStdMessage>("MF009JP010109F", 9);
        jpsFile->Head().push_back(std::move(fileId));
        jpsFile->Head().push_back(NonStdTextMessage::CreateCarriageReturnMessage());
        jpsFile->Head().push_back(NonStdTextMessage::CreateNewLineMessage());
        jpsFile->Head().push_back(std::move(msgFmt));
        jpsFile->Head().push_back(NonStdTextMessage::CreateCarriageReturnMessage());
        jpsFile->Head().push_back(NonStdTextMessage::CreateNewLineMessage());
    }
}
