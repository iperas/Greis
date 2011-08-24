#include "Settings.h"
#include "../Log/Log.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QMap>
#include <QTextCodec>

namespace Common
{
    Settings::Settings()
    {
        _pSettings = 0;
    }

    Settings::~Settings()
    {
        if (_pSettings)
            delete _pSettings;
    }

    bool Settings::Initialize(const QString& settingsFile)
    {
        _settingsFile = settingsFile;
        _pSettings = new QSettings(_settingsFile, QSettings::IniFormat);
        _initialized = true;
        return true;
    }

    void Settings::setValue( const QString& key, const QVariant& value )
    {
        _pSettings->setValue(key, value);
    }

    QVariant Settings::value( const QString & key, const QVariant & defaultValue /*= QVariant()*/ ) const
    {
        return _pSettings->value(key, defaultValue);
    }
}
