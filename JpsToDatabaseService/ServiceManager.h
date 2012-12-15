#pragma once

#include "ProjectBase\SmartPtr.h"
#include "ProjectBase\Connection.h"
#include "EControlCommand.h"
#include "EServiceLogSeverity.h"
#include "ProjectBase\IniSettings.h"

using namespace ProjectBase;

namespace jpslogd
{
	class ServiceManager
	{
	private:
		Connection::SharedPtr_t _connection;
	public:
		SMART_PTR_T(ServiceManager);

		bool IsRestartRequiredFlag;
		bool IsShutdownRequiredFlag;
		bool IsPausedFlag;

		ServiceManager(Connection::SharedPtr_t connection)
		{
			_connection = connection;
			IsRestartRequiredFlag = false;
			IsShutdownRequiredFlag = false;
			IsPausedFlag = false;
		}

		void HandlePendingCommands()
		{
			auto query = _connection->DbHelper()->ExecuteQuery("SELECT id, command_id, arguments FROM COMMANDQUEUE ORDER BY id;");
			while (query.next())
			{
				int id = query.value(0).toInt();
				int commandId = query.value(1).toInt();
				QString arguments = query.value(2).toString();

				switch (commandId)
				{
				case EControlCommand::SetConfigProperties:
					{
						auto propertyStrings = arguments.split(";");
						foreach (QString propertyString, propertyStrings)
						{
							auto tokens = propertyString.split("=");
							if (tokens.count() < 2)
							{
								addLogMessage("The service has received an invalid command.", EServiceLogSeverity::Warning);
								continue;
							}
							auto name = tokens[0];
							tokens.removeAt(0);
							auto value = tokens.join("=");
							sIniSettings.setValue(name, value);
							addLogMessage(QString("The property %1 was assigned the value '%2'. The restart is required to apply the changes.").arg(name).arg(value), EServiceLogSeverity::Info);
						}
					}
					break;
				case EControlCommand::Restart:
					IsRestartRequiredFlag = true;
					addLogMessage(QString("The service has received the restart command. The receiving loop is being restarted."), EServiceLogSeverity::Info);
					break;
				case EControlCommand::Shutdown:
					IsShutdownRequiredFlag = true;
					addLogMessage(QString("The service has received the shutdown command and is shutting down."), EServiceLogSeverity::Info);
					break;
				case EControlCommand::Pause:
					IsPausedFlag = true;
					addLogMessage(QString("The service has received the pause command and is getting paused."), EServiceLogSeverity::Info);
					break;
				case EControlCommand::Resume:
					IsPausedFlag = false;
					addLogMessage(QString("The service has received the resume command and is getting back active."), EServiceLogSeverity::Info);
					break;
				}

				_connection->DbHelper()->ExecuteQuery(QString("DELETE FROM COMMANDQUEUE WHERE id = %1;").arg(id));
			}
		}

		void addLogMessage(const QString& message, EServiceLogSeverity::Type severity)
		{
			switch (severity)
			{
			case EServiceLogSeverity::Debug:
				sLogger.Debug(message);
				break;
			case EServiceLogSeverity::Info:
				sLogger.Info(message);
				break;
			case EServiceLogSeverity::Warning:
				sLogger.Warn(message);
				break;
			case EServiceLogSeverity::Error:
				sLogger.Error(message);
				break;
			case EServiceLogSeverity::Fatal:
				sLogger.Fatal(message);
				break;
			}

			QSqlQuery query = _connection->DbHelper()->ExecuteQuery("");
			QString insertQuery = "INSERT INTO `servicelog` (`timeStamp`, `message`, `severity_id`) VALUES (?, ?, ?)";
			query.prepare(insertQuery);
			DatabaseHelper::ThrowIfError(query);
			query.addBindValue(QDateTime::currentDateTimeUtc());
			query.addBindValue(message);
			query.addBindValue((int)severity);
			query.exec();
			DatabaseHelper::ThrowIfError(query);
		}
	};
}