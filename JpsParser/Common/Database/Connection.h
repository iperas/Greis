#ifndef Connection_h__
#define Connection_h__

#include <QtCore/QtCore>
#include <QtSql/QtSql>
#include <boost/shared_ptr.hpp>
#include "Common/Exceptions/DatabaseException.h"
#include "DatabaseHelper.h"
#include "Common/Settings/Settings.h"
#include "Common/Log/Log.h"

class Connection
{
private:
	QSqlDatabase _db;
	QString _settingsPrefix;
	int _maxAllowedPacket;
	boost::shared_ptr<DatabaseHelper> _dbHelper;
public:
	QString Driver;
	QString DatabaseName;
	QString Username;
	QString Password;
	QString Hostname;
	int Port;

	void Connect()
	{
		if (_db.isOpen())
			return;

		QString escapedHostname = Hostname;
		escapedHostname.replace('.', '_');
		QString connectionName = QString("%1_%2_%3_%4").arg(Username).
			arg(escapedHostname).arg(Port).arg(DatabaseName);
		_db = QSqlDatabase::addDatabase(Driver, connectionName);
		_db.setDatabaseName(DatabaseName);
		_db.setPort(Port);
		_db.setHostName(Hostname);
		_db.setUserName(Username);
		_db.setPassword(Password);
		_db.setConnectOptions(QString("CLIENT_COMPRESS=1"));
		if (!_db.open())
		{
			throw DatabaseException(_db.lastError().text());
		}

		// ѕолучение максимального размера пакета
		_dbHelper = boost::shared_ptr<DatabaseHelper>(new DatabaseHelper(_db));
		_maxAllowedPacket = _dbHelper->ExecuteSingleRowQuery(
			"SHOW VARIABLES LIKE 'max_allowed_packet'").value(1).toInt();
	}

	inline QSqlDatabase& Database() { return _db; }
	inline DatabaseHelper* DbHelper() { return _dbHelper.get(); }
	inline int MaxAllowedPacket() const { return _maxAllowedPacket; }

	static Connection FromSettings(const QString& settingsPrefix)
	{
		Connection ci;
		ci._settingsPrefix = settingsPrefix;
		ci.Driver = sSettings.value(settingsPrefix + ".Driver", "").toString();
		ci.DatabaseName = sSettings.value(settingsPrefix + ".DatabaseName", "").toString();
		ci.Username = sSettings.value(settingsPrefix + ".Username", "").toString();
		ci.Password = sSettings.value(settingsPrefix + ".Password", "").toString();
		ci.Hostname = sSettings.value(settingsPrefix + ".Hostname", "").toString();
		ci.Port = sSettings.value(settingsPrefix + ".Port", 0).toInt();
		return ci;
	}

	void ToSettings()
	{
		sSettings.setValue(_settingsPrefix + ".Driver", Driver);
		sSettings.setValue(_settingsPrefix + ".DatabaseName", DatabaseName);
		sSettings.setValue(_settingsPrefix + ".Username", Username);
		sSettings.setValue(_settingsPrefix + ".Password", Password);
		sSettings.setValue(_settingsPrefix + ".Hostname", Hostname);
		sSettings.setValue(_settingsPrefix + ".Port", Port);
	}
};

#endif // Connection_h__