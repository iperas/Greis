<DatabaseToJps>

Usage: 'app.exe <output-filename>' [<date-from> [date-to]]
Where:
    <database> - source database name.
    <output-file> - path to output jps file.
    <date-from>, <date-to> - date range should be specified in either 'yyyy-MM-dd HH:mm:ss' or `msecs since epoch` format.
        Date will be set to [NOW - 1 day, NOW] if omitted.
        All dates should be specified in UTC.
        
config.ini content:

[General]
Db.Driver=QMYSQL
Db.DatabaseName=databaseName
Db.Username=username
Db.Password=password
Db.Hostname=127.0.0.1
Db.Port=3306
WrapIntoTransaction=true
inserterBatchSize=25000

config explanation:

Db.* - connection settings
WrapIntoTransaction - if you want to wrap you JPS-file import with transaction
inserterBatchSize - how often application should perform insert-operations while importing JPS-file