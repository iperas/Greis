#include "Log.h"

#include <QtGui/QMessageBox>
#include <QtCore/QTextStream>
#include <QtCore/QTextCodec>
#include <QtCore/QDebug>
#include <QtCore/QDateTime>
#include <iostream>
#include <string>

using namespace std;

namespace Common
{
    Log::Log()
    {
#ifdef WIN32
        _codec = QTextCodec::codecForName("IBM 866");
#else
        // TODO: какой кодек в линух-консоле?
        _codec = QTextCodec::codecForName("UTF-8");
#endif
    }

    Log::~Log()
    {
    }

    void Log::addError( const QString& message, const QString& details )
    {
        addToConsole(message, details);
        //QMessageBox::critical(0, shortMessage, message);
    }
    void Log::addWarning( const QString& message, const QString& details )
    {
        addToConsole(message, details);
        //QMessageBox::warning(0, QString::fromUtf8("Внимание!"), message);
    }

    void Log::addInfo( const QString& message, const QString& details )
    {
        addToConsole(message, details);
    }

    void Log::addError( const string& message, const string& details )
    {
        addError(asciiToQString(message), asciiToQString(details));
    }
    void Log::addWarning( const string& message, const string& details )
    {
        addWarning(asciiToQString(message), asciiToQString(details));
    }

    void Log::addInfo( const string& message, const string& details )
    {
        addInfo(asciiToQString(message), asciiToQString(details));
    }

    void Log::Initialize( bool displayMessages, const QString logFile )
    {
        _displayMessages = displayMessages;
        _logFile = logFile;
    }

    void Log::addToConsole( const QString& message, const QString& details )
    {
        QDateTime currentTime = QDateTime::currentDateTime();
        //QString prefix = currentTime.toString("dd.MM.yyyy hh:mm:ss: ");
        QString prefix = currentTime.toString("hh:mm:ss: ");
        QByteArray encodedPrefix = _codec->fromUnicode(prefix);
        QByteArray encodedMessage = _codec->fromUnicode(message);
        cout << (const char*)encodedPrefix << (const char*)encodedMessage << endl;
        if (!details.isEmpty())
        {
            QByteArray encodedDetails = _codec->fromUnicode(QString("Details: ") + details);
            cout << (const char*)encodedDetails << endl;
        }
    }

    QString Log::asciiToQString( const string& str )
    {
        return QString::fromAscii(str.c_str(), str.size());
    }
}
